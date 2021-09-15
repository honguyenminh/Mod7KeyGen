#include "ArgumentParser.h"

using namespace std;

bool IsNumber(const char* str) {
    return string(str).find_first_not_of("0123456789") == string::npos;
}

// Return true if args is handled (don't run anymore)
// False otherwise (keep running)
bool TryParseArgs(int argc, char **argv, vector<Operation>& queue) {
    // No argument
    if (argc == 1) {
        cout << "Key generator for Windows 95/NT4.\n";
        cout << "GitHub: https://github.com/honguyenminh/Mod7KeyGen\n";
        cout << "Use --help or -h for more information\n";
        return true;
    }
    // Help
    if (strcmp(argv[0], "--help") == 0 || strcmp(argv[0], "-h") == 0) {
        ShowHelp();
        return true;
    }

    /// Arguments parser
    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] != '-' || strlen(argv[i]) == 1) {
            InvalidArgs();
            return true;
        }
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            ShowHelp();
            return true;
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
                    return true;
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
                return true;
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
                return true;
            }
        }
        if (advanceNextArg) i++;
    }
    return false;
}