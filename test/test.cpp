#include "cashmachine.h"
#include <cassert>
#include <stdexcept>

void __compare(CashMachine& cashMachine,
            const unsigned int sum,
            unsigned int* expArrBeginPtr,
            unsigned int* expArrEndPtr);

template<typename Func>
void __throws(std::string what, Func func);

void test1();
void test2();
void test3();
void test4();


int main() {
    test1();
    test2();
    test3();
    test4();
}

void test1() {
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

void test2() {
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
}

void test3() {
    auto cashMachine = CashMachine();

    cashMachine.putStacks(
        Stack { 500, 2 },
        Stack { 50, 4 }
    );

    __throws("incorrect sum", [&]() {
        cashMachine.takeBanknotes(590);
    });
}

void test4() {
    auto cashMachine = CashMachine();

    cashMachine.putStacks(
        Stack { 100, 1 },
        Stack { 200, 3 }
    );

    __throws("out of banknotes", [&]() {
        cashMachine.takeBanknotes(800);
    });
}

void __compare(CashMachine& cashMachine, const unsigned int sum, unsigned int* expArrBeginPtr, unsigned int* expArrEndPtr) {
    const auto arrayLength = expArrEndPtr - expArrBeginPtr;
    auto listPtr = cashMachine.takeBanknotes(sum);
    auto iter = listPtr->begin();

    assert(listPtr->size() == arrayLength);

    for (int i = 0; i < arrayLength; i++, iter++) {
        auto actualDenom = *iter;
        assert(actualDenom == *(expArrBeginPtr + i));
    }
}

template<typename Func>
void __throws(std::string what, Func func) {
    std::runtime_error* err = 0;

    try {
        func();
    }
    catch (std::runtime_error& e) {
        err = &e;
    }

    assert(err && std::string(err->what()) == what);
}
