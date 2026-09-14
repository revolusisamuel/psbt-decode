#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace psbtdec {

struct Account {
    int index;
    std::string label;
    std::string address;
};

struct Vault {
    std::string id;
    std::string name;
    std::vector<Account> accounts;
};

Vault create_vault(const std::string& name, const std::string& pass);
void add_account(Vault& vault, const std::string& label);
std::string coin();

}  // namespace psbtdec
