#pragma once

#include <vector>
#include <iostream>
#include <cstring>
#include "CommonHeaders.h"
#include "ConsoleOutput.h"

bool IsNumber(const char* str);
bool TryParseArgs(int argc, char **argv, std::vector<Operation>& queue);