//
// Created by eduardo on 09/04/18.
//

#ifndef PROYECTO1_COMPILER_H
#define PROYECTO1_COMPILER_H

#include "Parser.h"
#include "string"
#include<stdio.h>
#include "nlohmann/json.hpp"
#include "mserver_client.h"
#include "Logger.h"

using json = nlohmann::json;
using string = std::string;

class Compiler {

private:
    Parser parser;
    Logger log;
    mserver_client* client;
    int line = 0;

    string tokens[5] = {"int", "long", "double", "float", "char"};


public:

    SingleList<string> vals;
    SingleList<string> tags;
    SingleList<string> types;

    Compiler();

    bool checkType(string type);
    bool checkTag(string tag);
    bool checkForOp(json j);

    string checkJson(string stream);

    string allocate(string str);
    string pull();

};


#endif //PROYECTO1_COMPILER_H
