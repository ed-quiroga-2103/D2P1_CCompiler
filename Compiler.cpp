//
// Created by eduardo on 09/04/18.
//

#include "Compiler.h"

Compiler::Compiler() {

    this->client = new mserver_client(90190);

}

bool Compiler::checkType(string type) {

    for(int i = 0; i < 5; i++){

        if(this->tokens[i] == type){

            return true;

        }

    }

    return false;
}

bool Compiler::checkTag(string tag) {

    for(int i = 0; i < tags.getLength(); i++){

        if(tags[i] == tag){

            return false;

        }

    }

    return true;

}

bool Compiler::checkJson(string stream) {

    json in = parser.parseLine(stream);

    bool checked = checkType(in[0]) && checkTag(in[1]) && (in[2] == "=") && (in[4]==";");

    return checked;
}

void Compiler::allocate(string str){

    SingleList<string> strings = parser.splitCode(str);

    for(int i = 0; i < strings.getLength(); i++){

        if(checkJson(strings[i])) {

            json in = parser.parseLine(strings[i]);

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

            perror("Error en sintaxis");

            return;

        }

    }

}