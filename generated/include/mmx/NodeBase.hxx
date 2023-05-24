
// AUTO GENERATED by vnxcppcodegen

#ifndef INCLUDE_mmx_NodeBase_HXX_
#define INCLUDE_mmx_NodeBase_HXX_

#include <mmx/package.hxx>
#include <mmx/Block.hxx>
#include <mmx/BlockHeader.hxx>
#include <mmx/ChainParams.hxx>
#include <mmx/Contract.hxx>
#include <mmx/NetworkInfo.hxx>
#include <mmx/ProofOfTime.hxx>
#include <mmx/ProofResponse.hxx>
#include <mmx/Transaction.hxx>
#include <mmx/addr_t.hpp>
#include <mmx/address_info_t.hxx>
#include <mmx/balance_t.hxx>
#include <mmx/bls_pubkey_t.hpp>
#include <mmx/exec_entry_t.hxx>
#include <mmx/exec_result_t.hxx>
#include <mmx/hash_t.hpp>
#include <mmx/offer_data_t.hxx>
#include <mmx/swap_entry_t.hxx>
#include <mmx/swap_info_t.hxx>
#include <mmx/swap_user_info_t.hxx>
#include <mmx/trade_entry_t.hxx>
#include <mmx/tx_entry_t.hxx>
#include <mmx/tx_info_t.hxx>
#include <mmx/uint128.hpp>
#include <mmx/virtual_plot_info_t.hxx>
#include <mmx/vm/varptr_t.hpp>
#include <vnx/Module.h>
#include <vnx/TopicPtr.hpp>
#include <vnx/Variant.hpp>
#include <vnx/addons/HttpData.hxx>
#include <vnx/addons/HttpRequest.hxx>
#include <vnx/addons/HttpResponse.hxx>


namespace mmx {

class MMX_EXPORT NodeBase : public ::vnx::Module {
public:
	
	::vnx::TopicPtr input_vdfs = "network.vdfs";
	::vnx::TopicPtr input_proof = "network.proof";
	::vnx::TopicPtr input_blocks = "network.blocks";
	::vnx::TopicPtr input_transactions = "network.transactions";
	::vnx::TopicPtr input_timelord_vdfs = "timelord.proofs";
	::vnx::TopicPtr input_harvester_proof = "harvester.proof";
	::vnx::TopicPtr output_verified_vdfs = "node.verified_vdfs";
	::vnx::TopicPtr output_verified_proof = "node.verified_proof";
	::vnx::TopicPtr output_verified_blocks = "node.verified_blocks";
	::vnx::TopicPtr output_verified_transactions = "node.verified_transactions";
	::vnx::TopicPtr output_committed_blocks = "node.committed_blocks";
	::vnx::TopicPtr output_transactions = "node.transactions";
	::vnx::TopicPtr output_interval_request = "timelord.requests";
	::vnx::TopicPtr output_timelord_infuse = "timelord.infuse";
	::vnx::TopicPtr output_challenges = "harvester.challenges";
	int32_t max_queue_ms = 10000;
	int32_t update_interval_ms = 1000;
	int32_t validate_interval_ms = 500;
	int32_t sync_loss_delay = 60;
	uint32_t max_history = 1000;
	uint32_t max_fork_length = 10000;
	uint32_t max_blocks_per_height = 2;
	uint32_t tx_pool_limit = 100;
	uint32_t max_sync_jobs = 64;
	uint32_t max_sync_ahead = 1000;
	uint32_t num_sync_retries = 3;
	uint32_t replay_height = -1;
	uint32_t num_threads = 24;
	uint32_t num_vdf_threads = 8;
	uint32_t vdf_check_divider = 5000;
	uint32_t vdf_verify_divider = 1;
	int32_t opencl_device = 0;
	vnx::bool_t do_sync = true;
	vnx::bool_t db_replay = false;
	vnx::bool_t show_warnings = false;
	vnx::bool_t verify_vdf_rewards = true;
	std::string storage_path;
	std::string database_path = "db/";
	std::string router_name = "Router";
	std::string timelord_name = "TimeLord";
	
	typedef ::vnx::Module Super;
	
	static const vnx::Hash64 VNX_TYPE_HASH;
	static const vnx::Hash64 VNX_CODE_HASH;
	
	static constexpr uint64_t VNX_TYPE_ID = 0x289d7651582d76a3ull;
	
	NodeBase(const std::string& _vnx_name);
	
	vnx::Hash64 get_type_hash() const override;
	std::string get_type_name() const override;
	const vnx::TypeCode* get_type_code() const override;
	
	void read(std::istream& _in) override;
	void write(std::ostream& _out) const override;
	
	template<typename T>
	void accept_generic(T& _visitor) const;
	void accept(vnx::Visitor& _visitor) const override;
	
	vnx::Object to_object() const override;
	void from_object(const vnx::Object& object) override;
	
	vnx::Variant get_field(const std::string& name) const override;
	void set_field(const std::string& name, const vnx::Variant& value) override;
	
	friend std::ostream& operator<<(std::ostream& _out, const NodeBase& _value);
	friend std::istream& operator>>(std::istream& _in, NodeBase& _value);
	
	static const vnx::TypeCode* static_get_type_code();
	static std::shared_ptr<vnx::TypeCode> static_create_type_code();
	
protected:
	using Super::handle;
	
	virtual std::shared_ptr<const ::mmx::ChainParams> get_params() const = 0;
	virtual std::shared_ptr<const ::mmx::NetworkInfo> get_network_info() const = 0;
	virtual ::mmx::hash_t get_genesis_hash() const = 0;
	virtual uint32_t get_height() const = 0;
	virtual vnx::optional<uint32_t> get_synced_height() const = 0;
	virtual std::shared_ptr<const ::mmx::Block> get_block(const ::mmx::hash_t& hash) const = 0;
	virtual std::shared_ptr<const ::mmx::Block> get_block_at(const uint32_t& height) const = 0;
	virtual std::shared_ptr<const ::mmx::BlockHeader> get_header(const ::mmx::hash_t& hash) const = 0;
	virtual std::shared_ptr<const ::mmx::BlockHeader> get_header_at(const uint32_t& height) const = 0;
	virtual vnx::optional<::mmx::hash_t> get_block_hash(const uint32_t& height) const = 0;
	virtual vnx::optional<std::pair<::mmx::hash_t, ::mmx::hash_t>> get_block_hash_ex(const uint32_t& height) const = 0;
	virtual vnx::optional<uint32_t> get_tx_height(const ::mmx::hash_t& id) const = 0;
	virtual vnx::optional<::mmx::tx_info_t> get_tx_info(const ::mmx::hash_t& id) const = 0;
	virtual vnx::optional<::mmx::tx_info_t> get_tx_info_for(std::shared_ptr<const ::mmx::Transaction> tx) const = 0;
	virtual std::vector<::mmx::hash_t> get_tx_ids_at(const uint32_t& height) const = 0;
	virtual std::vector<::mmx::hash_t> get_tx_ids_since(const uint32_t& height) const = 0;
	virtual ::mmx::exec_result_t validate(std::shared_ptr<const ::mmx::Transaction> tx) const = 0;
	virtual void add_block(std::shared_ptr<const ::mmx::Block> block) = 0;
	virtual void add_transaction(std::shared_ptr<const ::mmx::Transaction> tx, const vnx::bool_t& pre_validate) = 0;
	virtual std::shared_ptr<const ::mmx::Contract> get_contract(const ::mmx::addr_t& address) const = 0;
	virtual std::shared_ptr<const ::mmx::Contract> get_contract_for(const ::mmx::addr_t& address) const = 0;
	virtual std::vector<std::shared_ptr<const ::mmx::Contract>> get_contracts(const std::vector<::mmx::addr_t>& addresses) const = 0;
	virtual std::vector<::mmx::addr_t> get_contracts_by(const std::vector<::mmx::addr_t>& addresses, const vnx::optional<::mmx::hash_t>& type_hash) const = 0;
	virtual std::vector<::mmx::addr_t> get_contracts_owned_by(const std::vector<::mmx::addr_t>& addresses, const vnx::optional<::mmx::hash_t>& type_hash) const = 0;
	virtual std::shared_ptr<const ::mmx::Transaction> get_transaction(const ::mmx::hash_t& id, const vnx::bool_t& include_pending) const = 0;
	virtual std::vector<std::shared_ptr<const ::mmx::Transaction>> get_transactions(const std::vector<::mmx::hash_t>& ids) const = 0;
	virtual std::vector<::mmx::tx_entry_t> get_history(const std::vector<::mmx::addr_t>& addresses, const int32_t& since) const = 0;
	virtual ::mmx::uint128 get_balance(const ::mmx::addr_t& address, const ::mmx::addr_t& currency) const = 0;
	virtual std::map<::mmx::addr_t, ::mmx::uint128> get_balances(const ::mmx::addr_t& address) const = 0;
	virtual std::map<::mmx::addr_t, ::mmx::balance_t> get_contract_balances(const ::mmx::addr_t& address) const = 0;
	virtual ::mmx::uint128 get_total_balance(const std::vector<::mmx::addr_t>& addresses, const ::mmx::addr_t& currency) const = 0;
	virtual std::map<::mmx::addr_t, ::mmx::uint128> get_total_balances(const std::vector<::mmx::addr_t>& addresses) const = 0;
	virtual std::map<std::pair<::mmx::addr_t, ::mmx::addr_t>, ::mmx::uint128> get_all_balances(const std::vector<::mmx::addr_t>& addresses) const = 0;
	virtual std::vector<::mmx::exec_entry_t> get_exec_history(const ::mmx::addr_t& address, const int32_t& limit, const vnx::bool_t& recent) const = 0;
	virtual std::map<std::string, ::mmx::vm::varptr_t> read_storage(const ::mmx::addr_t& contract, const uint32_t& height) const = 0;
	virtual std::map<uint64_t, ::mmx::vm::varptr_t> dump_storage(const ::mmx::addr_t& contract, const uint32_t& height) const = 0;
	virtual ::mmx::vm::varptr_t read_storage_var(const ::mmx::addr_t& contract, const uint64_t& address, const uint32_t& height) const = 0;
	virtual std::pair<::mmx::vm::varptr_t, uint64_t> read_storage_field(const ::mmx::addr_t& contract, const std::string& name, const uint32_t& height) const = 0;
	virtual std::vector<::mmx::vm::varptr_t> read_storage_array(const ::mmx::addr_t& contract, const uint64_t& address, const uint32_t& height) const = 0;
	virtual std::map<::mmx::vm::varptr_t, ::mmx::vm::varptr_t> read_storage_map(const ::mmx::addr_t& contract, const uint64_t& address, const uint32_t& height) const = 0;
	virtual std::map<std::string, ::mmx::vm::varptr_t> read_storage_object(const ::mmx::addr_t& contract, const uint64_t& address, const uint32_t& height) const = 0;
	virtual ::vnx::Variant call_contract(const ::mmx::addr_t& address, const std::string& method, const std::vector<::vnx::Variant>& args, const vnx::optional<::mmx::addr_t>& user, const vnx::optional<std::pair<::mmx::addr_t, uint64_t>>& deposit) const = 0;
	virtual ::mmx::address_info_t get_address_info(const ::mmx::addr_t& address) const = 0;
	virtual std::vector<::mmx::address_info_t> get_address_infos(const std::vector<::mmx::addr_t>& addresses, const int32_t& since) const = 0;
	virtual std::vector<::mmx::virtual_plot_info_t> get_virtual_plots(const std::vector<::mmx::addr_t>& addresses) const = 0;
	virtual std::vector<::mmx::virtual_plot_info_t> get_virtual_plots_for(const ::mmx::bls_pubkey_t& farmer_key) const = 0;
	virtual std::vector<::mmx::virtual_plot_info_t> get_virtual_plots_owned_by(const std::vector<::mmx::addr_t>& addresses) const = 0;
	virtual uint64_t get_virtual_plot_balance(const ::mmx::addr_t& plot_id, const vnx::optional<::mmx::hash_t>& block_hash) const = 0;
	virtual ::mmx::offer_data_t get_offer(const ::mmx::addr_t& address) const = 0;
	virtual std::vector<::mmx::offer_data_t> get_offers(const uint32_t& since, const vnx::bool_t& state) const = 0;
	virtual std::vector<::mmx::offer_data_t> get_offers_by(const std::vector<::mmx::addr_t>& owners, const vnx::bool_t& state) const = 0;
	virtual std::vector<::mmx::offer_data_t> fetch_offers(const std::vector<::mmx::addr_t>& addresses, const vnx::bool_t& state, const vnx::bool_t& closed) const = 0;
	virtual std::vector<::mmx::offer_data_t> get_recent_offers(const int32_t& limit, const vnx::bool_t& state) const = 0;
	virtual std::vector<::mmx::offer_data_t> get_recent_offers_for(const vnx::optional<::mmx::addr_t>& bid, const vnx::optional<::mmx::addr_t>& ask, const int32_t& limit, const vnx::bool_t& state) const = 0;
	virtual std::vector<::mmx::trade_entry_t> get_trade_history(const int32_t& limit, const uint32_t& since) const = 0;
	virtual std::vector<::mmx::trade_entry_t> get_trade_history_for(const vnx::optional<::mmx::addr_t>& bid, const vnx::optional<::mmx::addr_t>& ask, const int32_t& limit, const uint32_t& since) const = 0;
	virtual std::vector<::mmx::swap_info_t> get_swaps(const uint32_t& since, const vnx::optional<::mmx::addr_t>& token, const vnx::optional<::mmx::addr_t>& currency) const = 0;
	virtual ::mmx::swap_info_t get_swap_info(const ::mmx::addr_t& address) const = 0;
	virtual ::mmx::swap_user_info_t get_swap_user_info(const ::mmx::addr_t& address, const ::mmx::addr_t& user) const = 0;
	virtual std::vector<::mmx::swap_entry_t> get_swap_history(const ::mmx::addr_t& address, const int32_t& limit) const = 0;
	virtual std::array<::mmx::uint128, 2> get_swap_trade_estimate(const ::mmx::addr_t& address, const uint32_t& i, const uint64_t& amount, const int32_t& num_iter) const = 0;
	virtual std::array<::mmx::uint128, 2> get_swap_fees_earned(const ::mmx::addr_t& address, const ::mmx::addr_t& user) const = 0;
	virtual std::array<::mmx::uint128, 2> get_swap_equivalent_liquidity(const ::mmx::addr_t& address, const ::mmx::addr_t& user) const = 0;
	virtual std::map<::mmx::addr_t, std::array<std::pair<::mmx::addr_t, ::mmx::uint128>, 2>> get_swap_liquidity_by(const std::vector<::mmx::addr_t>& addresses) const = 0;
	virtual ::mmx::uint128 get_total_supply(const ::mmx::addr_t& currency) const = 0;
	virtual std::vector<std::shared_ptr<const ::mmx::BlockHeader>> get_farmed_blocks(const std::vector<::mmx::bls_pubkey_t>& farmer_keys, const vnx::bool_t& full_blocks, const uint32_t& since) const = 0;
	virtual std::map<::mmx::bls_pubkey_t, uint32_t> get_farmed_block_count(const uint32_t& since) const = 0;
	virtual uint32_t get_farmed_block_count_for(const std::vector<::mmx::bls_pubkey_t>& farmer_keys, const uint32_t& since) const = 0;
	virtual void start_sync(const vnx::bool_t& force) = 0;
	virtual void revert_sync(const uint32_t& height) = 0;
	virtual void handle(std::shared_ptr<const ::mmx::Block> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::Transaction> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::ProofOfTime> _value) {}
	virtual void handle(std::shared_ptr<const ::mmx::ProofResponse> _value) {}
	virtual void http_request_async(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path, const vnx::request_id_t& _request_id) const = 0;
	void http_request_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::vnx::addons::HttpResponse>& _ret_0) const;
	virtual void http_request_chunk_async(std::shared_ptr<const ::vnx::addons::HttpRequest> request, const std::string& sub_path, const int64_t& offset, const int64_t& max_bytes, const vnx::request_id_t& _request_id) const = 0;
	void http_request_chunk_async_return(const vnx::request_id_t& _request_id, const std::shared_ptr<const ::vnx::addons::HttpData>& _ret_0) const;
	
	void vnx_handle_switch(std::shared_ptr<const vnx::Value> _value) override;
	std::shared_ptr<vnx::Value> vnx_call_switch(std::shared_ptr<const vnx::Value> _method, const vnx::request_id_t& _request_id) override;
	
};

template<typename T>
void NodeBase::accept_generic(T& _visitor) const {
	_visitor.template type_begin<NodeBase>(40);
	_visitor.type_field("input_vdfs", 0); _visitor.accept(input_vdfs);
	_visitor.type_field("input_proof", 1); _visitor.accept(input_proof);
	_visitor.type_field("input_blocks", 2); _visitor.accept(input_blocks);
	_visitor.type_field("input_transactions", 3); _visitor.accept(input_transactions);
	_visitor.type_field("input_timelord_vdfs", 4); _visitor.accept(input_timelord_vdfs);
	_visitor.type_field("input_harvester_proof", 5); _visitor.accept(input_harvester_proof);
	_visitor.type_field("output_verified_vdfs", 6); _visitor.accept(output_verified_vdfs);
	_visitor.type_field("output_verified_proof", 7); _visitor.accept(output_verified_proof);
	_visitor.type_field("output_verified_blocks", 8); _visitor.accept(output_verified_blocks);
	_visitor.type_field("output_verified_transactions", 9); _visitor.accept(output_verified_transactions);
	_visitor.type_field("output_committed_blocks", 10); _visitor.accept(output_committed_blocks);
	_visitor.type_field("output_transactions", 11); _visitor.accept(output_transactions);
	_visitor.type_field("output_interval_request", 12); _visitor.accept(output_interval_request);
	_visitor.type_field("output_timelord_infuse", 13); _visitor.accept(output_timelord_infuse);
	_visitor.type_field("output_challenges", 14); _visitor.accept(output_challenges);
	_visitor.type_field("max_queue_ms", 15); _visitor.accept(max_queue_ms);
	_visitor.type_field("update_interval_ms", 16); _visitor.accept(update_interval_ms);
	_visitor.type_field("validate_interval_ms", 17); _visitor.accept(validate_interval_ms);
	_visitor.type_field("sync_loss_delay", 18); _visitor.accept(sync_loss_delay);
	_visitor.type_field("max_history", 19); _visitor.accept(max_history);
	_visitor.type_field("max_fork_length", 20); _visitor.accept(max_fork_length);
	_visitor.type_field("max_blocks_per_height", 21); _visitor.accept(max_blocks_per_height);
	_visitor.type_field("tx_pool_limit", 22); _visitor.accept(tx_pool_limit);
	_visitor.type_field("max_sync_jobs", 23); _visitor.accept(max_sync_jobs);
	_visitor.type_field("max_sync_ahead", 24); _visitor.accept(max_sync_ahead);
	_visitor.type_field("num_sync_retries", 25); _visitor.accept(num_sync_retries);
	_visitor.type_field("replay_height", 26); _visitor.accept(replay_height);
	_visitor.type_field("num_threads", 27); _visitor.accept(num_threads);
	_visitor.type_field("num_vdf_threads", 28); _visitor.accept(num_vdf_threads);
	_visitor.type_field("vdf_check_divider", 29); _visitor.accept(vdf_check_divider);
	_visitor.type_field("vdf_verify_divider", 30); _visitor.accept(vdf_verify_divider);
	_visitor.type_field("opencl_device", 31); _visitor.accept(opencl_device);
	_visitor.type_field("do_sync", 32); _visitor.accept(do_sync);
	_visitor.type_field("db_replay", 33); _visitor.accept(db_replay);
	_visitor.type_field("show_warnings", 34); _visitor.accept(show_warnings);
	_visitor.type_field("verify_vdf_rewards", 35); _visitor.accept(verify_vdf_rewards);
	_visitor.type_field("storage_path", 36); _visitor.accept(storage_path);
	_visitor.type_field("database_path", 37); _visitor.accept(database_path);
	_visitor.type_field("router_name", 38); _visitor.accept(router_name);
	_visitor.type_field("timelord_name", 39); _visitor.accept(timelord_name);
	_visitor.template type_end<NodeBase>(40);
}


} // namespace mmx


namespace vnx {

} // vnx

#endif // INCLUDE_mmx_NodeBase_HXX_
