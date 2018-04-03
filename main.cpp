#include <iostream>
#include "Logger.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main() {

    json j;

    j["asd"] = 123;

    std::cout << j["asd"];

    return 0;

}