#pragma once
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iostream>
#include "../Colors.hpp"

// void fillVec(std::stack<std::string> *stack, std::vector<int> *vec);
int  calculation(std::stack<std::string> *stack);
void adjustAll(std::stringstream *ss, std::stack<std::string> *strStack, int reste);
void createParsedStack(std::stack<std::string> *stack, std::string sstack);
void fillIntStack(std::stack<std::string> *inputStack, std::stack<int> *outputStack);
