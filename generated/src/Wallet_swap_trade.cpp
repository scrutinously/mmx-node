
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/Wallet_swap_trade.hxx>
#include <mmx/Wallet_swap_trade_return.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/spend_options_t.hxx>
#include <mmx/uint80.hpp>
#include <vnx/Value.h>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 Wallet_swap_trade::VNX_TYPE_HASH(0x4b5a42cbf6657910ull);
const vnx::Hash64 Wallet_swap_trade::VNX_CODE_HASH(0xae110613e47f07dull);

vnx::Hash64 Wallet_swap_trade::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string Wallet_swap_trade::get_type_name() const {
	return "mmx.Wallet.swap_trade";
}

const vnx::TypeCode* Wallet_swap_trade::get_type_code() const {
	return mmx::vnx_native_type_code_Wallet_swap_trade;
}

std::shared_ptr<Wallet_swap_trade> Wallet_swap_trade::create() {
	return std::make_shared<Wallet_swap_trade>();
}

std::shared_ptr<vnx::Value> Wallet_swap_trade::clone() const {
	return std::make_shared<Wallet_swap_trade>(*this);
}

void Wallet_swap_trade::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void Wallet_swap_trade::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void Wallet_swap_trade::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_Wallet_swap_trade;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, index);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, address);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, amount);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, currency);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, min_trade);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, num_iter);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, options);
	_visitor.type_end(*_type_code);
}

void Wallet_swap_trade::write(std::ostream& _out) const {
	_out << "{\"__type\": \"mmx.Wallet.swap_trade\"";
	_out << ", \"index\": "; vnx::write(_out, index);
	_out << ", \"address\": "; vnx::write(_out, address);
	_out << ", \"amount\": "; vnx::write(_out, amount);
	_out << ", \"currency\": "; vnx::write(_out, currency);
	_out << ", \"min_trade\": "; vnx::write(_out, min_trade);
	_out << ", \"num_iter\": "; vnx::write(_out, num_iter);
	_out << ", \"options\": "; vnx::write(_out, options);
	_out << "}";
}

void Wallet_swap_trade::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object Wallet_swap_trade::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.Wallet.swap_trade";
	_object["index"] = index;
	_object["address"] = address;
	_object["amount"] = amount;
	_object["currency"] = currency;
	_object["min_trade"] = min_trade;
	_object["num_iter"] = num_iter;
	_object["options"] = options;
	return _object;
}

void Wallet_swap_trade::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "address") {
			_entry.second.to(address);
		} else if(_entry.first == "amount") {
			_entry.second.to(amount);
		} else if(_entry.first == "currency") {
			_entry.second.to(currency);
		} else if(_entry.first == "index") {
			_entry.second.to(index);
		} else if(_entry.first == "min_trade") {
			_entry.second.to(min_trade);
		} else if(_entry.first == "num_iter") {
			_entry.second.to(num_iter);
		} else if(_entry.first == "options") {
			_entry.second.to(options);
		}
	}
}

vnx::Variant Wallet_swap_trade::get_field(const std::string& _name) const {
	if(_name == "index") {
		return vnx::Variant(index);
	}
	if(_name == "address") {
		return vnx::Variant(address);
	}
	if(_name == "amount") {
		return vnx::Variant(amount);
	}
	if(_name == "currency") {
		return vnx::Variant(currency);
	}
	if(_name == "min_trade") {
		return vnx::Variant(min_trade);
	}
	if(_name == "num_iter") {
		return vnx::Variant(num_iter);
	}
	if(_name == "options") {
		return vnx::Variant(options);
	}
	return vnx::Variant();
}

void Wallet_swap_trade::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "index") {
		_value.to(index);
	} else if(_name == "address") {
		_value.to(address);
	} else if(_name == "amount") {
		_value.to(amount);
	} else if(_name == "currency") {
		_value.to(currency);
	} else if(_name == "min_trade") {
		_value.to(min_trade);
	} else if(_name == "num_iter") {
		_value.to(num_iter);
	} else if(_name == "options") {
		_value.to(options);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const Wallet_swap_trade& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, Wallet_swap_trade& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* Wallet_swap_trade::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> Wallet_swap_trade::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.Wallet.swap_trade";
	type_code->type_hash = vnx::Hash64(0x4b5a42cbf6657910ull);
	type_code->code_hash = vnx::Hash64(0xae110613e47f07dull);
	type_code->is_native = true;
	type_code->is_class = true;
	type_code->is_method = true;
	type_code->native_size = sizeof(::mmx::Wallet_swap_trade);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<Wallet_swap_trade>(); };
	type_code->depends.resize(1);
	type_code->depends[0] = ::mmx::spend_options_t::static_get_type_code();
	type_code->is_const = true;
	type_code->return_type = ::mmx::Wallet_swap_trade_return::static_get_type_code();
	type_code->fields.resize(7);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "index";
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.is_extended = true;
		field.name = "address";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[2];
		field.is_extended = true;
		field.name = "amount";
		field.code = {11, 10, 1};
	}
	{
		auto& field = type_code->fields[3];
		field.is_extended = true;
		field.name = "currency";
		field.code = {11, 32, 1};
	}
	{
		auto& field = type_code->fields[4];
		field.is_extended = true;
		field.name = "min_trade";
		field.code = {33, 11, 10, 1};
	}
	{
		auto& field = type_code->fields[5];
		field.data_size = 4;
		field.name = "num_iter";
		field.value = vnx::to_string(20);
		field.code = {7};
	}
	{
		auto& field = type_code->fields[6];
		field.is_extended = true;
		field.name = "options";
		field.code = {19, 0};
	}
	type_code->permission = "mmx.permission_e.SPENDING";
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::Wallet_swap_trade& value, const TypeCode* type_code, const uint16_t* code) {
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
		if(const auto* const _field = type_code->field_map[0]) {
			vnx::read_value(_buf + _field->offset, value.index, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[5]) {
			vnx::read_value(_buf + _field->offset, value.num_iter, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 1: vnx::read(in, value.address, type_code, _field->code.data()); break;
			case 2: vnx::read(in, value.amount, type_code, _field->code.data()); break;
			case 3: vnx::read(in, value.currency, type_code, _field->code.data()); break;
			case 4: vnx::read(in, value.min_trade, type_code, _field->code.data()); break;
			case 6: vnx::read(in, value.options, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::Wallet_swap_trade& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_Wallet_swap_trade;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::Wallet_swap_trade>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	auto* const _buf = out.write(8);
	vnx::write_value(_buf + 0, value.index);
	vnx::write_value(_buf + 4, value.num_iter);
	vnx::write(out, value.address, type_code, type_code->fields[1].code.data());
	vnx::write(out, value.amount, type_code, type_code->fields[2].code.data());
	vnx::write(out, value.currency, type_code, type_code->fields[3].code.data());
	vnx::write(out, value.min_trade, type_code, type_code->fields[4].code.data());
	vnx::write(out, value.options, type_code, type_code->fields[6].code.data());
}

void read(std::istream& in, ::mmx::Wallet_swap_trade& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::Wallet_swap_trade& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::Wallet_swap_trade& value) {
	value.accept(visitor);
}

} // vnx
