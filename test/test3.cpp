#include "cashmachine.h"
#include "testutils.cpp"

int main() {
    auto cashMachine = CashMachine();

    cashMachine.putStacks(
        Stack { 500, 2 },
        Stack { 50, 4 }
    );

    __throws("incorrect sum", [&]() {
        cashMachine.takeBanknotes(590);
    });

    return 0;
}
