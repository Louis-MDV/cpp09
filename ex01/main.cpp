#include "RPN.hpp"

int main(int ac, char **av) {

    try {
        if (ac != 2)
            throw "invalid input.";

        std::string sstack = av[1];
        std::stack<std::string> stack;
        
        createParsedStack(&stack, sstack);
        calculation(&stack);
        std::cout << stack.top() << std::endl;
    }
    catch (const char *e) {
        std::cout << "Error: " << e << std::endl;
    }
    catch (...) {
        std::cout << "Error" << std::endl;
    }

}
