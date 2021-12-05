#include "Base64.h"

namespace Base64
{
std::string encode(const std::string& input)
{
    int len = input.length();
    std::string characters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
    short int equalityCount = ((len % 3) == 0) ? 0 : (3 - (len % 3));
    std::string result;
    unsigned int buffer = 0;
    
    for(int i = 0; i < len; i+=3)
    {
        for(int j = 0; j < 3; j++)
        {
            buffer += (((i + j) < len) ? input[i+j] : 0);
            buffer <<= 8;
        }

        for(int j = 0; j < 4; j++)
        {
            short int index = buffer >> ((18 - 6*j) + 8);
            buffer <<= 6*(j+1);
            buffer >>= 6*(j+1);
            result += characters[index];
        }
        buffer = 0;
    }

    len = result.length() - 1;
    for(int i = 0; i < equalityCount; i++)
    {
        result[len - i] = '=';
    }

    return result;
}

std::string decode(std::string input)
{
    int len = input.length();
}
}