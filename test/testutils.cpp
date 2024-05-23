#include "cashmachine.h"
#include <cassert>
#include <stdexcept>

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
