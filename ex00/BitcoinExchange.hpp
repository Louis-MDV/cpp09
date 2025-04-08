#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "../Colors.hpp"

int checkFormat(std::string line);
std::map<std::string, float> dbMapCreation();
float getTradeRate(std::string date, std::map<std::string, float> db);
