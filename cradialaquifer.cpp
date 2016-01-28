#include "cradialaquifer.h"

#include <iostream>
#include <cmath>

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


void CRadialAquifer::calcU()
{
    ct = cf + 1.0; //ct = cf + cw;
    f = theta/2.0/M_PI;
    u = 2.0*M_PI*f*phi*ct*h*ro*ro;
}

double CRadialAquifer::getRe() const
{
    return re;
}

double CRadialAquifer::getRo() const
{
    return ro;
}

double CRadialAquifer::getTheta() const
{
    return theta;
}

double CRadialAquifer::getCt() const
{
    return cf; // fluid.cw+rock.cf;
}
