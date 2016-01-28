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
    cw = values[0];
    ct = values[1];
    k = values[2];
    ko = values[3];
    Mi = values[4];
    t = values[5];
    td = values[6];
    deltapo = values[7];
    j = values[8];
}
