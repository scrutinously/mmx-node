
// AUTO GENERATED by vnxcppcodegen

#include <mmx/package.hxx>
#include <mmx/spend_options_t.hxx>
#include <mmx/Contract.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/txio_key_t.hxx>
#include <mmx/utxo_t.hxx>

#include <vnx/vnx.h>


namespace mmx {


const vnx::Hash64 spend_options_t::VNX_TYPE_HASH(0x37f7c6d377362e95ull);
const vnx::Hash64 spend_options_t::VNX_CODE_HASH(0x384f33a50e8831fdull);

vnx::Hash64 spend_options_t::get_type_hash() const {
	return VNX_TYPE_HASH;
}

std::string spend_options_t::get_type_name() const {
	return "mmx.spend_options_t";
}

const vnx::TypeCode* spend_options_t::get_type_code() const {
	return mmx::vnx_native_type_code_spend_options_t;
}

std::shared_ptr<spend_options_t> spend_options_t::create() {
	return std::make_shared<spend_options_t>();
}

std::shared_ptr<spend_options_t> spend_options_t::clone() const {
	return std::make_shared<spend_options_t>(*this);
}

void spend_options_t::read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) {
	vnx::read(_in, *this, _type_code, _code);
}

void spend_options_t::write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const {
	vnx::write(_out, *this, _type_code, _code);
}

void spend_options_t::accept(vnx::Visitor& _visitor) const {
	const vnx::TypeCode* _type_code = mmx::vnx_native_type_code_spend_options_t;
	_visitor.type_begin(*_type_code);
	_visitor.type_field(_type_code->fields[0], 0); vnx::accept(_visitor, min_confirm);
	_visitor.type_field(_type_code->fields[1], 1); vnx::accept(_visitor, split_output);
	_visitor.type_field(_type_code->fields[2], 2); vnx::accept(_visitor, extra_fee);
	_visitor.type_field(_type_code->fields[3], 3); vnx::accept(_visitor, over_spend);
	_visitor.type_field(_type_code->fields[4], 4); vnx::accept(_visitor, pending_change);
	_visitor.type_field(_type_code->fields[5], 5); vnx::accept(_visitor, change_addr);
	_visitor.type_field(_type_code->fields[6], 6); vnx::accept(_visitor, exclude);
	_visitor.type_field(_type_code->fields[7], 7); vnx::accept(_visitor, spend_only);
	_visitor.type_field(_type_code->fields[8], 8); vnx::accept(_visitor, owner_map);
	_visitor.type_field(_type_code->fields[9], 9); vnx::accept(_visitor, utxo_map);
	_visitor.type_field(_type_code->fields[10], 10); vnx::accept(_visitor, contract_map);
	_visitor.type_end(*_type_code);
}

void spend_options_t::write(std::ostream& _out) const {
	_out << "{";
	_out << "\"min_confirm\": "; vnx::write(_out, min_confirm);
	_out << ", \"split_output\": "; vnx::write(_out, split_output);
	_out << ", \"extra_fee\": "; vnx::write(_out, extra_fee);
	_out << ", \"over_spend\": "; vnx::write(_out, over_spend);
	_out << ", \"pending_change\": "; vnx::write(_out, pending_change);
	_out << ", \"change_addr\": "; vnx::write(_out, change_addr);
	_out << ", \"exclude\": "; vnx::write(_out, exclude);
	_out << ", \"spend_only\": "; vnx::write(_out, spend_only);
	_out << ", \"owner_map\": "; vnx::write(_out, owner_map);
	_out << ", \"utxo_map\": "; vnx::write(_out, utxo_map);
	_out << ", \"contract_map\": "; vnx::write(_out, contract_map);
	_out << "}";
}

void spend_options_t::read(std::istream& _in) {
	if(auto _json = vnx::read_json(_in)) {
		from_object(_json->to_object());
	}
}

vnx::Object spend_options_t::to_object() const {
	vnx::Object _object;
	_object["__type"] = "mmx.spend_options_t";
	_object["min_confirm"] = min_confirm;
	_object["split_output"] = split_output;
	_object["extra_fee"] = extra_fee;
	_object["over_spend"] = over_spend;
	_object["pending_change"] = pending_change;
	_object["change_addr"] = change_addr;
	_object["exclude"] = exclude;
	_object["spend_only"] = spend_only;
	_object["owner_map"] = owner_map;
	_object["utxo_map"] = utxo_map;
	_object["contract_map"] = contract_map;
	return _object;
}

void spend_options_t::from_object(const vnx::Object& _object) {
	for(const auto& _entry : _object.field) {
		if(_entry.first == "change_addr") {
			_entry.second.to(change_addr);
		} else if(_entry.first == "contract_map") {
			_entry.second.to(contract_map);
		} else if(_entry.first == "exclude") {
			_entry.second.to(exclude);
		} else if(_entry.first == "extra_fee") {
			_entry.second.to(extra_fee);
		} else if(_entry.first == "min_confirm") {
			_entry.second.to(min_confirm);
		} else if(_entry.first == "over_spend") {
			_entry.second.to(over_spend);
		} else if(_entry.first == "owner_map") {
			_entry.second.to(owner_map);
		} else if(_entry.first == "pending_change") {
			_entry.second.to(pending_change);
		} else if(_entry.first == "spend_only") {
			_entry.second.to(spend_only);
		} else if(_entry.first == "split_output") {
			_entry.second.to(split_output);
		} else if(_entry.first == "utxo_map") {
			_entry.second.to(utxo_map);
		}
	}
}

vnx::Variant spend_options_t::get_field(const std::string& _name) const {
	if(_name == "min_confirm") {
		return vnx::Variant(min_confirm);
	}
	if(_name == "split_output") {
		return vnx::Variant(split_output);
	}
	if(_name == "extra_fee") {
		return vnx::Variant(extra_fee);
	}
	if(_name == "over_spend") {
		return vnx::Variant(over_spend);
	}
	if(_name == "pending_change") {
		return vnx::Variant(pending_change);
	}
	if(_name == "change_addr") {
		return vnx::Variant(change_addr);
	}
	if(_name == "exclude") {
		return vnx::Variant(exclude);
	}
	if(_name == "spend_only") {
		return vnx::Variant(spend_only);
	}
	if(_name == "owner_map") {
		return vnx::Variant(owner_map);
	}
	if(_name == "utxo_map") {
		return vnx::Variant(utxo_map);
	}
	if(_name == "contract_map") {
		return vnx::Variant(contract_map);
	}
	return vnx::Variant();
}

void spend_options_t::set_field(const std::string& _name, const vnx::Variant& _value) {
	if(_name == "min_confirm") {
		_value.to(min_confirm);
	} else if(_name == "split_output") {
		_value.to(split_output);
	} else if(_name == "extra_fee") {
		_value.to(extra_fee);
	} else if(_name == "over_spend") {
		_value.to(over_spend);
	} else if(_name == "pending_change") {
		_value.to(pending_change);
	} else if(_name == "change_addr") {
		_value.to(change_addr);
	} else if(_name == "exclude") {
		_value.to(exclude);
	} else if(_name == "spend_only") {
		_value.to(spend_only);
	} else if(_name == "owner_map") {
		_value.to(owner_map);
	} else if(_name == "utxo_map") {
		_value.to(utxo_map);
	} else if(_name == "contract_map") {
		_value.to(contract_map);
	}
}

/// \private
std::ostream& operator<<(std::ostream& _out, const spend_options_t& _value) {
	_value.write(_out);
	return _out;
}

/// \private
std::istream& operator>>(std::istream& _in, spend_options_t& _value) {
	_value.read(_in);
	return _in;
}

const vnx::TypeCode* spend_options_t::static_get_type_code() {
	const vnx::TypeCode* type_code = vnx::get_type_code(VNX_TYPE_HASH);
	if(!type_code) {
		type_code = vnx::register_type_code(static_create_type_code());
	}
	return type_code;
}

std::shared_ptr<vnx::TypeCode> spend_options_t::static_create_type_code() {
	auto type_code = std::make_shared<vnx::TypeCode>();
	type_code->name = "mmx.spend_options_t";
	type_code->type_hash = vnx::Hash64(0x37f7c6d377362e95ull);
	type_code->code_hash = vnx::Hash64(0x384f33a50e8831fdull);
	type_code->is_native = true;
	type_code->native_size = sizeof(::mmx::spend_options_t);
	type_code->create_value = []() -> std::shared_ptr<vnx::Value> { return std::make_shared<vnx::Struct<spend_options_t>>(); };
	type_code->depends.resize(2);
	type_code->depends[0] = ::mmx::txio_key_t::static_get_type_code();
	type_code->depends[1] = ::mmx::utxo_t::static_get_type_code();
	type_code->fields.resize(11);
	{
		auto& field = type_code->fields[0];
		field.data_size = 4;
		field.name = "min_confirm";
		field.value = vnx::to_string(1);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[1];
		field.data_size = 4;
		field.name = "split_output";
		field.value = vnx::to_string(1);
		field.code = {3};
	}
	{
		auto& field = type_code->fields[2];
		field.data_size = 8;
		field.name = "extra_fee";
		field.code = {4};
	}
	{
		auto& field = type_code->fields[3];
		field.data_size = 1;
		field.name = "over_spend";
		field.value = vnx::to_string(true);
		field.code = {31};
	}
	{
		auto& field = type_code->fields[4];
		field.data_size = 1;
		field.name = "pending_change";
		field.value = vnx::to_string(false);
		field.code = {31};
	}
	{
		auto& field = type_code->fields[5];
		field.is_extended = true;
		field.name = "change_addr";
		field.code = {33, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[6];
		field.is_extended = true;
		field.name = "exclude";
		field.code = {12, 19, 0};
	}
	{
		auto& field = type_code->fields[7];
		field.is_extended = true;
		field.name = "spend_only";
		field.code = {33, 12, 19, 0};
	}
	{
		auto& field = type_code->fields[8];
		field.is_extended = true;
		field.name = "owner_map";
		field.code = {12, 23, 2, 4, 7, 11, 32, 1, 11, 32, 1};
	}
	{
		auto& field = type_code->fields[9];
		field.is_extended = true;
		field.name = "utxo_map";
		field.code = {12, 23, 2, 4, 6, 19, 0, 19, 1};
	}
	{
		auto& field = type_code->fields[10];
		field.is_extended = true;
		field.name = "contract_map";
		field.code = {13, 5, 11, 32, 1, 16};
	}
	type_code->build();
	return type_code;
}


} // namespace mmx


namespace vnx {

void read(TypeInput& in, ::mmx::spend_options_t& value, const TypeCode* type_code, const uint16_t* code) {
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
			vnx::read_value(_buf + _field->offset, value.min_confirm, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[1]) {
			vnx::read_value(_buf + _field->offset, value.split_output, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[2]) {
			vnx::read_value(_buf + _field->offset, value.extra_fee, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[3]) {
			vnx::read_value(_buf + _field->offset, value.over_spend, _field->code.data());
		}
		if(const auto* const _field = type_code->field_map[4]) {
			vnx::read_value(_buf + _field->offset, value.pending_change, _field->code.data());
		}
	}
	for(const auto* _field : type_code->ext_fields) {
		switch(_field->native_index) {
			case 5: vnx::read(in, value.change_addr, type_code, _field->code.data()); break;
			case 6: vnx::read(in, value.exclude, type_code, _field->code.data()); break;
			case 7: vnx::read(in, value.spend_only, type_code, _field->code.data()); break;
			case 8: vnx::read(in, value.owner_map, type_code, _field->code.data()); break;
			case 9: vnx::read(in, value.utxo_map, type_code, _field->code.data()); break;
			case 10: vnx::read(in, value.contract_map, type_code, _field->code.data()); break;
			default: vnx::skip(in, type_code, _field->code.data());
		}
	}
}

void write(TypeOutput& out, const ::mmx::spend_options_t& value, const TypeCode* type_code, const uint16_t* code) {
	if(code && code[0] == CODE_OBJECT) {
		vnx::write(out, value.to_object(), nullptr, code);
		return;
	}
	if(!type_code || (code && code[0] == CODE_ANY)) {
		type_code = mmx::vnx_native_type_code_spend_options_t;
		out.write_type_code(type_code);
		vnx::write_class_header<::mmx::spend_options_t>(out);
	}
	else if(code && code[0] == CODE_STRUCT) {
		type_code = type_code->depends[code[1]];
	}
	char* const _buf = out.write(18);
	vnx::write_value(_buf + 0, value.min_confirm);
	vnx::write_value(_buf + 4, value.split_output);
	vnx::write_value(_buf + 8, value.extra_fee);
	vnx::write_value(_buf + 16, value.over_spend);
	vnx::write_value(_buf + 17, value.pending_change);
	vnx::write(out, value.change_addr, type_code, type_code->fields[5].code.data());
	vnx::write(out, value.exclude, type_code, type_code->fields[6].code.data());
	vnx::write(out, value.spend_only, type_code, type_code->fields[7].code.data());
	vnx::write(out, value.owner_map, type_code, type_code->fields[8].code.data());
	vnx::write(out, value.utxo_map, type_code, type_code->fields[9].code.data());
	vnx::write(out, value.contract_map, type_code, type_code->fields[10].code.data());
}

void read(std::istream& in, ::mmx::spend_options_t& value) {
	value.read(in);
}

void write(std::ostream& out, const ::mmx::spend_options_t& value) {
	value.write(out);
}

void accept(Visitor& visitor, const ::mmx::spend_options_t& value) {
	value.accept(visitor);
}

bool is_equivalent<::mmx::spend_options_t>::operator()(const uint16_t* code, const TypeCode* type_code) {
	if(code[0] != CODE_STRUCT || !type_code) {
		return false;
	}
	type_code = type_code->depends[code[1]];
	return type_code->type_hash == ::mmx::spend_options_t::VNX_TYPE_HASH && type_code->is_equivalent;
}

} // vnx
