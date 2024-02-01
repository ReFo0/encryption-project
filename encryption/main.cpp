#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include "xor.h"

std::string generatekey(int length)
{
    std::string key(length, 'A');  
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(key.begin(), key.end(), g);  

    return key;
}

std::string crypt(std::string originalCode)
{
    std::string key = generatekey(originalCode.length());

    std::string encryptedCode = originalCode;
    for (size_t i = 0; i < originalCode.length(); ++i)
    {
        encryptedCode[i] ^= key[i];
    }

    std::string decryptedCode = encryptedCode;
    for (size_t i = 0; i < encryptedCode.length(); ++i)
    {
        decryptedCode[i] ^= key[i];
    }
    return encryptedCode;
}

int main()
{
    auto encrypted = crypt(_("Hello World"));
    std::cout << "Encrypted Code: " << encrypted << std::endl;
    std::cin.get();
    return 0;
}
