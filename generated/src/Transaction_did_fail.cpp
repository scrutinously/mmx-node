
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Transaction_did_fail.hxx>
#include <mmx/Transaction_did_fail_return.hxx>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Transaction_did_fail::VNX_TYPE_HASH(0xf5a3e147c8d8485aull);
const vnx::Hash64 Transaction_did_fail::VNX_CODE_HASH(0x18286bb037e4ff06ull);

vnx::Hash64 Transaction_did_fail::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Transaction_did_fail::get_type_name() const {
	return "mmx.Transaction.did_fail";
}

const vnx::TypeCode* Transaction_did_fail::get_type_code() const {
	return mmx::vnx_native_type_code_Transaction_did_fail;
}

std::shared_ptr<Transaction_did_fail> Transaction_did_fail::create() {
	return std::make_shared<Transaction_did_fail>();
}

std::shared_ptr<vnx::Value> Transaction_did_fail::clone() const {
	return std::make_shared<Transaction_did_fail>(*this);
}

void Transaction_did_fail::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Transaction_did_fail::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Transaction_did_fail::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Transaction_did_fail;
	_visitor.type_begin(*_type_code);
	_visitor.type_end(*_type_code);
}

void Transaction_did_fail::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Transaction.did_fail\"";
	_out << "}";
}

void Transaction_did_fail::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Transaction_did_fail::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Transaction.did_fail";
	return _object;
}

void Transaction_did_fail::from_object(const vnx::Object& _object) {
}

vnx::Variant Transaction_did_fail::get_field(const std::string& _name) const {
	return vnx::Variant();
}

void Transaction_did_fail::set_field(const std::string& _name, const vnx::Variant& _value) {
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Transaction_did_fail& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Transaction_did_fail& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Transaction_did_fail::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Transaction_did_fail::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Transaction.did_fail";
	type_code->type_hash = vnx::Hash64(0xf5a3e147c8d8485aull);
	type_code->code_hash = vnx::Hash64(0x18286bb037e4ff06ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Transaction_did_fail);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Transaction_did_fail>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::Transaction_did_fail_return::static_get_type_code();
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Transaction_did_fail& value, const TypeCode* type_code, const uint16_t* code) {
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
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Transaction_did_fail& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Transaction_did_fail;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Transaction_did_fail>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
}

void read(std::istream& in, ::mmx::Transaction_did_fail& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Transaction_did_fail& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Transaction_did_fail& value) {
	value.accept(visitor);
}

} // vnx
