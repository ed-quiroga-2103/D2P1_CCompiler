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

    for(int i = 0; i < 5; i++){

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

        if(checkTag(in[1])){

            if(in[2] == "="){

                if(in[4]==";"){

                    return "1";

                }else return "Sintax error";

            }else return "Sintax error";

        }else{
            std::stringstream error;

            error << "Double declaration of " << in[1];

            return error.str();

        }
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



    if(checkJson(strings[line]) == "1") {

        json in = parser.parseLine(strings[line]);
        json msg;

        msg["type"] = in[0];

        msg["tag"] = in[1];

        msg["val"] = in[3];

        this->tags.newNode(msg["tag"]);
        this->types.newNode(msg["type"]);
        this->vals.newNode(msg["val"]);

        client->sendJson(msg.dump());

    }
    else{

        log.newLog(checkJson(strings[line]),line);
        return checkJson(strings[line]);
        }
    return "Success";
    }



bool Compiler::checkForOp(json j) {

    if(j[j.size()-1]==0){

        string val = j[3];

        string ops = "*&";

        if(val[0] == ops[0] || val[0] == ops[1]){



            return true;

        }else{

            return false;

        }


    }
    else{

        return false;

    }

}

string Compiler::pull() {
    client->sendJson("pull");
    return this->client->data;
}