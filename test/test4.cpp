#include "cashmachine.h"
#include "testutils.cpp"

int main() {
    auto cashMachine = CashMachine();

    cashMachine.putStacks(
        Stack { 100, 1 },
        Stack { 200, 3 }
    );

    __throws("out of banknotes", [&]() {
        cashMachine.takeBanknotes(800);
    });

    return 0;
}
