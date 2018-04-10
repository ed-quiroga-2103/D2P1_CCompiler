//
// Created by eduardo on 04/04/18.
//

#include "Parser.h"
#include "string"
#include <iostream>
#include "DataStructs/DataStructures.h"
#include "nlohmann/json.hpp"

using string = std::string;
using json = nlohmann::json;


Parser::Parser() {}

json Parser::parseLine(string line) {

    json j;

    string currentln = "";

    int count = 0;

    for(int i = 0; i < line.length(); i++){

        string cmp = " ";
        string col = ";";

        if(line[i] == col[0]){

            j[count] = currentln;
            count++;

            j[count] = ";";
            currentln = "";
            count++;

        }
        else if(!(line[i] == cmp[0])){

            string copy;
            copy = line[i];
            currentln.append(copy);

        }
        else{

            j[count] = currentln;
            currentln = "";
            count++;

        }

    }

    for(int i = 0; i < j.size(); i++){

        std::cout << j[i] << std::endl;

    }

    return j;

}

SingleList<string> Parser::splitCode(string code){

    string current = "";

    for(int i = 0; i < code.length() ; i++){

        string cmp = "\n";

        if(code[i] == cmp[0]){


            this->strings.newNode(current);

            current = "";


        }else if(i == code.length()-1){

            string copy;
            copy = code[i];
            current.append(copy);
            this->strings.newNode(current);

        }
        else{

            string copy;
            copy = code[i];
            current.append(copy);
        }

    }

    for(int i = 0; i < this->strings.getLength(); i++){

        parseLine(this->strings[i]);

    }

    return this->strings;


}