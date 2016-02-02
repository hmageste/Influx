#include "caquifer.h"

#include<iostream>

CAquifer::CAquifer()
{}

CAquifer::CAquifer( const SRock& rock_, const SFluid& fluid_ )
    : rock(rock_)
    , fluid(fluid_)
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
    std::cin >> rock.phi;
    std::cout << std::endl;

    std::cout << "Enter Permeability: ";
    std::cin >> rock.k;
    std::cout << std::endl;

    std::cout << "Enter Formation's Compressibility: ";
    std::cin >> rock.cf;
    std::cout << std::endl;

    std::cout << "Enter Fluid's Compressibility: ";
    std::cin >> fluid.cf;
    std::cout << std::endl;
}

void CAquifer::fileEntry()
{
}

double CAquifer::getVolume() const
{
    return getArea()*h;
}

double CAquifer::getH() const
{
    return h;
}

double CAquifer::getPi() const
{
    return pi;
}

double CAquifer::getPo() const
{
    return po;
}

SFluid CAquifer::getFluid() const
{
    return fluid;
}

SRock CAquifer::getRock() const
{
    return rock;
}

void CAquifer::getHistoric( std::vector<double>& t, std::vector<double>& p )
{
    t = time;
    p = pressure;
}

void CAquifer::setH( double h_ )
{
    h = h_;
}

void CAquifer::setPi( double pi_ )
{
    pi = pi_;
}

void CAquifer::setPo( double po_ )
{
    po = po_;
}

void CAquifer::setPressure( std::vector<double> p )
{
    pressure = p;
}

void CAquifer::setTime( std::vector<double> t )
{
    time = t;
}
