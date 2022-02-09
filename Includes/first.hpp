#ifndef FIRST_HPP
#define FIRST_HPP

#include <stdint.h>
#include <iostream>
#include <cstddef>
#include <array>
class first
{
private:
    /* data */
public:
    void printFunc();
    void sendDataUsingPointer(uint8_t* l_char);
};

struct customStruct {
    int id;
    std::array<char,10> name;
    float percentage;
};


#endif //FIRST_HPP