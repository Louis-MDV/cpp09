#include "PmergeMe.hpp"

void printVector(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

bool isnum(const char *str) {
    if (!str)
        return false; // Check for null pointer
    int i = 0;
    while (str[i]) {
        if (!isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}