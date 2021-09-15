#include "KeyGen.h"
#include <iostream>

// I'm sorry
using namespace std;

KeyGen::KeyGen() {
    std::random_device randomDevice;
    seed = randomDevice();
    // Initialize random engine to make quick pseudo random int with true random seed
    randomEngine = default_random_engine(seed);
    // Initialize uniform dist to limit range of random
    randomDigit = uniform_int_distribution<char>('0', '9');
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
    static std::uniform_int_distribution<int> dateDist(1, 366); // Set another random limit with uni dist
    int temp = dateDist(randomEngine);                    // Get temp, then check, if 1 digit add 00, 2 digits add 0
    if (temp < 10) { key.append("00" + to_string(temp)); }
    else if (temp < 100) { key.append("0" + to_string(temp)); }
    else { key.append(to_string(temp)); }             // If full 3 digits, append to key normally

    // - Next 2 digits is the year, 95 to 03 (95,96,97,98,99,00,01,02,03) is valid
    string yearArr[9] = {"95", "96", "97", "98", "99", "00", "01", "02", "03"};
    temp = 9;
    while (temp == 9) { temp = uniDist(randomEngine); }

    key.append(yearArr[temp]);

    // Second is OEM and the mod7 sequence again
    // But first character must be 0
    key.append("-OEM-0");
    int tempSum;
    string lastPart;
    do {
        tempSum = 0;
        lastPart = "";
        int temp;
        for (int i = 0; i < 6; i++) {
            temp = uniDist(randomEngine);
            tempSum += temp;
            lastPart.append(to_string(temp));
        }
    } while (tempSum % 7 != 0 || lastPart[5] - '0' == 0 || lastPart[5] - '0' >= 8);
    key.append(lastPart + "-");

    // Last five-digit segment can be anything, so randomly created
    for (int i = 0; i < 5; i++) {
        key.append(to_string(uniDist(randomEngine)));
    }
    cout << key << endl;
    key = "";
}

// TODO: This is incorrect, pls fix
string KeyGen::Mod7Generator() {
    // Digit sum must be divisible to 7
    // Last digit must be in range [1, 7]
    // Create random factor that makes a 7-digit long number when multiplied with 7
    string key;
    static uniform_int_distribution<int> randomFactor(142858, 1428571);
    do {
        key = to_string(randomFactor(randomEngine) * 7);
    } while (key[6] > '7' || key[6] == '0');
    return key;
}