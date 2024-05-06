#include "cashmachine.h"
#include <stdexcept>

using std::list, std::unique_ptr, std::make_unique;

CashMachine::CashMachine() {

}

void CashMachine::putStacks(Stack stack) {
    if (stack.denom == 0) throw std::runtime_error("denomination must be greater than 0");

    auto iter = _stacks.begin();

    while (iter != _stacks.end()) {
        Stack& i = *iter;

        if (stack.denom > i.denom) {
            break;
        }
        else if (stack.denom == i.denom) {
            i.count += stack.count;
            return;
        }

        iter++;
    }

    _stacks.emplace(iter, stack);
}

unique_ptr<list<unsigned int>> CashMachine::takeBanknotes(unsigned int sum) {
    if (_stacks.empty()) {
        throw std::runtime_error("out of banknotes");
    }

    const auto lowestDenom = _stacks.back().denom;

    if (sum < lowestDenom || sum % lowestDenom != 0) {
        throw std::runtime_error("incorrect sum");
    }

    auto banknotes = make_unique<list<unsigned int>>();
    auto remSum = sum;

    for (auto& stack : _stacks) {
        if (remSum < stack.denom || stack.count == 0) continue;

        int count = remSum / stack.denom;
        if (count > stack.count) count = stack.count;

        stack.count -= count;
        remSum -= count * stack.denom;

        for (size_t i = 0; i < count; i++) {
            banknotes->push_back(stack.denom);
        }
    }

    if (remSum > 0) {
        throw std::runtime_error("out of banknotes");
    }

    return banknotes;
}
