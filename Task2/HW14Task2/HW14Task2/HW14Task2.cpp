#include <iostream>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>
#include <string>

// ‘ункц≥€ перетворенн€ беззнакового масиву char у ш≥стнадц€тковий р€док  (Function to convert an unsigned char array to a hexadecimal string)
std::string toHexString(unsigned char* md)
{
    std::stringstream ss;
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)md[i];
    return ss.str();
}

// ‘ункц≥€, €ка знаходить сер≥йний номер за заданим MD5 хешем (Function that finds the serial number with the given MD5 hash)
std::string findSerialWithHash(const std::string& targetHash)
{
    unsigned char md[MD5_DIGEST_LENGTH];
    std::string serial;
    for (unsigned long long i = 0; ; i++) 
    {
        serial = std::to_string(i);
        MD5((unsigned char*)serial.c_str(), serial.length(), (unsigned char*)&md);
        std::string hash = toHexString(md);
        if (hash == targetHash) 
        {
            return serial;
        }
    }
}

int main() {
    std::string targetHash = "96c4dda0c4a0b34262b1d91d47056f9e";
    std::string serial = findSerialWithHash(targetHash);
    if (!serial.empty()) 
    {
        std::cout << "Found serial number: " << serial << std::endl;
    }
	else 
    {
        std::cout << "Serial number not found." << std::endl;
    }
    return 0;
}
