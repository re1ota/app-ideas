#include <string>
#include <stdexcept>
#include "bin2dec.h"

int binToDec(const std::string& number) {

    if (number.empty()) {
        throw std::runtime_error("Wrong input! Please enter a binary number");
    }

    int result = 0;
    const int uncutLength = number.length();
    int position = 0;
    int length = 0;

    for (int i = 0; i < uncutLength; i++) {
        if (number.at(i) == '1' || number.at(i) == '0') {
            length++;
        }
    }

    if (length > 8 || length == 0) {
        throw std::runtime_error("Wrong input! Please enter a binary number with a maximum length of 8!");
    }

    for (int i = 0 ; i < uncutLength; i++) {
        char c = number.at(i);
        if (c == '1') {
            result += (1 << (length - 1 - position));
            position++;
        }else if (c == '0') {
            position++;
        }else if (c == ' ') {
            continue;
        }else {
            throw std::runtime_error("Wrong input! Please enter a binary number");
        }
    }
    return result;
}

