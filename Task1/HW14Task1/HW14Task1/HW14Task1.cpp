#include <iostream>
#include <random>
#include <string>

bool validateSerial(const std::string& serial) {
    if (serial.length() != 6) return false;
    int totalSum = 0;
    for (int i = 0; i < serial.length(); ++i) {
        totalSum += serial[i] + i + 16;
    }

    if (serial[0] + serial[5] == 0xDE && serial[2] + serial[3] == 0xD4 && totalSum == 754) return true;

    return false;
}
std::string generateSerialNumber()
{
    const std::string characters = 
    {
        " !#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~ "
    };
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> uniformIntDistribution(0, characters.size() - 1);
    std::string serialNumber;
    int currentTotalSum = 0;
    do 
    {
        serialNumber = "";
        for (int i = 0; i < 6; ++i) 
        {
            serialNumber += characters.at(uniformIntDistribution(generator));
        }
        
	    for (int i = 0; i < serialNumber.length(); ++i) 
	    {
	        currentTotalSum += serialNumber.at(i) + i + 16;
	    }
    }
	while (serialNumber[0] + serialNumber[5]  == 222 && serialNumber[2] + serialNumber[3]  == 212 && currentTotalSum == 754);
    
	return serialNumber;
}
int main() {
    std::string testSerial = generateSerialNumber();

    if (validateSerial(testSerial)) 
    {
        std::cout << "Generated Serial: " << testSerial << " is valid." << std::endl;
    }
	else 
    {
        std::cout << "Generated Serial: " << testSerial << " is invalid." << std::endl;
    }
    return 0;
}
