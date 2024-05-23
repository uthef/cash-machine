#ifndef CASHMACHINE_H
#define CASHMACHINE_H

#include <list>
#include <memory>
#include "Stack.h"

class CashMachine {
    public:
        CashMachine();
        std::unique_ptr<std::list<unsigned int>> takeBanknotes(unsigned int sum);

        void putStacks(Stack stack);

        template<typename... Args>
        void putStacks(Stack stack, Args... args) {
            putStacks(stack);
            putStacks(args...);
        }
    private:
        std::list<Stack> _stacks;
};

#endif // CASHMACHINE_H
