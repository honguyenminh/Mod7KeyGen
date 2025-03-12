#include "ArgumentParser.h"
#include "ConsoleOutput.h"

#include <iostream>
#include <string>

using namespace std;

bool IsNumber(const char* str) {
    return string(str).find_first_not_of("0123456789") == string::npos;
}

// Return true if args is parsed successfully
// If parsing throws an error, return false (don't run anymore)
bool TryParseArgs(int argc, char **argv, vector<Operation>& queue) {
    // No argument
    if (argc <= 1) {
        cout << "Key generator for Windows 95/NT4.\n";
        cout << "GitHub: https://github.com/honguyenminh/Mod7KeyGen\n";
        cout << "Use --help or -h for more information\n";
        return false;
    }
    // Help
    if (strcmp(argv[0], "--help") == 0 || strcmp(argv[0], "-h") == 0) {
        ShowHelp();
        return false;
    }

    /// Arguments parser
    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] != '-' || strlen(argv[i]) == 1) {
            InvalidArgs();
            return false;
        }
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            ShowHelp();
            return false;
        }
        int keyNum = 1;
        bool advanceNextArg = false;
        // If not the end of args list
        if (i + 1 != argc) {
            // If next is not another operation
            if (argv[i + 1][0] != '-') {
                advanceNextArg = true;
                if (IsNumber(argv[i + 1]))
                    keyNum = stoi(argv[i + 1]);
                else {
                    InvalidArgs();
                    return false;
                }
            }
        }
        // Full args (start with "--") like --help or --type
        if (argv[i][1] == '-') {
            // Add operation to queue
            if (strcmp(argv[i], "--10-digit") == 0) {
                queue.emplace_back(KeyType::Cd10Digit, keyNum);
            } else if (strcmp(argv[i], "--11-digit") == 0) {
                queue.emplace_back(KeyType::Cd11Digit, keyNum);
            } else if (strcmp(argv[i], "--20-digit") == 0) {
                queue.emplace_back(KeyType::Oem20Digit, keyNum);
            } else {
                InvalidArgs();
                return false;
            }
        }
        // Short args (start with "-") like -t or -l
        else {
            // Add operation to queue
            if (strcmp(argv[i], "-10") == 0) {
                queue.emplace_back(KeyType::Cd10Digit, keyNum);
            } else if (strcmp(argv[i], "-11") == 0) {
                queue.emplace_back(KeyType::Cd11Digit, keyNum);
            } else if (strcmp(argv[i], "-20") == 0) {
                queue.emplace_back(KeyType::Oem20Digit, keyNum);
            } else {
                InvalidArgs();
                return false;
            }
        }
        if (advanceNextArg) i++;
    }
    return true;
}