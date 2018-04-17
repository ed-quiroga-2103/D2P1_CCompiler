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

    bool firstChecked = false;

    bool inPrint = false;

    json j;

    string currentln = "";

    int count = 0;


    for(int i = 0; i < line.length(); i++){

        string cmp = " ";
        string col = ";";
        string ln = "\n";
        string cmp1 = "(";
        string cmp2 = ")";
        if(line[i] == ln[0]){

            //Skips char

        }
        else if(line[i] == cmp1[0]){

            j[count] = currentln;
            currentln = "";
            count++;
            j[count] = "(";
            inPrint = true;
            count++;



        }else if(line[i] == cmp2[0]){

            j[count] = currentln;
            currentln = "";
            count++;
            j[count] = ")";
            count++;
            inPrint = true;

        }
        else if(line[i] == col[0]){

            j[count] = currentln;
            count++;

            j[count] = ";";
            currentln = "";
            count++;

        }
        else if(line[i] != cmp[0]){

            string copy;
            copy = line[i];
            currentln.append(copy);
            firstChecked = true;

        }else if(!firstChecked || inPrint){

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

    j[count] = 0;

    return j;

}

SingleList<string> Parser::splitCode(string code){

    string current = "";

    for(int i = 0; i < code.length() ; i++){

        string cmp = "\n";
        string col = ";";

        if(code[i] == col[0]){

            current.append(";");
            this->strings.newNode(current);

            current = "";


        }else if(i == code.length()-1){

            string copy;
            copy = code[i];
            current.append(copy);
            this->strings.newNode(current);

        }
        else if(cmp[0] == code[i]){

            //Skips char

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