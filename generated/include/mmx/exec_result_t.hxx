
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_exec_result_t_HXX_
#define INCLUDE_mmx_exec_result_t_HXX_

#include <vnx/Type.h>
#include <mmx/package.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/exec_error_t.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/txin_t.hxx>
#include <mmx/txout_t.hxx>


namespace mmx {

struct MMX_EXPORT exec_result_t : vnx::struct_t {
	
	
	vnx::bool_t did_fail = 0;
	uint32_t total_cost = 0;
	uint32_t total_fee = 0;
	std::vector<::mmx::txin_t> inputs;
	std::vector<::mmx::txout_t> outputs;
	vnx::optional<::mmx::exec_error_t> error;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x18fe02e2374b039eull;
	
	exec_result_t() {}
	
	vnx::Hash64 get_type_hash() const;
	std::string get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	vnx::bool_t is_valid() const;
	::mmx::hash_t calc_hash() const;
	uint64_t calc_cost(std::shared_ptr<const ::mmx::ChainParams> params = nullptr) const;
	std::string get_error_msg() const;
	
	static std::shared_ptr<exec_result_t> create();
	std::shared_ptr<exec_result_t> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	vnx::Variant get_field(const std::string& name) const;
	void set_field(const std::string& name, const vnx::Variant& value);
	
	friend std::ostream& operator<<(std::ostream& _out, const exec_result_t& _value);
	friend std::istream& operator>>(std::istream& _in, exec_result_t& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void exec_result_t::accept_generic(T& _visitor) const {
	_visitor.template type_begin<exec_result_t>(6);
	_visitor.type_field("did_fail", 0); _visitor.accept(did_fail);
	_visitor.type_field("total_cost", 1); _visitor.accept(total_cost);
	_visitor.type_field("total_fee", 2); _visitor.accept(total_fee);
	_visitor.type_field("inputs", 3); _visitor.accept(inputs);
	_visitor.type_field("outputs", 4); _visitor.accept(outputs);
	_visitor.type_field("error", 5); _visitor.accept(error);
	_visitor.template type_end<exec_result_t>(6);
}


} // namespace mmx


namespace vnx {

template<>
struct is_equivalent<::mmx::exec_result_t> {
	bool operator()(const uint16_t* code, const TypeCode* type_code);
};

} // vnx

#endif // INCLUDE_mmx_exec_result_t_HXX_
