#ifndef CBASECLASS_H
#define CBASECLASS_H

#include <string>
#include <vector>

class CBaseClass
{
public:
		    CBaseClass();
		    ~CBaseClass();

    virtual double  calcWe() = 0;
    virtual void    manualEntry();
    virtual void    fileEntry();

protected:
    double cw; ///< Water compressibility
    double ct; ///< Total compressibility
    double k;  ///< Water permeability
    double ko; ///< Oil permeability
    double Mi; ///< Water viscosity
    double t;  ///< Time
    double td;
    double deltapo;
    double j;

    std::string file_name;

private:
    double value;
    std::vector<double> values;

    void assign_values_to_variables(std::vector<double> values);
};

#endif // CBASECLASS_H
