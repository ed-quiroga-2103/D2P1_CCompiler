//
// Created by eduardo on 30/03/18.
//

#include "Logger.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>


void Logger::newLog(std::string error, int line) {

    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::string time = std::ctime(&end_time);
    std::string name = "Error at: " + time;

    std::ofstream myfile;
    myfile.open (name, std::ios::app);

    myfile << "Error #" << Logger::num << " in line " << line << ".\n";
    myfile << error + "\n";

    myfile.close();

    Logger::num++;
}