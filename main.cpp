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

    Compiler cmp;
    Parser par;

    cmp.allocate("amt o = 2;");

    return 0;
}