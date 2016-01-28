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
    f = theta/2.0/M_PI;
    u = 2.0*M_PI*f*rock.phi*getCt()*h*ro*ro;
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
    return rock.cf+fluid.cf;
}
