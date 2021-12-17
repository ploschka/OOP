#include "Base64.h"
#include <map>

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
        buffer >>= 8;

        for(int j = 0; j < 4; j++)
        {
            /*short int index = buffer >> ((18 - 6*j) + 8);
            buffer <<= 6*(j+1);
            buffer >>= 6*(j+1);
            result += characters[index];*/
            
            unsigned char index = buffer >> 18;
            buffer <<= (8 + 6);
            buffer >>= 8;
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

std::string decode(const std::string& input)
{
    int len = input.length();
    if((len % 4) != 0)
    {
        throw(std::length_error("Not a Base64 string length\nFile: " + std::string(__FILE__) + "\nLine: " + std::to_string(__LINE__)));
    }

    for(char i: input)
    {
        if  (!((i != '=') ||
            (i != '/') ||
            (i != '+') ||
            ((i >= 'A') && (i <= 'Z')) ||
            ((i >= 'a') && (i <= 'z')) ||
            ((i >= '0') && (i <= '1'))))
        {
            throw(std::invalid_argument("Not a Base64 string\nFile: " + std::string(__FILE__) + "\nLine: " + std::to_string(__LINE__)));
        }
    }
    std::map<char, int> characters {{'A', 0},  {'B', 1},  {'C', 2},  {'D', 3}, 
                                    {'E', 4},  {'F', 5},  {'G', 6},  {'H', 7}, 
                                    {'I', 8},  {'J', 9},  {'K', 10}, {'L', 11}, 
                                    {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15}, 
                                    {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, 
                                    {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23}, 
                                    {'Y', 24}, {'Z', 25}, {'a', 26}, {'b', 27}, 
                                    {'c', 28}, {'d', 29}, {'e', 30}, {'f', 31}, 
                                    {'g', 32}, {'h', 33}, {'i', 34}, {'j', 35}, 
                                    {'k', 36}, {'l', 37}, {'m', 38}, {'n', 39}, 
                                    {'o', 40}, {'p', 41}, {'q', 42}, {'r', 43}, 
                                    {'s', 44}, {'t', 45}, {'u', 46}, {'v', 47}, 
                                    {'w', 48}, {'x', 49}, {'y', 50}, {'z', 51}, 
                                    {'0', 52}, {'1', 53}, {'2', 54}, {'3', 55}, 
                                    {'4', 56}, {'5', 57}, {'6', 58}, {'7', 59}, 
                                    {'8', 60}, {'9', 61}, {'+', 62}, {'/', 63}};
    std::string result;

    unsigned short int equalityCount = 0;
    for(int i = 0; i < len; i += 4)
    {
        unsigned int buffer = 0;
        for(int j = 0; j < 4; j++)
        {
            if(input[i + j] != '=')
            {
                buffer += characters[input[i + j]];
                buffer <<= 6;
            }
            else
            {
                equalityCount++;
            }
        }

        buffer <<= 2;
        buffer >>= 8;
        buffer >>= (2 * equalityCount);

        for(int j = 0; j < 3; j++)
        {
            unsigned char index = buffer >> 16;
            buffer <<= 8;
            if(index != 0)
            {
                result += index;
            }
        }
    }
    return result;
}
}