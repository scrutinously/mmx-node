
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_Wallet_send_HXX_
#define INCLUDE_mmx_Wallet_send_HXX_

#include <mmx/package.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/spend_options_t.hxx>
#include <mmx/uint80.hpp>
#include <vnx/Value.h>


namespace mmx {

class MMX_EXPORT Wallet_send : public ::vnx::Value {
public:
	
	uint32_t index = 0;
	::mmx::uint80 amount;
	::mmx::addr_t dst_addr;
	::mmx::addr_t currency;
	::mmx::spend_options_t options;
	
	typedef ::vnx::Value Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x3842658ae3c2d5ebull;
	
	Wallet_send() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	static std::shared_ptr<Wallet_send> create();
	std::shared_ptr<vnx::Value> clone() const override;
	
	void read(vnx::TypeInput& _in, const vnx::TypeCode* _type_code, const uint16_t* _code) override;
	void write(vnx::TypeOutput& _out, const vnx::TypeCode* _type_code, const uint16_t* _code) const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const Wallet_send& _value);
	friend std::istream& operator>>(std::istream& _in, Wallet_send& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void Wallet_send::accept_generic(T& _visitor) const {
	_visitor.template type_begin<Wallet_send>(5);
	_visitor.type_field("index", 0); _visitor.accept(index);
	_visitor.type_field("amount", 1); _visitor.accept(amount);
	_visitor.type_field("dst_addr", 2); _visitor.accept(dst_addr);
	_visitor.type_field("currency", 3); _visitor.accept(currency);
	_visitor.type_field("options", 4); _visitor.accept(options);
	_visitor.template type_end<Wallet_send>(5);
}


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_Wallet_send_HXX_
