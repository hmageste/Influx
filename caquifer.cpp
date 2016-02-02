#include "caquifer.h"

#include <iostream>
#include <fstream>

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

void CAquifer::fileEntry( const std::string& file_name )
{
    std::ifstream fin( file_name.c_str() );

    if ( fin.is_open() )
    {
    while( fin >> variable >> assing >> value )
            expressions.insert( std::make_pair( variable, value ) );

        assign_values_to_variables( expressions );
    }
    else
    {
        std::cerr << "Não é possível abrir o arquivo especificado";
        return;
    }

    fin.close();
}

void CAquifer::setCf( double cf_ )
{
    fluid.cf = cf_;
}

void CAquifer::assign_values_to_variables( std::map<std::string, double> expressions )
{
    for(it_expressions expression = expressions.begin(); expression != expressions.end(); expression++)
        functions.insert( std::make_pair( expression->first, &CAquifer::setCf ) );

    for(it_functions function = functions.begin(); function != functions.end(); function++)
    {
        if ( functions.find( function->first ) != functions.end() )
        {
            MPF fp = functions[function->first];
            (this->*fp)( expressions[function->first] );
        }
    }
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
