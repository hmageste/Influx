#include "cradialaquifer.h"

#include <iostream>
#include <cmath>

CRadialAquifer::CRadialAquifer()
    : CAquifer()
{}

CRadialAquifer::CRadialAquifer( const SRock& rock_, const SFluid& fluid_ )
    : CAquifer(rock_,fluid_)
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

void CRadialAquifer::setVariables( std::map<std::string,double>& tokens )
{
    CAquifer::setVariables( tokens );

    setRe( tokens["re"] );
    setRo( tokens["ro"] );
    setF( tokens["f"] );
}

double CRadialAquifer::getArea() const
{
    return M_PI*(re*re-ro*ro)*fraction;
}

double CRadialAquifer::getCt() const
{
    return rock.cf+fluid.cf;
}

double CRadialAquifer::getF() const
{
    return fraction;
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
    return 2*M_PI*fraction;
}

double CRadialAquifer::getU() const
{
    return 2.0*M_PI*getF()*rock.phi*getCt()*h*ro*ro;
}

void CRadialAquifer::setRe( double re_ )
{
    re = re_;
}

void CRadialAquifer::setRo( double ro_ )
{
    ro = ro_;
}

void CRadialAquifer::setF( double fraction_ )
{
    fraction = fraction_;
}
