//
// Created by Anthony Wu on 12/15/24.
//

#pragma once
#include "AbstractParsingStrategy.h"
using namespace std;
class MacroParsingStrategy : public AbstractParsingStrategy {
    public:
    virtual vector<string> parse(std::string) override;
};



