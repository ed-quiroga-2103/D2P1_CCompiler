//
// Created by eduardo on 04/04/18.
//

#ifndef PROYECTO1_PARSER_H
#define PROYECTO1_PARSER_H

#include "string"
#include "nlohmann/json.hpp"
#include "DataStructs/DataStructures.h"
using json = nlohmann::json;
using string = std::string;

class Parser {

public:
    SingleList<string> strings;


    Parser();

    json parseLine(string line);
    SingleList<string> splitCode(string code);

};


#endif //PROYECTO1_PARSER_H
