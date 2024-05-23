#include "cashmachine.h"
#include "testutils.cpp"

int main() {
    auto cashMachine = CashMachine();

    cashMachine.putStacks(
        Stack { 5000, 2 },
        Stack { 100, 3 },
        Stack { 500, 1 },
        Stack { 200, 2 },
        Stack { 3000, 6 },
        Stack { 1000, 1 }
    );

    unsigned int expectedDenoms[] = {
        1000, 500, 200, 200, 100, 100, 100
    };

    __compare(cashMachine, 2200, std::begin(expectedDenoms), std::end(expectedDenoms));

    return 0;
}
