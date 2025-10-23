#pragma once

#include <vector>
#include "header/models.h"

bool IsNumber(const char* str);
bool TryParseArgs(int argc, char **argv, std::vector<Operation>& queue);