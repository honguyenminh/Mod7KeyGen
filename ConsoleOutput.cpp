#include "ConsoleOutput.h"

using namespace std;

void ShowHelp() {
    cout << "A basic product key generator for Microsoft products that use mod7 algorithm.\n\n";
    cout << "Usage: Mod7KeyGen(.exe) {argument(s)}\n\n";
    cout << "Arguments list:\n";
    cout << "-h       --help           Display this help. All other argument WILL BE IGNORED.\n";
    cout << "-10 <n>  --10-digit <n>   Generate <n> 10-digit key for CD retails.\n";
    cout << "                           - Is often used by Windows 95, NT,...\n";
    cout << "-11 <n>  --11-digit <n>   Generate <n> 11-digit key for CD retails.\n";
    cout << "                           - This type can be found in Office 97,...\n";
    cout << "-20 <n>  --20-digit <n>   Generate <n> 20-digit key for OEM versions.\n";
    cout << "By default, if <n> is not set, operation will generate 1 key for that type\n\n";
    cout << "Example command to generate 50 keys of type 20-digit OEM and 20 keys of type 10-digit:\n";
    cout << "MOD7KeyGen.exe -20 50 --10-digit 20\n\n";
    cout << "                                      THIS KEYGEN HAS SUPER COW POWER.\n";
}

void InvalidArgs() {
    cout << "Invalid input. Check your syntax or spelling and try again.\n";
    cout << "Use --help or -h for more information (case sensitive)\n";
}