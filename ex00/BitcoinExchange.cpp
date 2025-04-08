#include "BitcoinExchange.hpp"

//database to map: date | tradeRate
std::map<std::string, float> dbMapCreation() {

    std::map<std::string, float>    db;
    std::ifstream   inputfile("data.csv");
    if (!inputfile) {
        std::cerr << "Error: Could not open data.csv" << std::endl;
        return db;
    }
    std::string line;
    getline(inputfile, line); //skip first line
    while (getline(inputfile, line)) {

        std::string date = line.substr(0, 10);
        float tradeRate = std::stof(line.substr(11));
        db.insert(std::make_pair(date, tradeRate));
    }
    inputfile.close();
    return db;
}

float getTradeRate(std::string date, std::map<std::string, float> db) {

    std::map<std::string, float>::iterator it = db.begin();

    try {
        if (db.empty())
            throw "db empty!";
        for (it = db.begin(); it != db.end(); ++it) {
            if (it->first == date)
                return (it->second);
            else if (it->first > date) { 
                --it;
                return (it->second);
            }
        }
    }
    catch (const char *e) {
        std::cout << RED << "Error:getTradeRate: " << e << RESET << std::endl;
    }
    return (it->second);
}

//1. check "date | valeur" format
int checkFormat(std::string line) {

    //2. check date format "YYYY-MM-DD"
    int year = std::atoi(line.substr(0, 4).c_str());
    if (year == 0)
        return 1;
    int month = std::atoi(line.substr(5, 2).c_str());
    if (month == 0)
        return 1;
    int day = std::atoi(line.substr(8, 2).c_str());
    if (day == 0)
        return 1;

    if ((year < 1 || year > 2025)
        || (month < 1 || month > 12)
        || (day < 1 || day > 31)) {
            return 1;
    }
    if (line.compare(10, 3, " | ") != 0)
        return 1;

    //3. check value format 0-100 or float
    float stockNum = atof(line.substr(line.find('|') + 2).c_str());    
    if (stockNum == 0)
        return 1;

    return 0;
}
