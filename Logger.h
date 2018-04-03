//
// Created by eduardo on 30/03/18.
//

#ifndef PROYECTO1_LOGGER_H
#define PROYECTO1_LOGGER_H

#include <string>

class Logger {

public:
    void newLog(std::string error, int line);

private:
    int num = 1;
};


#endif //PROYECTO1_LOGGER_H
