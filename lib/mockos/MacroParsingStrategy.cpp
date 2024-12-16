//
// Created by Anthony Wu on 12/15/24.
//

#include "mockos/MacroParsingStrategy.h"
#include "mockos/MetadataDisplayVisitor.h"
#include <sstream>

vector<string> MacroParsingStrategy::parse(string input) {
    vector<std::string> output;
    stringstream iss(input);
    std::string s;
    std::string secondOption;
    iss >> s;
    iss >> secondOption;
    if (secondOption == "-p") { //Checks for password protection
        output.push_back(s + " " + secondOption);
        std::string thirdOption;
        iss >> thirdOption;
        if (thirdOption == "-m") { //Checks for meta display option
            output.push_back(thirdOption);
        }
        else {
            output.push_back("");
        }
    }
    else {
        output.push_back(s);
        if (secondOption == "-m") {
            output.push_back(secondOption);
        }
        else {
            output.push_back("");
        }
    }
    return output;
}