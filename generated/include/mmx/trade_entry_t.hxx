
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_trade_entry_t_HXX_
#define INCLUDE_mmx_trade_entry_t_HXX_

#include <vnx/Type.h>
#include <mmx/package.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>
#include <mmx/uint80.hpp>


namespace mmx {

struct MMX_EXPORT trade_entry_t : vnx::struct_t {
	
	
	uint32_t height = 0;
	int64_t time_stamp = 0;
	::mmx::addr_t address;
	::mmx::hash_t txid;
	::mmx::addr_t bid_currency;
	::mmx::addr_t ask_currency;
	::mmx::uint80 bid_amount;
	::mmx::uint80 ask_amount;
	vnx::float64_t price = 0;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xed7d8e67cb8db394ull;
	
	trade_entry_t() {}
	
	vnx::Hash64 get_type_hash() const;
	std::string get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	static std::shared_ptr<trade_entry_t> create();
	std::shared_ptr<trade_entry_t> clone() const;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code);
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const;
	
	void read(std::istream& _in);
	void write(std::ostream& _out) const;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const;
	
	vnx::Object to_object() const;
	void from_object(const vnx::Object& object);
	
	vnx::Variant get_field(const std::string& name) const;
	void set_field(const std::string& name, const vnx::Variant& value);
	
	friend std::ostream& operator<<(std::ostream& _out, const trade_entry_t& _value);
	friend std::istream& operator>>(std::istream& _in, trade_entry_t& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void trade_entry_t::accept_generic(T& _visitor) const {
	_visitor.template type_begin<trade_entry_t>(9);
	_visitor.type_field("height", 0); _visitor.accept(height);
	_visitor.type_field("time_stamp", 1); _visitor.accept(time_stamp);
	_visitor.type_field("address", 2); _visitor.accept(address);
	_visitor.type_field("txid", 3); _visitor.accept(txid);
	_visitor.type_field("bid_currency", 4); _visitor.accept(bid_currency);
	_visitor.type_field("ask_currency", 5); _visitor.accept(ask_currency);
	_visitor.type_field("bid_amount", 6); _visitor.accept(bid_amount);
	_visitor.type_field("ask_amount", 7); _visitor.accept(ask_amount);
	_visitor.type_field("price", 8); _visitor.accept(price);
	_visitor.template type_end<trade_entry_t>(9);
}


} // namespace mmx


namespace vnx {

template<>
struct is_equivalent<::mmx::trade_entry_t> {
	bool operator()(const uint16_t* code, const TypeCode* type_code);
};

} // vnx

#endif // INCLUDE_mmx_trade_entry_t_HXX_
