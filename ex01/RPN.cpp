#include "RPN.hpp"
#include <stack>
#include <string>
#include <sstream>
#include <iostream>

int calculation(std::stack<std::string> *strStack) {
    std::stack<int> intStack;

    while (strStack->size() != 1) {
        fillIntStack(strStack, &intStack);
        // std::cout << "intStack size: "<< intStack.size() << std::endl;
        std::stringstream ss;

        int remainder = -1;
        (void) remainder;
        if (intStack.size() == 3) {
            remainder = intStack.top(); intStack.pop();
            // std::cout << "num0 [" << remainder << "]\n";
            int num1 = intStack.top(); intStack.pop();
            // std::cout << "num1 (" << num1 << ") ";
            // std::cout << strStack->top()[0];
            int num2 = intStack.top(); intStack.pop();
            // std::cout << " num2 (" << num2 << ") = ";

            // If the operator is invalid or there's an issue with the stack
            if (strStack->top().empty() || strStack->top()[0] == 0) {
                std::cout << "Error: Invalid operator" << std::endl;
                return 0;
            }
            switch (strStack->top()[0]) {
                case '-':
                    ss << num1 - num2;
                    break;
                case '+':
                    ss << num1 + num2;
                    break;
                case '*':
                    ss << num1 * num2;
                    break;
                case '/':
                    ss << num1 / num2;
                    break;
                default:
                    break;
            }
        } else if (intStack.size() == 2) {

            int num0 = intStack.top(); intStack.pop();
            // std::cout << "num1 (" << num0 << ") ";
            int num1 = intStack.top(); intStack.pop();
            // std::cout << strStack->top()[0];
            // std::cout << " num0 (" << num1 << ") = ";

            // If the operator is invalid or there's an issue with the stack
            if (strStack->top().empty() || strStack->top()[0] == 0) {
                std::cout << "Error: Invalid operator" << std::endl;
                return 0;
            }
            switch (strStack->top()[0]) {
                case '-':
                    ss << num0 - num1;
                    break;
                case '+':
                    ss << num0 + num1;
                    break;
                case '*':
                    ss << num0 * num1;
                    break;
                case '/':
                    ss << num0 / num1;
                    break;
                default:
                    break;
            }
        }
        adjustAll(&ss, strStack, remainder);
    }

    return 0;
}
