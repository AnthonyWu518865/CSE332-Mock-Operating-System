#include "mockos/RenameParsingStrategy.h"
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> RenameParsingStrategy::parse(std::string input) {
    std::vector <std::string> outputParse;
    std::string fileName, newFileName;
    std::istringstream iss(input);
    iss >> fileName;
    outputParse.push_back(input);
    outputParse.push_back(fileName);

    return outputParse;
}