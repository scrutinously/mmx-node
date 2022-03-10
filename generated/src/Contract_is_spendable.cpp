
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Contract_is_spendable.hxx>
#include <mmx/Context.hxx>
#include <mmx/Contract_is_spendable_return.hxx>
#include <mmx/utxo_t.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Contract_is_spendable::VNX_TYPE_HASH(0xd12879d16cac3d5cull);
const vnx::Hash64 Contract_is_spendable::VNX_CODE_HASH(0xbb86ee35f95e834eull);

vnx::Hash64 Contract_is_spendable::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Contract_is_spendable::get_type_name() const {
	return "mmx.Contract.is_spendable";
}

const vnx::TypeCode* Contract_is_spendable::get_type_code() const {
	return mmx::vnx_native_type_code_Contract_is_spendable;
}

std::shared_ptr<Contract_is_spendable> Contract_is_spendable::create() {
	return std::make_shared<Contract_is_spendable>();
}

std::shared_ptr<vnx::Value> Contract_is_spendable::clone() const {
	return std::make_shared<Contract_is_spendable>(*this);
}

void Contract_is_spendable::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Contract_is_spendable::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Contract_is_spendable::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Contract_is_spendable;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, utxo);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, context);
	_visitor.type_end(*_type_code);
}

void Contract_is_spendable::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Contract.is_spendable\"";
	_out << ", \"utxo\": "; vnx::write(_out, utxo);
	_out << ", \"context\": "; vnx::write(_out, context);
	_out << "}";
}

void Contract_is_spendable::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Contract_is_spendable::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Contract.is_spendable";
	_object["utxo"] = utxo;
	_object["context"] = context;
	return _object;
}

void Contract_is_spendable::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "context") {
			_entry.second.to(context);
		} else if(_entry.first == "utxo") {
			_entry.second.to(utxo);
		}
	}
}

vnx::Variant Contract_is_spendable::get_field(const std::string& _name) const {
	if(_name == "utxo") {
		return vnx::Variant(utxo);
	}
	if(_name == "context") {
		return vnx::Variant(context);
	}
	return vnx::Variant();
}

void Contract_is_spendable::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "utxo") {
		_value.to(utxo);
	} else if(_name == "context") {
		_value.to(context);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Contract_is_spendable& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Contract_is_spendable& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Contract_is_spendable::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Contract_is_spendable::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Contract.is_spendable";
	type_code->type_hash = vnx::Hash64(0xd12879d16cac3d5cull);
	type_code->code_hash = vnx::Hash64(0xbb86ee35f95e834eull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Contract_is_spendable);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Contract_is_spendable>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::utxo_t::static_get_type_code();
	type_code->is_const = true;
	type_code->return_type = ::mmx::Contract_is_spendable_return::static_get_type_code();
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "utxo";
		field.code = {19, 0};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "context";
		field.code = {16};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Contract_is_spendable& value, const TypeCode* type_code, const uint16_t* code) {
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
	in.read(type_code->total_field_size);
	if(type_code->is_matched) {
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.utxo, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.context, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Contract_is_spendable& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Contract_is_spendable;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Contract_is_spendable>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.utxo, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.context, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::Contract_is_spendable& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Contract_is_spendable& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Contract_is_spendable& value) {
	value.accept(visitor);
}

} // vnx
