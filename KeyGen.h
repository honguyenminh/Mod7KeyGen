#pragma once

#include "CommonHeaders.h"
#include <random>
#include <string>

class KeyGen {
public:
    KeyGen();
    // Always use this function, don't touch the rest
    static void GeneratePrintKey(KeyType keyType);

    // Generate Mod7 part for CD 10 and 11 digit keys
    static std::string Mod7Generator();

private:
    // Make a true random seed
    static unsigned int seed;
    // Initialize random engine to make quick pseudo random int with true random seed
    static std::default_random_engine randomEngine;
    // Initialize uniform dist to limit range of random
    static std::uniform_int_distribution<char> randomDigit;
};