
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_Block_HXX_
#define INCLUDE_mmx_Block_HXX_

#include <mmx/package.hxx>
#include <mmx/BlockHeader.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/txio_entry_t.hxx>


namespace mmx {

class MMX_EXPORT Block : public ::mmx::BlockHeader {
public:
	
	std::vector<std::shared_ptr<const ::mmx::Transaction>> tx_list;
	
	typedef ::mmx::BlockHeader Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x94965d816d328467ull;
	
	Block() {}
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	virtual void finalize();
	virtual vnx::bool_t is_valid() const override;
	virtual ::mmx::hash_t calc_tx_hash() const;
	virtual std::shared_ptr<const ::mmx::BlockHeader> get_header() const override;
	virtual std::vector<std::shared_ptr<const ::mmx::Transaction>> get_transactions() const;
	virtual std::vector<::mmx::txio_entry_t> get_inputs(std::shared_ptr<const ::mmx::ChainParams> params = nullptr) const;
	virtual std::vector<::mmx::txio_entry_t> get_outputs(std::shared_ptr<const ::mmx::ChainParams> params = nullptr) const;
	
	static std::shared_ptr<Block> create();
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
	
	friend std::ostream& operator<<(std::ostream& _out, const Block& _value);
	friend std::istream& operator>>(std::istream& _in, Block& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method) override;
	
};

template<typename T>
void Block::accept_generic(T& _visitor) const {
	_visitor.template type_begin<Block>(40);
	_visitor.type_field("version", 0); _visitor.accept(version);
	_visitor.type_field("support_flags", 1); _visitor.accept(support_flags);
	_visitor.type_field("hash", 2); _visitor.accept(hash);
	_visitor.type_field("prev", 3); _visitor.accept(prev);
	_visitor.type_field("height", 4); _visitor.accept(height);
	_visitor.type_field("vdf_height", 5); _visitor.accept(vdf_height);
	_visitor.type_field("nonce", 6); _visitor.accept(nonce);
	_visitor.type_field("time_stamp", 7); _visitor.accept(time_stamp);
	_visitor.type_field("time_diff", 8); _visitor.accept(time_diff);
	_visitor.type_field("space_diff", 9); _visitor.accept(space_diff);
	_visitor.type_field("weight", 10); _visitor.accept(weight);
	_visitor.type_field("total_weight", 11); _visitor.accept(total_weight);
	_visitor.type_field("vdf_count", 12); _visitor.accept(vdf_count);
	_visitor.type_field("vdf_iters", 13); _visitor.accept(vdf_iters);
	_visitor.type_field("vdf_output", 14); _visitor.accept(vdf_output);
	_visitor.type_field("vdf_reward_addr", 15); _visitor.accept(vdf_reward_addr);
	_visitor.type_field("vdf_reward_payout", 16); _visitor.accept(vdf_reward_payout);
	_visitor.type_field("proof", 17); _visitor.accept(proof);
	_visitor.type_field("proof_hash", 18); _visitor.accept(proof_hash);
	_visitor.type_field("challenge", 19); _visitor.accept(challenge);
	_visitor.type_field("is_space_fork", 20); _visitor.accept(is_space_fork);
	_visitor.type_field("proof_score_sum", 21); _visitor.accept(proof_score_sum);
	_visitor.type_field("proof_score_count", 22); _visitor.accept(proof_score_count);
	_visitor.type_field("reward_amount", 23); _visitor.accept(reward_amount);
	_visitor.type_field("reward_addr", 24); _visitor.accept(reward_addr);
	_visitor.type_field("reward_contract", 25); _visitor.accept(reward_contract);
	_visitor.type_field("reward_account", 26); _visitor.accept(reward_account);
	_visitor.type_field("reward_vote", 27); _visitor.accept(reward_vote);
	_visitor.type_field("reward_vote_sum", 28); _visitor.accept(reward_vote_sum);
	_visitor.type_field("reward_vote_count", 29); _visitor.accept(reward_vote_count);
	_visitor.type_field("base_reward", 30); _visitor.accept(base_reward);
	_visitor.type_field("static_cost", 31); _visitor.accept(static_cost);
	_visitor.type_field("total_cost", 32); _visitor.accept(total_cost);
	_visitor.type_field("tx_count", 33); _visitor.accept(tx_count);
	_visitor.type_field("tx_fees", 34); _visitor.accept(tx_fees);
	_visitor.type_field("txfee_buffer", 35); _visitor.accept(txfee_buffer);
	_visitor.type_field("tx_hash", 36); _visitor.accept(tx_hash);
	_visitor.type_field("farmer_sig", 37); _visitor.accept(farmer_sig);
	_visitor.type_field("content_hash", 38); _visitor.accept(content_hash);
	_visitor.type_field("tx_list", 39); _visitor.accept(tx_list);
	_visitor.template type_end<Block>(40);
}


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_Block_HXX_
