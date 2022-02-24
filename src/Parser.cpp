#include <algorithm>
#include <sstream>
#include <iterator>
#include <fstream>
#include <iostream>
#include <vector>

#include "Parser.hpp"

std::vector<std::string> Parser::getArgs(std::string &line)
{
    std::replace(line.begin(), line.end(), ',', ' ');
    auto iss = std::istringstream(line);
    std::vector<std::string> args = std::vector<std::string> (
        std::istream_iterator<std::string>(iss),
        std::istream_iterator<std::string>()
    );
    if (!iss && !iss.eof()) {
        throw "Error parsing args";
    }

    return args;
}