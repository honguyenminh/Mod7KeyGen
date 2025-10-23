cmake_minimum_required(VERSION 3.20)
project(Mod7KeyGen)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mod7KeyGen
        src/main.cpp
        src/header/models.h
        src/io/ArgumentParser.cpp
        src/io/ArgumentParser.h
        src/io/ConsoleOutput.cpp
        src/io/ConsoleOutput.h
        src/keygen/KeyGen.cpp
        src/keygen/KeyGen.h
)

target_include_directories(Mod7KeyGen PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
