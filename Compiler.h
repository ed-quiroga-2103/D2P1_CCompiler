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

using json = nlohmann::json;
using string = std::string;

class Compiler {

private:
    Parser parser;

    mserver_client* client;

    string tokens[5] = {"int", "long", "double", "float", "char"};


public:

    SingleList<string> vals;
    SingleList<string> tags;
    SingleList<string> types;

    Compiler();

    bool checkType(string type);
    bool checkTag(string tag);
    bool checkJson(string stream);

    void allocate(string str);

};


#endif //PROYECTO1_COMPILER_H
