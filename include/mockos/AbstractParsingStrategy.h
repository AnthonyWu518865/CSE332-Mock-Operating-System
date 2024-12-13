#pragma once
#include <string>
#include <vector>
class AbstractParsingStrategy {
    virtual std:: vector<std::string> parse(std::string path) = 0;
};