/*
 * var_t.h
 *
 *  Created on: Apr 21, 2022
 *      Author: mad
 */

#ifndef INCLUDE_MMX_VM_VAR_T_H_
#define INCLUDE_MMX_VM_VAR_T_H_

#include <uint256_t.h>

#include <cstdint>
#include <cstdlib>
#include <cstring>


namespace mmx {
namespace vm {

constexpr uint64_t SEG_SIZE = 0x4000000;
constexpr uint64_t STACK_SIZE = 16 * SEG_SIZE;

constexpr uint64_t MEM_CONST = SEG_SIZE;
constexpr uint64_t MEM_EXTERN = MEM_CONST + SEG_SIZE;
constexpr uint64_t MEM_STACK = MEM_EXTERN + SEG_SIZE;
constexpr uint64_t MEM_STATIC = MEM_STACK + STACK_SIZE;
constexpr uint64_t MEM_HEAP = uint64_t(1) << 32;

constexpr uint64_t STATIC_SIZE = MEM_HEAP - MEM_STATIC;


enum class vartype_e : uint8_t {

	NIL,
	TRUE,
	FALSE,
	REF,
	UINT,
	STRING,
	BINARY,
	ARRAY,
	MAP,

};

enum varflags_e : uint8_t {

	DIRTY = (1 << 0),
	CONST = (1 << 1),
	STORED = (1 << 2),
	DELETED = (1 << 3),
	KEY = (1 << 4),

};

struct var_t {

	uint32_t ref_count = 0;

	varflags_e flags = 0;

	vartype_e type = vartype_e::NIL;

	var_t() = default;
	var_t(const vartype_e& type) : type(type) {}
	var_t(const vartype_e& type, const varflags_e& flags) : type(type), flags(flags) {}

	void addref() {
		if(ref_count == std::numeric_limits<typeof(ref_count)>::max()) {
			throw std::runtime_error("ref_count overflow");
		}
		ref_count++;
		flags |= varflags_e::DIRTY;
	}
	bool unref() {
		if(!ref_count) {
			throw std::logic_error("unref underflow");
		}
		ref_count--;
		flags |= varflags_e::DIRTY;
		return ref_count == 0;
	}
	var_t* pin() {
		if(!ref_count) {
			ref_count = 1;
		}
		return this;
	}

};

struct ref_t : var_t {

	uint64_t address = 0;

	ref_t() : var_t(vartype_e::REF) {}
	ref_t(const ref_t&) = default;
	ref_t(uint64_t address) : ref_t(), address(address) {}

};

struct uint_t : var_t {

	uint256_t value = uint256_0;

	uint_t() : var_t(vartype_e::UINT) {}
	uint_t(const uint_t&) = default;
	uint_t(const uint256_t& value) : uint_t() { this->value = value; }

};

struct binary_t : var_t {

	size_t size = 0;
	size_t capacity = 0;

	void* data(const size_t offset = 0) {
		return ((char*)this) + sizeof(binary_t) + offset;
	}
	const void* data(const size_t offset = 0) const {
		return ((const char*)this) + sizeof(binary_t) + offset;
	}

	static binary_t* alloc(const binary_t& src) {
		return alloc(src, src.type);
	}
	static binary_t* alloc(const binary_t& src, const vartype_e type) {
		auto bin = unsafe_alloc(src.size, type);
		bin->size = src.size;
		::memcpy(bin->data(), src.data(), bin->size);
		::memset(bin->data(bin->size), 0, bin->capacity - bin->size);
		return bin;
	}
	static binary_t* alloc(const std::string& src, const vartype_e type = vartype_e::STRING) {
		auto bin = unsafe_alloc(src.size(), type);
		bin->size = src.size();
		::memcpy(bin->data(), src.c_str(), bin->size);
		::memset(bin->data(bin->size), 0, bin->capacity - bin->size);
		return bin;
	}
	static binary_t* alloc(const void* data, const size_t len, const vartype_e type = vartype_e::BINARY) {
		auto bin = unsafe_alloc(len, type);
		bin->size = len;
		::memcpy(bin->data(), data, bin->size);
		::memset(bin->data(bin->size), 0, bin->capacity - bin->size);
		return bin;
	}
	static binary_t* alloc(size_t size, const vartype_e type) {
		auto bin = unsafe_alloc(size, type);
		::memset(bin->data(), 0, bin->capacity);
		return bin;
	}
	static binary_t* unsafe_alloc(size_t size, const vartype_e type) {
		switch(type) {
			case vartype_e::BINARY: break;
			case vartype_e::STRING: size += 1; break;
			default: throw std::logic_error("invalid binary type");
		}
		auto bin = new(::operator new(sizeof(binary_t) + size)) binary_t(type);
		bin->capacity = size;
		return bin;
	}

private:
	binary_t(const vartype_e& type) : var_t(type) {}

};

struct array_t : var_t {

	uint64_t address = 0;
	uint32_t size = 0;

	array_t() : var_t(vartype_e::ARRAY) {}
	array_t(const array_t&) = default;
	array_t(uint32_t size) : array_t(), size(size) {}

};

struct map_t : var_t {

	uint64_t address = 0;

	map_t() : var_t(vartype_e::MAP) {}
	map_t(const map_t&) = default;

};

struct varptr_t {

	var_t* ptr = nullptr;

	varptr_t() = default;
	varptr_t(var_t* var) {
		ptr = var;
		if(ptr) {
			ptr->addref();
		}
	}
	varptr_t(const varptr_t& other) : varptr_t(other.ptr) {}

	~varptr_t() {
		if(ptr) {
			if(ptr->unref()) {
				delete ptr;
			}
			ptr = nullptr;
		}
	}
	varptr_t& operator=(const varptr_t& other) {
		if(ptr) {
			ptr->unref();
		}
		ptr = other.ptr;
		if(ptr) {
			ptr->addref();
		}
		return *this;
	}
	var_t* get() const {
		return ptr;
	}

};


var_t* clone(const var_t& src);

var_t* clone(const var_t* var);

int compare(const var_t& lhs, const var_t& rhs);

struct varptr_less_t {
	bool operator()(const var_t*& L, const var_t*& R) const {
		if(!L) { return R; }
		if(!R) { return false; }
		return compare(*L, *R) < 0;
	}
};

inline bool operator<(const var_t& L, const var_t& R) const {
	return compare(L, R) < 0;
}
inline bool operator>(const var_t& L, const var_t& R) const {
	return compare(L, R) > 0;
}
inline bool operator==(const var_t& L, const var_t& R) const {
	return compare(L, R) == 0;
}
inline bool operator!=(const var_t& L, const var_t& R) const {
	return compare(L, R) != 0;
}
inline bool operator<(const varptr_t& L, const varptr_t& R) const {
	return varptr_less_t{}(L.ptr, R.ptr);
}

inline size_t num_bytes(const var_t& var)
{
	switch(var.type) {
		case vartype_e::REF:
			return 8;
		case vartype_e::UINT:
			return 32;
		case vartype_e::STRING:
		case vartype_e::BINARY:
			return ((const binary_t&)var).size;
		case vartype_e::ARRAY:
			return 8 + 4;
		case vartype_e::MAP:
			return 8;
	}
	return 0;
}

inline size_t num_bytes(const var_t* var)
{
	if(!var) {
		return 0;
	}
	return num_bytes(*var);
}




} // vm
} // mmx

#endif /* INCLUDE_MMX_VM_VAR_T_H_ */
