
// AUTO GENERATED by vnxcppcodegen

#include <mmx/contract/package.hxx>
#include <mmx/contract/TokenBase.hxx>
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
#include <mmx/Contract_is_valid.hxx>
#include <mmx/Contract_is_valid_return.hxx>
#include <mmx/Contract_transfer.hxx>
#include <mmx/Contract_transfer_return.hxx>
#include <mmx/Contract_validate.hxx>
#include <mmx/Contract_validate_return.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/contract/TokenBase_calc_cost.hxx>
#include <mmx/contract/TokenBase_calc_cost_return.hxx>
#include <mmx/contract/TokenBase_calc_hash.hxx>
#include <mmx/contract/TokenBase_calc_hash_return.hxx>
#include <mmx/contract/TokenBase_is_valid.hxx>
#include <mmx/contract/TokenBase_is_valid_return.hxx>
#include <mmx/hash_t.hpp>

#include <vnx/vnx.h>


namespace mmx {
namespace contract {


const vnx::Hash64 TokenBase::VNX_TYPE_HASH(0x5aeed4c96d232b5eull);
const vnx::Hash64 TokenBase::VNX_CODE_HASH(0x537f48cf8f591dc6ull);

vnx::Hash64 TokenBase::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string TokenBase::get_type_name() const {
	return "mmx.contract.TokenBase";
}

const vnx::TypeCode* TokenBase::get_type_code() const {
	return mmx::contract::vnx_native_type_code_TokenBase;
}

std::shared_ptr<TokenBase> TokenBase::create() {
	return std::make_shared<TokenBase>();
}

std::shared_ptr<vnx::Value> TokenBase::clone() const {
	return std::make_shared<TokenBase>(*this);
}

void TokenBase::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void TokenBase::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void TokenBase::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::contract::vnx_native_type_code_TokenBase;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, version);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, name);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, symbol);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, web_url);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, icon_url);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, decimals);
	_visitor.type_end(*_type_code);
}

void TokenBase::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.contract.TokenBase\"";
	_out << ", \"version\": "; vnx::write(_out, version);
	_out << ", \"name\": "; vnx::write(_out, name);
	_out << ", \"symbol\": "; vnx::write(_out, symbol);
	_out << ", \"web_url\": "; vnx::write(_out, web_url);
	_out << ", \"icon_url\": "; vnx::write(_out, icon_url);
	_out << ", \"decimals\": "; vnx::write(_out, decimals);
	_out << "}";
}

void TokenBase::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object TokenBase::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.contract.TokenBase";
	_object["version"] = version;
	_object["name"] = name;
	_object["symbol"] = symbol;
	_object["web_url"] = web_url;
	_object["icon_url"] = icon_url;
	_object["decimals"] = decimals;
	return _object;
}

void TokenBase::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "decimals") {
			_entry.second.to(decimals);
		} else if(_entry.first == "icon_url") {
			_entry.second.to(icon_url);
		} else if(_entry.first == "name") {
			_entry.second.to(name);
		} else if(_entry.first == "symbol") {
			_entry.second.to(symbol);
		} else if(_entry.first == "version") {
			_entry.second.to(version);
		} else if(_entry.first == "web_url") {
			_entry.second.to(web_url);
		}
	}
}

vnx::Variant TokenBase::get_field(const std::string& _name) const {
	if(_name == "version") {
		return vnx::Variant(version);
	}
	if(_name == "name") {
		return vnx::Variant(name);
	}
	if(_name == "symbol") {
		return vnx::Variant(symbol);
	}
	if(_name == "web_url") {
		return vnx::Variant(web_url);
	}
	if(_name == "icon_url") {
		return vnx::Variant(icon_url);
	}
	if(_name == "decimals") {
		return vnx::Variant(decimals);
	}
	return vnx::Variant();
}

void TokenBase::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "version") {
		_value.to(version);
	} else if(_name == "name") {
		_value.to(name);
	} else if(_name == "symbol") {
		_value.to(symbol);
	} else if(_name == "web_url") {
		_value.to(web_url);
	} else if(_name == "icon_url") {
		_value.to(icon_url);
	} else if(_name == "decimals") {
		_value.to(decimals);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const TokenBase& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, TokenBase& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* TokenBase::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> TokenBase::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.contract.TokenBase";
	type_code->type_hash = vnx::Hash64(0x5aeed4c96d232b5eull);
	type_code->code_hash = vnx::Hash64(0x537f48cf8f591dc6ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::contract::TokenBase);
	type_code->parents.resize(1);
	type_code->parents[0] = ::mmx::Contract::static_get_type_code();
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<TokenBase>(); };
	type_code->methods.resize(10);
	type_code->methods[0] = ::mmx::Contract_calc_cost::static_get_type_code();
	type_code->methods[1] = ::mmx::Contract_calc_hash::static_get_type_code();
	type_code->methods[2] = ::mmx::Contract_get_dependency::static_get_type_code();
	type_code->methods[3] = ::mmx::Contract_get_owner::static_get_type_code();
	type_code->methods[4] = ::mmx::Contract_is_valid::static_get_type_code();
	type_code->methods[5] = ::mmx::Contract_transfer::static_get_type_code();
	type_code->methods[6] = ::mmx::Contract_validate::static_get_type_code();
	type_code->methods[7] = ::mmx::contract::TokenBase_calc_cost::static_get_type_code();
	type_code->methods[8] = ::mmx::contract::TokenBase_calc_hash::static_get_type_code();
	type_code->methods[9] = ::mmx::contract::TokenBase_is_valid::static_get_type_code();
	type_code->fields.resize(6);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "version";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "name";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "symbol";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "web_url";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "icon_url";
		field.code = {32};
	}
	{
		auto& field = type_code->fields[5];
		field.data_size = 4;
		field.name = "decimals";
		field.value = vnx::to_string(6);
		field.code = {7};
	}
	type_code->build();
	return type_code;
}

std::shared_ptr<vnx::Value> TokenBase::vnx_call_switch(std::shared_ptr<const vnx::Value> _method) {
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
		case 0xc758d95e2799f160ull: {
			auto _args = std::static_pointer_cast<const ::mmx::contract::TokenBase_calc_cost>(_method);
			auto _return_value = ::mmx::contract::TokenBase_calc_cost_return::create();
			_return_value->_ret_0 = calc_cost(_args->params);
			return _return_value;
		}
		case 0x174a1238420b859full: {
			auto _args = std::static_pointer_cast<const ::mmx::contract::TokenBase_calc_hash>(_method);
			auto _return_value = ::mmx::contract::TokenBase_calc_hash_return::create();
			_return_value->_ret_0 = calc_hash();
			return _return_value;
		}
		case 0x771fd1948e99a4b4ull: {
			auto _args = std::static_pointer_cast<const ::mmx::contract::TokenBase_is_valid>(_method);
			auto _return_value = ::mmx::contract::TokenBase_is_valid_return::create();
			_return_value->_ret_0 = is_valid();
			return _return_value;
		}
	}
	return nullptr;
}


} // namespace mmx
} // namespace contract


namespace vnx {

void read(TypeInput& in, ::mmx::contract::TokenBase& value, const TypeCode* type_code, const uint16_t* code) {
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
		if(const auto* const _field = type_code->field_map[5]) {
			vnx::read_value(_buf + _field->offset, value.decimals, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.name, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.symbol, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.web_url, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.icon_url, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::contract::TokenBase& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::contract::vnx_native_type_code_TokenBase;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::contract::TokenBase>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.version);
	vnx::write_value(_buf + 4, value.decimals);
	vnx::write(out, value.name, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.symbol, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.web_url, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.icon_url, type_code, type_code->fields[4].code.data());
}

void read(std::istream& in, ::mmx::contract::TokenBase& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::contract::TokenBase& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::contract::TokenBase& value) {
	value.accept(visitor);
}

} // vnx
