#include "mockos/RenameParsingStrategy.h"
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> RenameParsingStrategy::parse(std::string input) {
    std::vector <std::string> outputParse;

    std::string fileName, newFileName;
    std::istringstream iss(input);
    iss >> fileName >> newFileName;

    std::string parsedFileName = fileName + " " + newFileName;
    outputParse.push_back(parsedFileName);
    outputParse.push_back(fileName);

    return outputParse;
}