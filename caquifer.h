#ifndef CAQUIFER_H
#define CAQUIFER_H

#include <vector>

class CAquifer
{
public:
		CAquifer();
		~CAquifer();

    virtual bool isLinear() const = 0;

    virtual void manualEntry();

protected:
    double cf; ///< Formation compressibility
    double h;  ///< Height (thickness)
    double pi; ///< Intern pressure
    double po; ///< Extern pressure
    double phi;///< Porosity
    double k;  ///< Permeability
    double wd; ///<
    double we;
    double wei;

    std::vector<double> p; ///< Pressure log
    std::vector<double> t; ///< Time log
};

#endif // CAQUIFER_H
