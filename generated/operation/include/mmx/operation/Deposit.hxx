
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_operation_Deposit_HXX_
#define INCLUDE_mmx_operation_Deposit_HXX_

#include <mmx/operation/package.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>
#include <mmx/operation/Execute.hxx>


namespace mmx {
namespace operation {

class MMX_OPERATION_EXPORT Deposit : public ::mmx::operation::Execute {
public:
	
	::mmx::addr_t currency;
	uint64_t amount = 0;
	vnx::optional<::mmx::addr_t> sender;
	
	typedef ::mmx::operation::Execute Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xc23408cb7b04b0ecull;
	
	Deposit() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	virtual vnx::bool_t is_valid() const override;
	virtual ::mmx::hash_t calc_hash() const override;
	
	static std::shared_ptr<Deposit> create();
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
	
	friend std::ostream& operator<<(std::ostream& _out, const Deposit& _value);
	friend std::istream& operator>>(std::istream& _in, Deposit& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method) override;
	
};

template<typename T>
void Deposit::accept_generic(T& _visitor) const {
	_visitor.template type_begin<Deposit>(9);
	_visitor.type_field("version", 0); _visitor.accept(version);
	_visitor.type_field("address", 1); _visitor.accept(address);
	_visitor.type_field("solution", 2); _visitor.accept(solution);
	_visitor.type_field("user", 3); _visitor.accept(user);
	_visitor.type_field("method", 4); _visitor.accept(method);
	_visitor.type_field("args", 5); _visitor.accept(args);
	_visitor.type_field("currency", 6); _visitor.accept(currency);
	_visitor.type_field("amount", 7); _visitor.accept(amount);
	_visitor.type_field("sender", 8); _visitor.accept(sender);
	_visitor.template type_end<Deposit>(9);
}


} // namespace mmx
} // namespace operation


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_operation_Deposit_HXX_
