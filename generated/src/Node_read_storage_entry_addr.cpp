
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Node_read_storage_entry_addr.hxx>
#include <mmx/Node_read_storage_entry_addr_return.hxx>
#include <mmx/addr_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Node_read_storage_entry_addr::VNX_TYPE_HASH(0xffbf8c4478bb5ab5ull);
const vnx::Hash64 Node_read_storage_entry_addr::VNX_CODE_HASH(0x3d1c0b58a99f9dd6ull);

vnx::Hash64 Node_read_storage_entry_addr::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Node_read_storage_entry_addr::get_type_name() const {
	return "mmx.Node.read_storage_entry_addr";
}

const vnx::TypeCode* Node_read_storage_entry_addr::get_type_code() const {
	return mmx::vnx_native_type_code_Node_read_storage_entry_addr;
}

std::shared_ptr<Node_read_storage_entry_addr> Node_read_storage_entry_addr::create() {
	return std::make_shared<Node_read_storage_entry_addr>();
}

std::shared_ptr<vnx::Value> Node_read_storage_entry_addr::clone() const {
	return std::make_shared<Node_read_storage_entry_addr>(*this);
}

void Node_read_storage_entry_addr::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Node_read_storage_entry_addr::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Node_read_storage_entry_addr::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Node_read_storage_entry_addr;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, contract);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, name);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, key);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, height);
	_visitor.type_end(*_type_code);
}

void Node_read_storage_entry_addr::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Node.read_storage_entry_addr\"";
	_out << ", \"contract\": "; vnx::write(_out, contract);
	_out << ", \"name\": "; vnx::write(_out, name);
	_out << ", \"key\": "; vnx::write(_out, key);
	_out << ", \"height\": "; vnx::write(_out, height);
	_out << "}";
}

void Node_read_storage_entry_addr::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Node_read_storage_entry_addr::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Node.read_storage_entry_addr";
	_object["contract"] = contract;
	_object["name"] = name;
	_object["key"] = key;
	_object["height"] = height;
	return _object;
}

void Node_read_storage_entry_addr::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "contract") {
			_entry.second.to(contract);
		} else if(_entry.first == "height") {
			_entry.second.to(height);
		} else if(_entry.first == "key") {
			_entry.second.to(key);
		} else if(_entry.first == "name") {
			_entry.second.to(name);
		}
	}
}

vnx::Variant Node_read_storage_entry_addr::get_field(const std::string& _name) const {
	if(_name == "contract") {
		return vnx::Variant(contract);
	}
	if(_name == "name") {
		return vnx::Variant(name);
	}
	if(_name == "key") {
		return vnx::Variant(key);
	}
	if(_name == "height") {
		return vnx::Variant(height);
	}
	return vnx::Variant();
}

void Node_read_storage_entry_addr::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "contract") {
		_value.to(contract);
	} else if(_name == "name") {
		_value.to(name);
	} else if(_name == "key") {
		_value.to(key);
	} else if(_name == "height") {
		_value.to(height);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Node_read_storage_entry_addr& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Node_read_storage_entry_addr& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Node_read_storage_entry_addr::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Node_read_storage_entry_addr::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Node.read_storage_entry_addr";
	type_code->type_hash = vnx::Hash64(0xffbf8c4478bb5ab5ull);
	type_code->code_hash = vnx::Hash64(0x3d1c0b58a99f9dd6ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Node_read_storage_entry_addr);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Node_read_storage_entry_addr>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::Node_read_storage_entry_addr_return::static_get_type_code();
	type_code->fields.resize(4);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "contract";
		field.code = {11, 32, 1};
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
		field.name = "key";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 4;
		field.name = "height";
		field.value = vnx::to_string(-1);
		field.code = {3};
	}
	type_code->permission = "mmx.permission_e.PUBLIC";
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Node_read_storage_entry_addr& value, const TypeCode* type_code, const uint16_t* code) {
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
	const auto* const _buf = in.read(type_code->total_field_size);
	if(type_code->is_matched) {
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.height, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 0: vnx::read(in, value.contract, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.name, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.key, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Node_read_storage_entry_addr& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Node_read_storage_entry_addr;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Node_read_storage_entry_addr>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(4);
	vnx::write_value(_buf + 0, value.height);
	vnx::write(out, value.contract, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.name, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.key, type_code, type_code->fields[2].code.data());
}

void read(std::istream& in, ::mmx::Node_read_storage_entry_addr& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Node_read_storage_entry_addr& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Node_read_storage_entry_addr& value) {
	value.accept(visitor);
}

} // vnx
