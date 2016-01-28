#ifndef CAQUIFER_H
#define CAQUIFER_H

#include <vector>

class CAquifer
{
public:
		    CAquifer();
		    ~CAquifer();
    enum    model   { infinite, sealed, constant };

    virtual bool    isLinear() const = 0;

    virtual void    manualEntry();

    double	    getU() const;
    double	    getWd() const;
    double	    getPi() const;
    double	    getPo() const;

protected:
    double cf;	///< Formation compressibility
    double h;	///< Height (thickness)
    double pi;	///< Initial pressure
    double po;	///< Reservoir contact pressure
    double phi;	///< Porosity
    double k;	///< Permeability
    double wd;	///< Dimensionless cumulative water influx
    double we;	///< Cumulative water influx
    double wei; ///< Initial water in place
    double u;	///< Constante de Influxo de Água do Aquífero

    std::vector<double> p; ///< Pressure log
    std::vector<double> t; ///< Time log
};

#endif // CAQUIFER_H