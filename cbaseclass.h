#ifndef CBASECLASS_H
#define CBASECLASS_H

#include <string>
#include <vector>
#include <map>
#include "sfluid.h"

class CBaseClass
{
public:
            CBaseClass();

    virtual double  calcWe(double) = 0;
    virtual void    manualEntry();
    virtual void    fileEntry();

    void setCw(double);

protected:

    std::string file_name;

private:
    double value;
    std::string assing, variable;

    typedef std::map<std::string, double>::iterator it_expressions;
    std::map<std::string, double> expressions;

    typedef void (CBaseClass::*MPF)(double);
    typedef std::map<std::string, MPF>::iterator it_functions;
    std::map<std::string, MPF> functions;

//    Just for tests
    SRock rock;

    void assign_values_to_variables(std::map<std::string, double>);
};

#endif // CBASECLASS_H
