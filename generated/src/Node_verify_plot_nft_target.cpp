
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Node_verify_plot_nft_target.hxx>
#include <mmx/Node_verify_plot_nft_target_return.hxx>
#include <mmx/addr_t.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Node_verify_plot_nft_target::VNX_TYPE_HASH(0xf3ac786edcae50e1ull);
const vnx::Hash64 Node_verify_plot_nft_target::VNX_CODE_HASH(0xf5349444ccd84317ull);

vnx::Hash64 Node_verify_plot_nft_target::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Node_verify_plot_nft_target::get_type_name() const {
	return "mmx.Node.verify_plot_nft_target";
}

const vnx::TypeCode* Node_verify_plot_nft_target::get_type_code() const {
	return mmx::vnx_native_type_code_Node_verify_plot_nft_target;
}

std::shared_ptr<Node_verify_plot_nft_target> Node_verify_plot_nft_target::create() {
	return std::make_shared<Node_verify_plot_nft_target>();
}

std::shared_ptr<vnx::Value> Node_verify_plot_nft_target::clone() const {
	return std::make_shared<Node_verify_plot_nft_target>(*this);
}

void Node_verify_plot_nft_target::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Node_verify_plot_nft_target::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Node_verify_plot_nft_target::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Node_verify_plot_nft_target;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, address);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, pool_target);
	_visitor.type_end(*_type_code);
}

void Node_verify_plot_nft_target::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Node.verify_plot_nft_target\"";
	_out << ", \"address\": "; vnx::write(_out, address);
	_out << ", \"pool_target\": "; vnx::write(_out, pool_target);
	_out << "}";
}

void Node_verify_plot_nft_target::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Node_verify_plot_nft_target::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Node.verify_plot_nft_target";
	_object["address"] = address;
	_object["pool_target"] = pool_target;
	return _object;
}

void Node_verify_plot_nft_target::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "address") {
			_entry.second.to(address);
		} else if(_entry.first == "pool_target") {
			_entry.second.to(pool_target);
		}
	}
}

vnx::Variant Node_verify_plot_nft_target::get_field(const std::string& _name) const {
	if(_name == "address") {
		return vnx::Variant(address);
	}
	if(_name == "pool_target") {
		return vnx::Variant(pool_target);
	}
	return vnx::Variant();
}

void Node_verify_plot_nft_target::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "address") {
		_value.to(address);
	} else if(_name == "pool_target") {
		_value.to(pool_target);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Node_verify_plot_nft_target& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Node_verify_plot_nft_target& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Node_verify_plot_nft_target::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Node_verify_plot_nft_target::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Node.verify_plot_nft_target";
	type_code->type_hash = vnx::Hash64(0xf3ac786edcae50e1ull);
	type_code->code_hash = vnx::Hash64(0xf5349444ccd84317ull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Node_verify_plot_nft_target);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Node_verify_plot_nft_target>(); };
	type_code->is_const = true;
	type_code->return_type = ::mmx::Node_verify_plot_nft_target_return::static_get_type_code();
	type_code->fields.resize(2);
	{
		auto& field = type_code->fields[0];
		field.is_extended = true;
		field.name = "address";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "pool_target";
		field.code = {11, 32, 1};
	}
	type_code->permission = "mmx.permission_e.PUBLIC";
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Node_verify_plot_nft_target& value, const TypeCode* type_code, const uint16_t* code) {
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
			case 0: vnx::read(in, value.address, type_code, _field->code.data()); break;
			case 1: vnx::read(in, value.pool_target, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Node_verify_plot_nft_target& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Node_verify_plot_nft_target;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Node_verify_plot_nft_target>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	vnx::write(out, value.address, type_code, type_code->fields[0].code.data());
	vnx::write(out, value.pool_target, type_code, type_code->fields[1].code.data());
}

void read(std::istream& in, ::mmx::Node_verify_plot_nft_target& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Node_verify_plot_nft_target& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Node_verify_plot_nft_target& value) {
	value.accept(visitor);
}

} // vnx
