
// AUTO GENERATED by vnxcppcodegen

#include <mmx/contract/package.hxx>
#include <mmx/contract/Offer.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/Contract.hxx>
#include <mmx/Contract_calc_cost.hxx>
#include <mmx/Contract_calc_cost_return.hxx>
#include <mmx/Contract_calc_hash.hxx>
#include <mmx/Contract_calc_hash_return.hxx>
#include <mmx/Contract_get_dependency.hxx>
#include <mmx/Contract_get_dependency_return.hxx>
#include <mmx/Contract_get_owner.hxx>
#include <mmx/Contract_get_owner_return.hxx>
#include <mmx/Contract_is_locked.hxx>
#include <mmx/Contract_is_locked_return.hxx>
#include <mmx/Contract_is_valid.hxx>
#include <mmx/Contract_is_valid_return.hxx>
#include <mmx/Contract_transfer.hxx>
#include <mmx/Contract_transfer_return.hxx>
#include <mmx/Contract_validate.hxx>
#include <mmx/Contract_validate_return.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/contract/Offer_calc_cost.hxx>
#include <mmx/contract/Offer_calc_cost_return.hxx>
#include <mmx/contract/Offer_calc_hash.hxx>
#include <mmx/contract/Offer_calc_hash_return.hxx>
#include <mmx/contract/Offer_is_valid.hxx>
#include <mmx/contract/Offer_is_valid_return.hxx>
#include <mmx/hash_t.hpp>

#include <vnx/vnx.h>


namespace mmx {
namespace contract {


const vnx::Hash64 Offer::VNX_TYPE_HASH(0x992a8ef435f8b3cbull);
const vnx::Hash64 Offer::VNX_CODE_HASH(0xac2ccd9cfc451a4full);

vnx::Hash64 Offer::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Offer::get_type_name() const {
	return "mmx.contract.Offer";
}

const vnx::TypeCode* Offer::get_type_code() const {
	return mmx::contract::vnx_native_type_code_Offer;
}

std::shared_ptr<Offer> Offer::create() {
	return std::make_shared<Offer>();
}

std::shared_ptr<vnx::Value> Offer::clone() const {
	return std::make_shared<Offer>(*this);
}

void Offer::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Offer::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Offer::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::contract::vnx_native_type_code_Offer;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, version);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, base);
	_visitor.type_end(*_type_code);
}

void Offer::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.contract.Offer\"";
	_out << ", \"version\": "; vnx::write(_out, version);
	_out << ", \"base\": "; vnx::write(_out, base);
	_out << "}";
}

void Offer::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Offer::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.contract.Offer";
	_object["version"] = version;
	_object["base"] = base;
	return _object;
}

void Offer::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "base") {
			_entry.second.to(base);
		} else if(_entry.first == "version") {
			_entry.second.to(version);
		}
	}
}

vnx::Variant Offer::get_field(const std::string& _name) const {
	if(_name == "version") {
		return vnx::Variant(version);
	}
	if(_name == "base") {
		return vnx::Variant(base);
	}
	return vnx::Variant();
}

void Offer::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "version") {
		_value.to(version);
	} else if(_name == "base") {
		_value.to(base);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Offer& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Offer& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Offer::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Offer::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.contract.Offer";
	type_code->type_hash = vnx::Hash64(0x992a8ef435f8b3cbull);
	type_code->code_hash = vnx::Hash64(0xac2ccd9cfc451a4full);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::contract::Offer);
	type_code->parents.resize(1);
	type_code->parents[0] = ::mmx::Contract::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Offer>(); };
	type_code->methods.resize(11);
	type_code->methods[0] = ::mmx::Contract_calc_cost::static_get_type_code();
	type_code->methods[1] = ::mmx::Contract_calc_hash::static_get_type_code();
	type_code->methods[2] = ::mmx::Contract_get_dependency::static_get_type_code();
	type_code->methods[3] = ::mmx::Contract_get_owner::static_get_type_code();
	type_code->methods[4] = ::mmx::Contract_is_locked::static_get_type_code();
	type_code->methods[5] = ::mmx::Contract_is_valid::static_get_type_code();
	type_code->methods[6] = ::mmx::Contract_transfer::static_get_type_code();
	type_code->methods[7] = ::mmx::Contract_validate::static_get_type_code();
	type_code->methods[8] = ::mmx::contract::Offer_calc_cost::static_get_type_code();
	type_code->methods[9] = ::mmx::contract::Offer_calc_hash::static_get_type_code();
	type_code->methods[10] = ::mmx::contract::Offer_is_valid::static_get_type_code();
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "version";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "base";
		field.code = {16};
	}
	type_code->build();
	return type_code;
}

std::shared_ptr<vnx::Value> Offer::vnx_call_switch(std::shared_ptr<const vnx::Value> _method) {
	switch(_method->get_type_hash()) {
		case 0xb23d047adf8b2612ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_calc_cost>(_method);
			auto _return_value = ::mmx::Contract_calc_cost_return::create();
			_return_value->_ret_0 = calc_cost(_args->params);
			return _return_value;
		}
		case 0x622fcf1cba1952edull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_calc_hash>(_method);
			auto _return_value = ::mmx::Contract_calc_hash_return::create();
			_return_value->_ret_0 = calc_hash();
			return _return_value;
		}
		case 0x989dd3da956ebbd0ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_get_dependency>(_method);
			auto _return_value = ::mmx::Contract_get_dependency_return::create();
			_return_value->_ret_0 = get_dependency();
			return _return_value;
		}
		case 0x8fe2c64fdc8f0680ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_get_owner>(_method);
			auto _return_value = ::mmx::Contract_get_owner_return::create();
			_return_value->_ret_0 = get_owner();
			return _return_value;
		}
		case 0x9b7981d03b3aeab6ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_is_locked>(_method);
			auto _return_value = ::mmx::Contract_is_locked_return::create();
			_return_value->_ret_0 = is_locked(_args->context);
			return _return_value;
		}
		case 0xe3adf9b29a723217ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_is_valid>(_method);
			auto _return_value = ::mmx::Contract_is_valid_return::create();
			_return_value->_ret_0 = is_valid();
			return _return_value;
		}
		case 0xd41bec275faff1ffull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_transfer>(_method);
			auto _return_value = ::mmx::Contract_transfer_return::create();
			transfer(_args->new_owner);
			return _return_value;
		}
		case 0xc2126a44901c8d52ull: {
			auto _args = std::static_pointer_cast<const ::mmx::Contract_validate>(_method);
			auto _return_value = ::mmx::Contract_validate_return::create();
			_return_value->_ret_0 = validate(_args->operation, _args->context);
			return _return_value;
		}
		case 0x698897fbc2fd8486ull: {
			auto _args = std::static_pointer_cast<const ::mmx::contract::Offer_calc_cost>(_method);
			auto _return_value = ::mmx::contract::Offer_calc_cost_return::create();
			_return_value->_ret_0 = calc_cost(_args->params);
			return _return_value;
		}
		case 0xb99a5c9da76ff079ull: {
			auto _args = std::static_pointer_cast<const ::mmx::contract::Offer_calc_hash>(_method);
			auto _return_value = ::mmx::contract::Offer_calc_hash_return::create();
			_return_value->_ret_0 = calc_hash();
			return _return_value;
		}
		case 0x589c751af0789c7eull: {
			auto _args = std::static_pointer_cast<const ::mmx::contract::Offer_is_valid>(_method);
			auto _return_value = ::mmx::contract::Offer_is_valid_return::create();
			_return_value->_ret_0 = is_valid();
			return _return_value;
		}
	}
	return nullptr;
}


} // namespace mmx
} // namespace contract


namespace vnx {

void read(TypeInput& in, ::mmx::contract::Offer& value, const TypeCode* type_code, const uint16_t* code) {
	if(code) {
		switch(code[0]) {
			case CODE_OBJECT:
			case CODE_ALT_OBJECT: {
				Object tmp;
				vnx::read(in, tmp, type_code, code);
				value.from_object(tmp);
				return;
			}
			case CODE_DYNAMIC:
			case CODE_ALT_DYNAMIC:
				vnx::read_dynamic(in, value);
				return;
		}
	}
	if(!type_code) {
		vnx::skip(in, type_code, code);
		return;
	}
	if(code) {
		switch(code[0]) {
			case CODE_STRUCT: type_code = type_code->depends[code[1]]; break;
			case CODE_ALT_STRUCT: type_code = type_code->depends[vnx::flip_bytes(code[1])]; break;
			default: {
				vnx::skip(in, type_code, code);
				return;
			}
		}
	}
	const char* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[0]) {
			vnx::read_value(_buf + _field->offset, value.version, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.base, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::contract::Offer& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::contract::vnx_native_type_code_Offer;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::contract::Offer>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.version);
	vnx::write(out, value.base, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::contract::Offer& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::contract::Offer& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::contract::Offer& value) {
	value.accept(visitor);
}

} // vnx
