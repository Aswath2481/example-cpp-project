#include "first.hpp"
#include <iostream>
#include <cstring>

#include <array>

void first::printFunc(){
    std::cout << "First Class" << std::endl;
}

void first::sendDataUsingPointer(uint8_t* l_data){
    std::array<int8_t, 15> l_logData;
    std::memmove(l_logData.begin(), l_data, sizeof(l_data));
    std::cout << l_data << std::endl;
    std::cout << sizeof l_data << std::endl;
}