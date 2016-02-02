#include "cbaseclass.h"

#include <iostream>
#include <fstream>

CBaseClass::CBaseClass()
{}

void CBaseClass::manualEntry()
{}

void CBaseClass::fileEntry()
{
    // Open and read a file
    std::cout << "Entre com o nome do arquivo: ";
    std::cin >> file_name;
    std::cout << std::endl;

    std::fstream myfile( file_name.c_str() );

    if ( myfile.is_open() )
    {
        while( myfile >> variable >> assing >> value )
            expressions.insert( std::make_pair( variable, value ) );

        assign_values_to_variables( expressions );
    }
    else
    {
        std::cerr << "Não é possível abrir o arquivo especificado";
        return;
    }

    myfile.close();
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
