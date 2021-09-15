#include "KeyGen.h"
#include <iostream>

// I'm sorry
using namespace std;

KeyGen::KeyGen() {
    random_device randomDevice;
    this->seed = randomDevice();
    // Initialize random engine to make quick pseudo random int with true random seed
    this->randomEngine = default_random_engine(seed);
    // Initialize uniform dist to limit range of random
    this->randomDigit = uniform_int_distribution<char>('0', '9');
}

void KeyGen::GeneratePrintKey(KeyType keyType) {
    // 10-digit retail CD key
    if (keyType == KeyType::Cd10Digit) {
        // First 3 digits, anything but 333, 444, ..., 999
        // Switch to c-string and strcmp if you need s p e e d & s p a c e
        // I sure don't
        string key = "---";
        do {
            for (int i = 0; i < 3; i++) {
                key[i] = randomDigit(randomEngine);
            }
        } while (
            // TODO: fix this mess
                key == "333" &&
                key == "444" &&
                key == "555" &&
                key == "666" &&
                key == "777" &&
                key == "888" &&
                key == "999"
                );
        cout << key;

        // Last 7 digits
        cout << '-' << Mod7Generator() << "\n";
        return;
    }

    // 11-digit retail CD key (i.e. Office 97)
    if (keyType == KeyType::Cd11Digit) {
        // First 3 digits can be anything
        char key[4];
        key[3] = 0; // c-string, null terminate
        for (int i = 0; i < 3; ++i) {
            key[i] = randomDigit(randomEngine);
        }
        // 4th digit is 3rd digit + 1 or + 2, overflow if > 9
        // Roll a die for +1 or +2
        char randomPlus = randomDigit(randomEngine) > 4 ? 1 : 2;
        // Overflow
        if ((key[2] - '0') + randomPlus > 9) {
            cout << key << randomPlus - 1;
        } else {
            cout << key << key[2] + randomPlus;
        }
        /// If this doesn't make sense to you, read the source blog linked on README.md page

        // Last 7 digits, same with 10digit key
        cout << '-' << Mod7Generator() << "\n";
        return;
    }


    /// 20-digit OEM key
    /// Guaranteed with the Enum, so no need to check

    // First 5-digit segment, represent key printing date
    // - First 3 digits is days in a year, 001 to 366 (they don't check leap year)
    static std::uniform_int_distribution<short> randomDate(1, 366);
    short tempDate = randomDate(randomEngine);
    // Pad the date with 0s if needed
    if (tempDate < 10) { cout << "00" << tempDate; }
    else if (tempDate < 100) { cout << '0' << tempDate; }
    else cout << tempDate;

    // - Next 2 digits is the year, 95 to 03 is valid
    const char* validYear[9] = {"95", "96", "97", "98", "99", "00", "01", "02", "03"};
    tempDate = 9;
    while (tempDate == 9)
        tempDate = (unsigned char) (randomDigit(randomEngine) - '0');

    cout << validYear[tempDate];

    // Second is -OEM- and the mod7 sequence again
    // But first digit must be 0
    cout << "-OEM-" << Mod7Generator(true) << '-';

    // Last five-digit segment can be anything, so randomly created
    for (char i = 0; i < 5; i++) {
        cout << randomDigit(randomEngine);
    }
    cout << '\n';
}

string KeyGen::Mod7Generator(bool firstDigitIsZero) {
    // Mod7 part is 7-digit long
    char digitSum;
    string key = "0------";
    // If first digit is zero, generate from the next digit only
    char firstDigitIndex = firstDigitIsZero ? 1 : 0;

    // Digit sum must be divisible to 7
    // Last digit must be in range [1, 7]
    do {
        digitSum = 0;
        for (char i = firstDigitIndex; i < 7; ++i) {
            key[i] = randomDigit(randomEngine);
            digitSum += key[i] - '0';
        }
    } while (digitSum % 7 != 0 || key[6] > '7' || key[6] == '0');
    return key;
}