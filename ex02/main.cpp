#include "PmergeMe.hpp"
#include <sstream>

int main(int ac, char **av) {

    try {
        if (ac < 2) {
            throw "wrong input format.\n";
        }
        
        std::vector<int> vec;
        std::deque<int> dq;
        for (int i = 1; i < ac; ++i) {
            std::istringstream iss(av[i]);
            int num;
            if (!(iss >> num)) {
                throw "Invalid input: must be integers.\n";
            }
            if (num >= 0) {
                vec.push_back(num);
                dq.push_back(num);
            } else {
                throw "Only accepts positive integers.\n";
            }
        }
        
        int n = vec.size();

        std::cout << "Before :  ";
        printVector(vec);

        clock_t start = clock();
        mergeInsertionSort(vec, 0, n - 1);
        clock_t end = clock();
        double vecTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0; //time in ms

        start = clock();
        mergeInsertionSort(dq, 0, n - 1);
        end = clock();
        double dqTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0; //time in ms

        
        std::cout << "After :   ";
        printVector(vec);
        std::cout << "Time to process a range of " << (ac - 1) << " elements with std::vector : " << vecTime << "\n" ;
        std::cout << "Time to process a range of " << (ac - 1) << " elements with std::deque : " << dqTime << "\n" ;

        return 0;
    
    } catch (const char *e) {

        std::cout << RED << "Error: " << e << RESET;
    } catch (...) {

        std::cerr << RED << "Error: something went wrong!\n" << RESET;
    }
}
