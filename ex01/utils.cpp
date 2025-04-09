#include "RPN.hpp"

bool isign(char c) {
    return c == '+' || c == '-' || c == '/' || c == '*';
}

void createParsedStack(std::stack<std::string>* stack, std::string input) {

    int i = 0;
    int len = input.size();
    // std::cout << len << std::endl;
    while (i < len && input[i] ) {
        if (i > 0 && isdigit(input[i]) && isdigit(input[i+2]) && isign(input[i+4]) && isign(input[i+6])) {
            // std::cout << "d d s s: " << i << "\n";

            if (i+6 < len && isdigit(input[i+6])) {
                i+=8;
                // std::cout << input[i] << std::endl;
            }
            else {
                i+=8;
                // std::cout << input[i] << std::endl;
            }
        }
        else if (isdigit(input[i]) && isdigit(input[i+2]) && isign(input[i+4])) {
            // std::cout << "d d s: "<< i << "\n";

            if (i+6 < len && !isign(input[i+6])) {
                i+=6;
                // std::cout << input[i] << std::endl;
            }
            else {
                i+=5; // so i == len which is exit condition
                // std::cout << input[i] << std::endl;
            }
        }
        else if (isdigit(input[i]) && isdigit(input[i+2]) && isdigit(input[i+4])
            && isign(input[i+6]) && isign(input[i+8])) {
            // std::cout << "d d d s s: " << i << "\n";

            if (i+10 < len && !isign(input[i+10])) {
                i+=10;
                // std::cout << input[i] << std::endl;
            }
            else {
                i+=9;
                // std::cout << input[i] << std::endl;
            }
        }
        else if (isdigit(input[i]) && isign(input[i+2])) {
            // std::cout << "d s :" << i << "\n";

            if (i+4 < len && isdigit(input[i+4])) {
                i+=4;
                // std::cout << input[i] << std::endl;
            }
            else {
                i+=3;
                // std::cout << input[i] << std::endl;
            }
        }
        else
            throw 1;
    }
    int y = input.size() - 1;
    while(y >= 0) {
        // std::cout << input[y] <<std::endl;
        stack->push(std::string(1, input[y]));
        y-=2;
    }
}

// Function to adjust the stack after calculation
void adjustAll(std::stringstream *ss, std::stack<std::string> *strStack, int remainder) {

    std::ostringstream oss;
    oss << remainder;
    std::string tmp = oss.str();

    strStack->pop(); //remove sign used for last calculation
    strStack->push(ss->str()); //push result to remaining stack
    if (remainder != -1) {
        strStack->push(tmp); //if 3 num calul push 3rd num to stack
    }
    ss->str(""); // Clear the stringstream
    ss->clear(); // Clear the state flags
}

// Cut nums from stack to stack
void fillIntStack(std::stack<std::string> *strStack, std::stack<int> *intStack) {
    // Temporary stack to reverse the order
    std::stack<int> tmpStack;

    // Cutting 2 top digits from inputStack to tempStack
    for (int i = 0; i < 2; ++i) {
        tmpStack.push(atoi(strStack->top().c_str()));
        strStack->pop(); // Remove copied digits from inputStack
    }

    // Check if inputStack's next element is a sign, if not cut to tempStack
    if (!strStack->empty() && !strStack->top().empty() && isdigit((strStack->top())[0])) {
        tmpStack.push(atoi(strStack->top().c_str()));
        strStack->pop();
    }

    // Transfer elements from tempStack to outputStack to maintain the original order
    while (!tmpStack.empty()) {
        intStack->push(tmpStack.top());
        tmpStack.pop();
    }
    // while (!intStack->empty()) {
    //     std::cout << intStack->top() << std::endl;
    //     intStack->pop();
    // }
}
