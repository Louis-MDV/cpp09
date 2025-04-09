#include "BitcoinExchange.hpp"

int main (int ac, char **av) {

    (void) ac;
    try {

        std::ifstream   ifile(av[1]);
        if (ac != 2 || !ifile.is_open())
            throw "could not open file.\n";
        if (ifile.peek() == std::ifstream::traits_type::eof())
            throw "input file is empty.\n";


        std::ifstream   inputfile("data.csv");
        if (!inputfile) {
            throw "Could not open data.csv\n";
        }
        std::map<std::string, float> db = dbMapCreation();
        if (db.empty())
            throw "db empty!\n";
            
        std::string     line;
        getline(ifile, line); // skip head

        while (getline(ifile, line)) {

            if (checkFormat(line)) {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            //3. check value format 0-100 or float
            float stockNum = atof(line.substr(line.find('|') + 2).c_str());    
            if (stockNum == 0) {
                std::cout << "Error: 0 not accepted.\n";
                continue;
            }
            if (stockNum < 0) {
                std::cout << "Error: not a positive number.\n";
                continue;
            }
            if (stockNum > 1000) {
                std::cout << "Error: too large a number.\n";
                continue;
            }
            std::string date = line.substr(0, line.find('|') - 1);
            float tradeRate = getTradeRate(date, db);
            float bondValue = stockNum * tradeRate;
            std::cout << date << " => " << stockNum /* << " * " << tradeRate */ << " = " << bondValue << std::endl;
        }
        ifile.close();
    }
    catch (const char *e) {
        std::cout << RED << "Error: " << e << RESET;
    }
    catch (...) {
        std::cerr << RED << "Error: something went wrong!\n" << RESET;
    }
}
    
