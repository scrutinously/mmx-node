
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/WalletFile.hxx>
#include <mmx/addr_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 WalletFile::VNX_TYPE_HASH(0xefcdc0f20fc4360eull);
const vnx::Hash64 WalletFile::VNX_CODE_HASH(0x82ac26e33ee406a0ull);

vnx::Hash64 WalletFile::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string WalletFile::get_type_name() const {
	return "mmx.WalletFile";
}

const vnx::TypeCode* WalletFile::get_type_code() const {
	return mmx::vnx_native_type_code_WalletFile;
}

std::shared_ptr<WalletFile> WalletFile::create() {
	return std::make_shared<WalletFile>();
}

std::shared_ptr<vnx::Value> WalletFile::clone() const {
	return std::make_shared<WalletFile>(*this);
}

void WalletFile::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void WalletFile::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void WalletFile::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_WalletFile;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, addresses);
	_visitor.type_end(*_type_code);
}

void WalletFile::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.WalletFile\"";
	_out << ", \"addresses\": "; vnx::write(_out, addresses);
	_out << "}";
}

void WalletFile::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object WalletFile::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.WalletFile";
	_object["addresses"] = addresses;
	return _object;
}

void WalletFile::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "addresses") {
			_entry.second.to(addresses);
		}
	}
}

vnx::Variant WalletFile::get_field(const std::string& _name) const {
	if(_name == "addresses") {
		return vnx::Variant(addresses);
	}
	return vnx::Variant();
}

void WalletFile::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "addresses") {
		_value.to(addresses);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const WalletFile& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, WalletFile& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* WalletFile::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> WalletFile::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.WalletFile";
	type_code->type_hash = vnx::Hash64(0xefcdc0f20fc4360eull);
	type_code->code_hash = vnx::Hash64(0x82ac26e33ee406a0ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->native_size = sizeof(::mmx::WalletFile);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<WalletFile>(); };
	type_code->fields.resize(1);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "addresses";
		field.code = {12, 11, 32, 1};
	}
	type_code->build();
	return type_code;
}

std::shared_ptr<vnx::Value> WalletFile::vnx_call_switch(std::shared_ptr<const vnx::Value> _method) {
	switch(_method->get_type_hash()) {
	}
	return nullptr;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::WalletFile& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.addresses, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::WalletFile& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_WalletFile;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::WalletFile>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.addresses, type_code, type_code->fields[0].code.data());
}

void read(std::istream& in, ::mmx::WalletFile& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::WalletFile& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::WalletFile& value) {
	value.accept(visitor);
}

} // vnx
