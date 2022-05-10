/*
 * Executable.cpp
 *
 *  Created on: May 10, 2022
 *      Author: mad
 */

#include <mmx/contract/Executable.hxx>
#include <mmx/write_bytes.h>


namespace mmx {
namespace contract {

bool Executable::is_valid() const
{
	for(const auto& entry : methods) {
		const auto& method = entry.second;
		if(method.is_payable && method.is_const) {
			return false;
		}
	}
	return Super::is_valid();
}

hash_t Executable::calc_hash() const
{
	std::vector<uint8_t> buffer;
	vnx::VectorOutputStream stream(&buffer);
	vnx::OutputBuffer out(&stream);

	write_bytes(out, get_type_hash());
	write_field(out, "version", 	version);
	write_field(out, "name", 		name);
	write_field(out, "symbol", 		symbol);
	write_field(out, "web_url", 	web_url);
	write_field(out, "icon_url", 	icon_url);
	write_field(out, "decimals", 	decimals);
	write_field(out, "fields", 		fields);
	write_field(out, "methods", 	methods);
	write_field(out, "constant", 	constant);
	write_field(out, "binary", 		binary);
	write_field(out, "source", 		source);
	write_field(out, "init_method", init_method);
	write_field(out, "init_args", 	init_args);
	out.flush();

	return hash_t(buffer);
}

uint64_t Executable::calc_cost(std::shared_ptr<const ChainParams> params) const
{
	uint64_t payload = 0;
	for(const auto& entry : fields) {
		payload += entry.first.size();
	}
	for(const auto& entry : methods) {
		const auto& method = entry.second;
		for(const auto& entry : method.args) {
			payload += entry.size();
		}
		payload += entry.first.size() + method.name.size() + method.info.size();
	}
	payload += constant.size() + binary.size() + init_method.size();

	for(const auto& arg : init_args) {
		payload += arg.size();
	}
	return Super::calc_cost(params) + payload * params->min_txfee_byte;
}


} // contract
} // mmx
