#include "utils.h"
#include <vector>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>

struct data convert_string_to_data(const std::string str, char delim)
{
    struct data data;
    std::vector<std::string> cont;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
    data.zi = std::stoi(cont[0]);
    data.luna = std::stoi(cont[1]);
    data.an = std::stoi(cont[2]);
    return data;
}