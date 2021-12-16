#pragma once
#include <string>
#include "Exception.h"

namespace Base64
{
std::string encode(const std::string& input);
std::string decode(const std::string& input);
}