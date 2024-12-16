//
// Created by Anthony Wu on 12/15/24.
//

#include "mockos/MacroParsingStrategy.h"
#include "mockos/MetadataDisplayVisitor.h"
#include <sstream>


vector<string> MacroParsingStrategy::parse(string input) {
    vector<string> tokens;
    stringstream ss(input);
    string s;
    while(getline(ss, s, '|')) {
        tokens.push_back(s);
    }
    return tokens;
}