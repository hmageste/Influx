#include "cradialaquifer.h"

#include <iostream>
#include <cmath>

CRadialAquifer::CRadialAquifer()
    : CAquifer()
{}

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

void CRadialAquifer::fileEntry()
{
}

double CRadialAquifer::getCt() const
{
    return rock.cf+fluid.cf;
}

double CRadialAquifer::getF() const
{
    return theta/2.0/M_PI;
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

double CRadialAquifer::getU() const
{
    return 2.0*M_PI*getF()*rock.phi*getCt()*h*ro*ro;
}
