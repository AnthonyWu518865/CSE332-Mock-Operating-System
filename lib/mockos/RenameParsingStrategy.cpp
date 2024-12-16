#include "mockos/RenameParsingStrategy.h"
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> RenameParsingStrategy::parse(std::string input) {
    std::vector <std::string> outputParse;
    std::string fileName;
    std::istringstream iss(input);
    iss >> fileName; //Extraction of the first input (file name) -> stored as fileName
    outputParse.push_back(input);
    outputParse.push_back(fileName); //Addition of the file name to the vector
    return outputParse; //Allows for the return of the full input string as well as the file name
}