#include "cashmachine.h"
#include "testutils.cpp"

int main() {
    auto cashMachine = CashMachine();

    cashMachine.putStacks(
        Stack { 200, 1 },
        Stack { 100, 4 },
        Stack { 100, 1 },
        Stack { 2000, 1 },
        Stack { 1000, 5 }
    );

    unsigned int expectedDenoms[] = {
        2000, 1000, 1000, 1000, 200, 100, 100, 100, 100, 100
    };

    __compare(cashMachine, 5700, std::begin(expectedDenoms), std::end(expectedDenoms));
}

