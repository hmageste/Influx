#include "cradialaquifer.h"

#include <iostream>

CRadialAquifer::CRadialAquifer()
    : CAquifer()
{

}

void CRadialAquifer::manualEntry()
{
    CAquifer::manualEntry();

    std::cout << "Enter Re: ";
    std::cin >> re;
    std::cout << std::endl;

    std::cout << "Enter Ro: ";
    std::cin >> ro;
    std::cout << std::endl;
}
