
const FRACT_BITS = 64;
const LOCK_DURATION = 8640;	// 24 hours

const fee_rates = [
	1844674407370955,		// 0.0001
	3689348814741910,		// 0.0002
	9223372036854776,		// 0.0005
	18446744073709552,		// 0.001
	36893488147419103,		// 0.002
	92233720368547758,		// 0.005
	184467440737095516,		// 0.01
	368934881474191032,		// 0.02
	922337203685477581,		// 0.05
	1844674407370955162		// 0.1
];

var state = [];
var tokens = [];
var volume = [0, 0];
var users = {};

function init(token, currency)
{
	push(tokens, bech32(token));
	push(tokens, bech32(currency));
	
	for(var j = 0; j < size(fee_rates); ++j) {
		var out = {};
		out.balance = [0, 0];
		out.user_total = [0, 0];
		out.fees_paid = [0, 0];
		out.fees_claimed = [0, 0];
		push(state, out);
	}
}

function _get_earned_fees(user) const
{
	const entry = state[user.pool_idx];
	
	const user_share = [0, 0];
	for(var i = 0; i < 2; ++i) {
		if(user.balance[i] > 0) {
			const total_fees = entry.fees_paid[i] - user.last_fees_paid[i];
			if(total_fees > 0) {
				user_share[i] = min(
						(2 * total_fees * user.balance[i]) /
						(entry.user_total[i] + user.last_user_total[i]),
						entry.fees_paid[i] - entry.fees_claimed[i]);
			}
		}
	}
	return user_share;
}

function get_earned_fees(address) const public
{
	const user = users[bech32(address)];
	if(user == null) {
		fail("no such user", 2);
	}
	return _get_earned_fees(user);
}

function _payout(user)
{
	const entry = state[user.pool_idx];
	const user_share = _get_earned_fees(user);
	
	for(var i = 0; i < 2; ++i) {
		const amount = user_share[i];
		if(amount > 0) {
			entry.fees_claimed[i] += amount;
			send(this.user, amount, tokens[i]);
		}
		user.last_fees_paid[i] = entry.fees_paid[i];
	}
	return user_share;
}

function payout() public
{
	const user = users[this.user];
	if(user == null) {
		fail("no such user", 2);
	}
	return _payout(user);
}

function _disable(user)
{
	_payout(user);
	
	const entry = state[user.pool_idx];
	
	const user_sum = user.balance[0] + user.balance[1];
	const pool_sum = entry.balance[0] + entry.balance[1];
	const user_ratio = (user_sum << FRACT_BITS) / pool_sum;
	
	for(var i = 0; i < 2; ++i) {
		const amount = (entry.balance[i] * user_ratio) >> FRACT_BITS;
		
		entry.balance[i] -= amount;
		entry.user_total[i] -= user.balance[i];
		
		user.balance[i] = amount;
	}
	user.pool_idx = null;
	
	return user.balance;
}

function disable() public
{
	var user = users[this.user];
	if(user == null) {
		return;
	}
	if(user.pool_idx == null) {
		return;
	}
	return _disable(user);
}

function _activate(user, pool_idx)
{
	if(user.pool_idx != null) {
		fail("already activated", 9);
	}
	const total_balance = get_total_balance();
	
	const amount = [0, 0];
	const balance = user.balance;
	
	if(total_balance[0] > 0 && total_balance[1] > 0)
	{
		const price = (total_balance[0] << FRACT_BITS) / (total_balance[1]);
		
		amount[0] = (balance[1] * price) >> FRACT_BITS;
		
		if(amount[0] <= balance[0]) {
			amount[1] = balance[1];
		} else {
			amount[0] = balance[0];
			amount[1] = (balance[0] << FRACT_BITS) / price;
		}
	}
	else {
		amount[0] = balance[0];
		amount[1] = balance[1];
	}
	const entry = state[pool_idx];
	
	if(entry == null) {
		fail("invalid pool_idx", 8);
	}
	
	for(var i = 0; i < 2; ++i) {
		total_balance[i] += amount[i];
		entry.balance[i] += amount[i];
		entry.user_total[i] += amount[i];
		
		user.last_fees_paid[i] = entry.fees_paid[i];
	}
	const amount_left = [0, 0];
	
	for(var i = 0; i < 2; ++i) {
		amount_left[i] = balance[i] - amount[i];
		balance[i] = amount[i];
	}
	
	for(var i = 0; i < 2; ++i) {
		const half_amount = amount_left[i] / 2;
		if(half_amount > 0) {
			const k = (i + 1) % 2;
			const trade_amount = _trade(i, half_amount)[0];
			
			balance[i] += half_amount;
			balance[k] += trade_amount;
			entry.balance[i] += half_amount;
			entry.balance[k] += trade_amount;
			entry.user_total[i] += half_amount;
			entry.user_total[k] += trade_amount;
		}
	}
	
	for(var i = 0; i < 2; ++i) {
		user.last_user_total[i] = entry.user_total[i];
	}
	user.pool_idx = pool_idx;
	
	return balance;
}

function activate(pool_idx) public
{
	var user = users[this.user];
	if(user == null) {
		fail("no such user", 2);
	}
	return _activate(user, pool_idx);
}

function add_liquid(i) public payable
{
	if(this.deposit.currency != tokens[i]) {
		fail("currency mismatch", 1);
	}
	
	var user = users[this.user];
	if(user == null) {
		user = {};
		user.pool_idx = null;
		user.balance = [0, 0];
		user.last_fees_paid = [0, 0];
		user.last_user_total = [0, 0];
		users[this.user] = user;
	} else {
		if(user.pool_idx != null) {
			fail("already activated", 9);
		}
	}
	user.balance[i] += this.deposit.amount;
}

function _rem_liquid(user, i, amount, do_send = true)
{
	const k = (i + 1) % 2;
	const entry = state[user.pool_idx];
	
	var ret_amount = (amount * entry.balance[i]) / entry.user_total[i];
	var trade_amount = 0;
	
	if(entry.balance[i] < entry.user_total[i]) {
		if(entry.balance[k] > entry.user_total[k]) {
			// token k was bought
			trade_amount = ((entry.balance[k] - entry.user_total[k]) * amount) / entry.user_total[i];
		}
	} else if(entry.balance[k] < entry.user_total[k]) {
		// no trade happened
		ret_amount = amount;
	}
	
	if(ret_amount > 0) {
		if(do_send) {
			send(this.user, ret_amount, tokens[i]);
		}
		entry.balance[i] -= ret_amount;
	}
	if(trade_amount > 0) {
		if(do_send) {
			send(this.user, trade_amount, tokens[k]);
		}
		entry.balance[k] -= trade_amount;
	}
	user.balance[i] -= amount;
	entry.user_total[i] -= amount;
	
	var out = [0, 0];
	out[i] = ret_amount;
	out[k] = trade_amount;
	return out;
}

function rem_liquid(i, amount) public
{
	if(amount == 0) {
		fail("amount == 0");
	}
	const user = users[this.user];
	if(user == null) {
		fail("no such user", 2);
	}
	if(!dry_run) {
		if(this.height < user.unlock_height) {
			fail("liquidity still locked", 3);
		}
	}
	if(amount > user.balance[i]) {
		fail("amount > user balance", 4);
	}
	return _rem_liquid(user, i, amount, !dry_run);
}

function rem_all_liquid(dry_run = false) public
{
	const user = users[this.user];
	if(user == null) {
		fail("no such user", 2);
	}
	_payout(user);
	
	var out = [0, 0];
	for(var i = 0; i < 2; ++i) {
		const amount = user.balance[i];
		if(amount > 0) {
			const ret = rem_liquid(i, amount, dry_run);
			for(var k = 0; k < 2; ++k) {
				out[k] += ret[k];
			}
		}
	}
	return out;
}

function switch_pool(pool_idx) public
{
	const user = users[this.user];
	if(user == null) {
		fail("no such user", 2);
	}
	_disable(user);
	_activate(user, pool_idx);
	
	return user.balance;
}

function get_total_balance() public const
{
	var total = [0, 0];
	for(const entry of state) {
		total[0] += entry.balance[0];
		total[1] += entry.balance[1];
	}
	return total;
}

function trade(i, address, min_amount) public payable
{
	if(this.deposit.currency != tokens[i]) {
		fail("currency mismatch", 1);
	}
	const total_balance = get_total_balance();
	
	const k = (i + 1) % 2;
	if(total_balance[k] == 0) {
		fail("liquidity pool is empty", 5);
	}
	const amount = this.deposit.amount;

	const price = (total_balance[k] << FRACT_BITS) / (total_balance[i] + amount);
	
	const trade_amount = (amount * price) >> FRACT_BITS;
	
	var out = [0, 0];
	var actual_amount = 0;
	var amount_left = amount;
	var trade_amount_left = trade_amount;
	
	for(var j = 0; j < size(state) && trade_amount_left > 0; ++j)
	{
		const entry = state[j];
		
		if(entry.balance[k] > 0) {
			const pool_trade_amount = min(trade_amount_left, entry.balance[k]);
			
			var pool_amount = 0;
			if(pool_trade_amount < trade_amount_left) {
				pool_amount = min((pool_trade_amount << FRACT_BITS) / price, amount_left);
			} else {
				pool_amount = amount_left;
			}
			
			const fee_amount = min(1 + ((pool_trade_amount * fee_rates[j]) >> FRACT_BITS), pool_trade_amount);
			actual_amount += pool_trade_amount - fee_amount;
			
			out[0] += pool_trade_amount;
			out[1] += fee_amount;
			
			entry.balance[i] += pool_amount;
			entry.balance[k] -= pool_trade_amount;
			entry.fees_paid[k] += fee_amount;
			
			amount_left -= pool_amount;
			trade_amount_left -= pool_trade_amount;
		}
	}
	
	if(min_amount != null) {
		if(actual_amount < min_amount) {
			fail("minimum amount not reached", 7);
		}
	}
	send(bech32(address), actual_amount, tokens[k]);
	
	volume[k] += trade_amount;
	
	return out;
}

