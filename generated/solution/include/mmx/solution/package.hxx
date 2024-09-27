
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_solution_PACKAGE_HXX_
#define INCLUDE_mmx_solution_PACKAGE_HXX_

#include <vnx/Type.h>

#include <mmx/package.hxx>
#include <vnx/package.hxx>

#ifdef MMX_SOLUTION_EXPORT_ENABLE
#include <mmx_solution_export.h>
#else
#ifndef MMX_SOLUTION_EXPORT
#define MMX_SOLUTION_EXPORT
#endif
#endif


namespace mmx {
namespace solution {

void register_all_types();


class MultiSig;
class PubKey;

MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_MultiSig; ///< \private
MMX_SOLUTION_EXPORT extern const vnx::TypeCode* const vnx_native_type_code_PubKey; ///< \private

} // namespace mmx
} // namespace solution


namespace vnx {

void read(TypeInput& in, ::mmx::solution::MultiSig& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void read(TypeInput& in, ::mmx::solution::PubKey& value, const TypeCode* type_code, const uint16_t* code); ///< \private

void write(TypeOutput& out, const ::mmx::solution::MultiSig& value, const TypeCode* type_code, const uint16_t* code); ///< \private
void write(TypeOutput& out, const ::mmx::solution::PubKey& value, const TypeCode* type_code, const uint16_t* code); ///< \private

void read(std::istream& in, ::mmx::solution::MultiSig& value); ///< \private
void read(std::istream& in, ::mmx::solution::PubKey& value); ///< \private

void write(std::ostream& out, const ::mmx::solution::MultiSig& value); ///< \private
void write(std::ostream& out, const ::mmx::solution::PubKey& value); ///< \private

void accept(Visitor& visitor, const ::mmx::solution::MultiSig& value); ///< \private
void accept(Visitor& visitor, const ::mmx::solution::PubKey& value); ///< \private

template<typename V>
void accept_generic(V& visitor, std::shared_ptr<const ::mmx::solution::MultiSig> value); ///< \private
template<typename V>
void accept_generic(V& visitor, std::shared_ptr<const ::mmx::solution::PubKey> value); ///< \private

/// \private
template<>
struct type<::mmx::solution::MultiSig> {
	void read(TypeInput& in, ::mmx::solution::MultiSig& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::MultiSig& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::MultiSig& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::MultiSig& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::MultiSig& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::MultiSig& value, bool special = false);
};

/// \private
template<>
struct type<::mmx::solution::PubKey> {
	void read(TypeInput& in, ::mmx::solution::PubKey& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::read(in, value, type_code, code);
	}
	void write(TypeOutput& out, const ::mmx::solution::PubKey& value, const TypeCode* type_code, const uint16_t* code) {
		vnx::write(out, value, type_code, code);
	}
	void read(std::istream& in, ::mmx::solution::PubKey& value) {
		vnx::read(in, value);
	}
	void write(std::ostream& out, const ::mmx::solution::PubKey& value) {
		vnx::write(out, value);
	}
	void accept(Visitor& visitor, const ::mmx::solution::PubKey& value) {
		vnx::accept(visitor, value);
	}
	const TypeCode* get_type_code();
	void create_dynamic_code(std::vector<uint16_t>& code);
	void create_dynamic_code(std::vector<uint16_t>& code, const ::mmx::solution::PubKey& value, bool special = false);
};


} // namespace vnx

#endif // INCLUDE_mmx_solution_PACKAGE_HXX_
