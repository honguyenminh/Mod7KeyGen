cmake_minimum_required(VERSION 3.20)
project(Mod7KeyGen)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mod7KeyGen main.cpp main.h CommonHeaders.h ArgumentParser.cpp ArgumentParser.h ConsoleOutput.cpp ConsoleOutput.h KeyGen.cpp KeyGen.h)
