#include <iostream>
#include <vector>
#include "header/models.h"
#include "io/ArgumentParser.h"
#include "keygen/KeyGen.h"

int main(int argc, char* argv[]) {
    // Operation queue
    std::vector<Operation> queue;

    // TODO: reverse the result to "success" or similar
    bool stop = TryParseArgs(argc, argv, queue);
    if (stop) return 1;

    /// Generate keys and output
    KeyGen keyGen;
    // Run operations queue
    for (const auto& operation : queue) {
        std::cout << "[Operation]: " << operation.keyType << "-digit key, total " << operation.keyNum << " key.\n";
        for (int i = 0; i < operation.keyNum; ++i) {
            keyGen.GeneratePrintKey(operation.keyType);
        }
    }
    return 0;
}