#include "cbaseclass.h"

#include <iostream>
#include <fstream>

//#include <vector>

CBaseClass::CBaseClass()
{}

void CBaseClass::manualEntry()
{}

void CBaseClass::fileEntry( const std::string& file_name )
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

void CBaseClass::setCw( double cw_ )
{
    rock.cf = cw_;
}

void CBaseClass::assign_values_to_variables( std::map<std::string, double> expressions )
{
    for(it_expressions expression = expressions.begin(); expression != expressions.end(); expression++)
        functions.insert( std::make_pair( expression->first, &CBaseClass::setCw ) );

    for(it_functions function = functions.begin(); function != functions.end(); function++)
    {
        if ( functions.find( function->first ) != functions.end() )
        {
            MPF fp = functions[function->first];
            (this->*fp)( expressions[function->first] );
        }

        std::cout << rock.cf;
    }
}
