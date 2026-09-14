#include "psbt-decode/wallet.h"

#include <iomanip>
#include <sstream>

namespace psbtdec {

namespace {

std::uint64_t mix(std::uint64_t state, std::uint8_t b, std::size_t i) {
    return state * 0x100000001b3ull + b + static_cast<std::uint64_t>(i);
}

std::string hex8(std::uint64_t n) {
    std::ostringstream o;
    o << std::hex << std::setw(16) << std::setfill('0') << n;
    return o.str();
}

std::uint64_t digest(const std::string& s) {
    std::uint64_t state = 0x9e3779b97f4a7c15ull;
    for (std::size_t i = 0; i < s.size(); ++i) {
        state = mix(state, static_cast<std::uint8_t>(s[i]), i);
    }
    return state;
}

std::string address(int index, const std::string& name) {
    return std::string("bc1q") + hex8(digest(name + std::to_string(index) + "m/84'/0'/0'"));
}

}  // namespace

Vault create_vault(const std::string& name, const std::string& pass) {
    Vault v;
    v.id = hex8(digest(name + pass)).substr(0, 16);
    v.name = name;
    v.accounts.push_back(Account{0, "Primary", address(0, name)});
    return v;
}

void add_account(Vault& vault, const std::string& label) {
    int index = static_cast<int>(vault.accounts.size());
    vault.accounts.push_back(Account{index, label, address(index, vault.name)});
}

const char* coin_tag = "BTC";
std::string coin() { return coin_tag; }

}  // namespace psbtdec
