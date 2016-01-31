#ifndef CBASECLASS_H
#define CBASECLASS_H

#include <string>
#include <vector>

class CBaseClass
{
public:
            CBaseClass();

    virtual double  calcWe(double) = 0;
    virtual void    manualEntry();
    virtual void    fileEntry();

protected:

    std::string file_name;

private:
    double value;
    std::vector<double> values;

    void assign_values_to_variables(std::vector<double> values);
};

#endif // CBASECLASS_H
