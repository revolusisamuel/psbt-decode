#include "psbt-decode/wallet.h"

#include <iostream>

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            std::cerr << "fail: " #cond "\n";                                \
            return 1;                                                        \
        }                                                                    \
    } while (0)

int main() {
    auto v = psbtdec::create_vault("test", "pw");
    CHECK(v.name == "test");
    CHECK(v.accounts.size() == 1);
    psbtdec::add_account(v, "A");
    psbtdec::add_account(v, "B");
    CHECK(v.accounts.size() == 3);
    CHECK(v.accounts[0].address != v.accounts[1].address);
    CHECK(!psbtdec::coin().empty());
    std::cout << "ok\n";
    return 0;
}
