#include "caquifer.h"

#include <iostream>
#include <fstream>
#include <sstream>

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

void CAquifer::setVariables( std::map<std::string,double>& tokens )
{
    setH( tokens["h"] );
    setPi( tokens["pi"] );
    setPo( tokens["po"] );
    rock.k = tokens["rock.k"];
    rock.cf = tokens["rock.cf"];
    rock.phi = tokens["rock.phi"];
    fluid.cf = tokens["fluid.cf"];
    fluid.viscosity = tokens["fluid.mi"];
}

void CAquifer::fileEntry( const std::string& file_name )
{
    std::ifstream fin( file_name.c_str() );
    if ( !fin.is_open() )
    {
	std::cerr << "File not found" << std::endl;
	return;
    }

    std::string line;
    std::vector<std::string> lines;
    while ( getline(fin,line,';') )
	lines.push_back( line );

    fin.close();

    std::map<std::string, double> tokens;

    std::string token, equalsign; double value;
    for ( int i = 0; i < lines.size(); i++ )
    {
	std::istringstream iss( lines[i] );
	iss >> token >> equalsign >> value;
	tokens.insert( std::make_pair(token,value) );
    }

    setVariables( tokens );
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
