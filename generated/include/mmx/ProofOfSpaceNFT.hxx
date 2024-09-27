
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_ProofOfSpaceNFT_HXX_
#define INCLUDE_mmx_ProofOfSpaceNFT_HXX_

#include <mmx/package.hxx>
#include <mmx/ProofOfSpace.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/hash_t.hpp>


namespace mmx {

class MMX_EXPORT ProofOfSpaceNFT : public ::mmx::ProofOfSpace {
public:
	
	uint8_t ksize = 0;
	::mmx::hash_t seed;
	std::vector<uint32_t> proof_xs;
	::mmx::addr_t contract;
	
	typedef ::mmx::ProofOfSpace Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x22a4d97166711bd9ull;
	
	ProofOfSpaceNFT() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	virtual vnx::bool_t is_valid() const override;
	virtual ::mmx::hash_t calc_hash() const override;
	virtual void validate() const override;
	
	static std::shared_ptr<ProofOfSpaceNFT> create();
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
	
	friend std::ostream& operator<<(std::ostream& _out, const ProofOfSpaceNFT& _value);
	friend std::istream& operator>>(std::istream& _in, ProofOfSpaceNFT& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method) override;
	
};

template<typename T>
void ProofOfSpaceNFT::accept_generic(T& _visitor) const {
	_visitor.template type_begin<ProofOfSpaceNFT>(7);
	_visitor.type_field("score", 0); _visitor.accept(score);
	_visitor.type_field("plot_id", 1); _visitor.accept(plot_id);
	_visitor.type_field("farmer_key", 2); _visitor.accept(farmer_key);
	_visitor.type_field("ksize", 3); _visitor.accept(ksize);
	_visitor.type_field("seed", 4); _visitor.accept(seed);
	_visitor.type_field("proof_xs", 5); _visitor.accept(proof_xs);
	_visitor.type_field("contract", 6); _visitor.accept(contract);
	_visitor.template type_end<ProofOfSpaceNFT>(7);
}


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_ProofOfSpaceNFT_HXX_
