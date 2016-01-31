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

    if (myfile.is_open())
    {
        while(myfile >> value)
        {
            values.push_back(value);
        }

        assign_values_to_variables(values);
    }
    else std::cout << "Não é possível abrir o arquivo especificado";

    myfile.close();
}

void CBaseClass::assign_values_to_variables(std::vector<double> values)
{
}
