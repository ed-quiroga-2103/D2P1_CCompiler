cmake_minimum_required(VERSION 3.9)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Proyecto1 main.cpp Logger.cpp Logger.h mserver_client.cpp mserver_client.h Parser.cpp Parser.h Compiler.cpp Compiler.h)