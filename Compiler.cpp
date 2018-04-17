//
// Created by eduardo on 09/04/18.
//

#include "Compiler.h"

Compiler::Compiler() {

    this->client = new mserver_client(90190);

}

/**
 *
 * @param Data type
 * @return boolean
 *
 * Returns true if the type token is admitted
 */
bool Compiler::checkType(string type) {

    for(int i = 0; i < 10; i++){

        if(this->tokens[i] == type){

            return true;

        }
    }

    return false;
}

/**
 *
 * @param tag
 * @return
 *
 * Checks if the tag is already being used
 */
bool Compiler::checkTag(string tag) {

    for(int i = 0; i < tags.getLength(); i++){

        if(tags[i] == tag){

            return false;

        }

    }

    return true;

}

/**
 *
 * @param stream
 * @return
 *
 * Evaluates if the json has the required tokens to be allocated
 */
string Compiler::checkJson(string stream) {

    json in = parser.parseLine(stream);

    if(checkType(in[0])){



            if(in[2] == "="){

                if(in[4]==";"){

                    return "1";

                }else return "Sintax error";

            }else return "Sintax error";


    }
    else{
        std::stringstream error;

        error << "Type " << in[0] << " does not exist";

        return error.str();
    }

}

/**
 *
 * @param str
 *
 * Gets the string of code for it to be parsed, and then it
 * gets sent to the server to be allocated
 *
 */
string Compiler::allocate(string str){

    SingleList<string> strings = parser.splitCode(str);
    json in = parser.parseLine(strings[line]);

    if(in[0] == "print"){

        this->line++;
        return in[2];

    }

    if(checkJson(strings[line]) == "1") {

        json in = parser.parseLine(strings[line]);

        json msg;


        msg["type"] = in[0];
        msg["tag"] = in[1];
        msg["val"] = in[3];
        msg["cmplx"] = 0;

        if(checkForRef(in)){

            msg["val"] = missOp(in);
            msg["cmplx"] = 1;
        }
        else if(checkForDRef(in)){

            msg["val"] = missOp(in);
            msg["cmplx"] = 2;
        }

        if(msg["cmplx"] == 1 || msg["cmplx"] == 2) {

            //Checks if the value being referenced exists
            for (int i = 0; i < this->tags.getLength(); i++) {

                //Checks if the value is included in the allocated tags
                if (this->tags[i] == msg["val"]) {

                    if(isTypeRef(msg) && msg["cmplx"] == 1) {

                        this->tags.newNode(msg["tag"]);
                        this->types.newNode(msg["type"]);
                        this->vals.newNode(msg["val"]);

                        //Sends json through the server client
                        client->sendJson(msg.dump());
                        this->line++;
                        return "Success";


                    }else if(msg["cmplx"] == 2){

                        this->tags.newNode(msg["tag"]);
                        this->types.newNode(msg["type"]);
                        this->vals.newNode(msg["val"]);

                        client->sendJson(msg.dump());
                        this->line++;
                        return "Success";

                    }
                    else{
                        this->line++;
                        return "Value is not a reference";

                    }
                }

            }

            this->line++;

            return "Value has not been defined";

        }

        this->tags.newNode(msg["tag"]);
        this->types.newNode(msg["type"]);
        this->vals.newNode(msg["val"]);

        client->sendJson(msg.dump());

    }
    else{

        log.newLog(checkJson(strings[line]),line);
        this->line++;
        return checkJson(strings[line]);
        }

    this->line++;
    return "Success";
    }

bool Compiler::checkForRef(json j) {

    if(j[j.size()-1]==0){

        string val = j[3];

        string ops = "&";

        if(val[0] == ops[0]){

            return true;

        }else{

            return false;

        }


    }
    else{

        return false;

    }

}

bool Compiler::checkForDRef(json j) {

    if(j[j.size()-1]==0){

        string val = j[3];

        string ops = "*";

        if(val[0] == ops[0]){

            return true;

        }else{

            return false;

        }


    }
    else{

        return false;

    }

}

bool Compiler::isTypeRef(json j) {

    string tokens[5] = {"reference<int>", "reference<long>", "reference<char>", "reference<double>", "reference<float>"};

    for(int i = 0; i < 5; i++){

        if(tokens[i] == j["type"]){

            return true;

        }

    }
    return false;

}

string Compiler::pull() {
    client->sendJson("pull");
    return this->client->data;
}

string Compiler::missOp(json j) {

    string val = j[3];
    string newVal = "";

    for(int i = 1; i < val.length(); i++){

        newVal+= val[i];

    }

    return newVal;
}
