
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_tx_exec_result_t_HXX_
#define INCLUDE_mmx_tx_exec_result_t_HXX_

#include <vnx/Type.h>
#include <mmx/package.hxx>
#include <mmx/txin_t.hxx>
#include <mmx/txout_t.hxx>


namespace mmx {

struct MMX_EXPORT tx_exec_result_t {
	
	static const uint32_t MAX_MESSAGE_LENGTH = 128;
	
	vnx::bool_t did_fail = 0;
	uint32_t total_cost = 0;
	std::vector<::mmx::txin_t> inputs;
	std::vector<::mmx::txout_t> outputs;
	vnx::optional<std::string> message;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0xd4c88a84145b5148ull;
	
	tx_exec_result_t() {}
	
	vnx::Hash64 get_type_hash() const;
	std::string get_type_name() const;
	const vnx::TypeCode* get_type_code() const;
	
	static std::shared_ptr<tx_exec_result_t> create();
	std::shared_ptr<tx_exec_result_t> clone() const;
	
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
	
	friend std::ostream& operator<<(std::ostream& _out, const tx_exec_result_t& _value);
	friend std::istream& operator>>(std::istream& _in, tx_exec_result_t& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
};

template<typename T>
void tx_exec_result_t::accept_generic(T& _visitor) const {
	_visitor.template type_begin<tx_exec_result_t>(5);
	_visitor.type_field("did_fail", 0); _visitor.accept(did_fail);
	_visitor.type_field("total_cost", 1); _visitor.accept(total_cost);
	_visitor.type_field("inputs", 2); _visitor.accept(inputs);
	_visitor.type_field("outputs", 3); _visitor.accept(outputs);
	_visitor.type_field("message", 4); _visitor.accept(message);
	_visitor.template type_end<tx_exec_result_t>(5);
}


} // namespace mmx


namespace vnx {

template<>
struct is_equivalent<::mmx::tx_exec_result_t> {
	bool operator()(const uint16_t* code, const TypeCode* type_code);
};

} // vnx

#endif // INCLUDE_mmx_tx_exec_result_t_HXX_
