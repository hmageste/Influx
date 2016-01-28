#include "caquifer.h"

#include<iostream>

CAquifer::CAquifer()
{}

CAquifer::~CAquifer()
{}

void CAquifer::manualEntry()
{
    std::cout << "Enter Height: ";
    std::cin >> h;
    std::cout << std::endl;

    std::cout << "Enter Initial Pressure: ";
    std::cin >> pi;
    std::cout << std::endl;

    std::cout << "Enter Po: ";
    std::cin >> po;
    std::cout << std::endl;

    std::cout << "Enter Porosity: ";
    std::cin >> phi;
    std::cout << std::endl;

    std::cout << "Enter Permeability: ";
    std::cin >> k;
    std::cout << std::endl;

    std::cout << "Enter Formation's Compressibility: ";
    std::cin >> cf;
    std::cout << std::endl;
}

double CAquifer::getU() const
{
    return u;
}

double CAquifer::getWd() const
{
    return wd; //Unfortunaly it is not that simple to calc this one
}

double CAquifer::getPhi() const
{
    return phi;
}

double CAquifer::getPi() const
{
    return pi;
}

double CAquifer::getPo() const
{
    return po;
}
