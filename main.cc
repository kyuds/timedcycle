#include <iostream>
#include "timedcycle.h"

class Example : public TimedCycle {
    public:
        Example() : TimedCycle(2000) {}
        ~Example() {}

        void task() override {
            std::cout << "Executed!\n";
        }
};

int main(void) {
    Example * e = new Example();

    // execute + potentially delay 5 times
    for (int i = 0; i < 5; i++) {
        std::cin.get();
        e->reset();
    }

    // delete. Thread is dead now.
    delete e;
    std::cout << "dead" << std::endl;

    // nothing should be printed now.
    while (true) {}

    return 0;
}
