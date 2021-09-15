#include "main.h"

int main(int argc, char *argv[]) {
    // Operation queue
    std::vector<Operation> queue;

    bool stop = TryParseArgs(argc, argv, queue);
    if (stop) return 1;

    /// Generate keys and output
    KeyGen keyGen;
    // Run operations queue
    for (auto operation : queue) {
        std::cout << "[Operation]: 10-digit retail CD key, total " << operation.keyNum << " key.\n";
        for (int i = 0; i < operation.keyNum; ++i) {
            keyGen.GeneratePrintKey(operation.keyType);
        }
    }
    return 0;
}