#pragma once
#include <cstdint>

enum KeyType {
    Cd10Digit = 10,
    Cd11Digit = 11,
    Oem20Digit = 20
};

struct Operation {
    KeyType keyType;
    uint16_t keyNum;

    Operation(KeyType keyType, uint16_t keyNum)
            : keyType(keyType), keyNum(keyNum) {};
};