#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include <iostream>
#include "string"
#include "mserver_client.h"
#include "nlohmann/json.hpp"
#include "Parser.h"
#include "Compiler.h"


using json = nlohmann::json;
using string = std::string;

//main driver program
int main(int argc , char *argv[])
{

    Compiler comp;

    json j;

    j[0] = "int";
    j[1] = "a";
    j[2] = "=";
    j[3] = "5";
    j[4] = ";";

    mserver_client client(90190);

    comp.allocate("int a = 5;");

    client.sendJson("break");

    return 0;
}