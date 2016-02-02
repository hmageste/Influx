#ifndef CAQUIFER_H
#define CAQUIFER_H

#include <vector>
#include <string>
#include <map>
#include "sfluid.h"

class CAquifer
{
public:
		    CAquifer();
		    CAquifer(const SRock&,const SFluid&);
		    ~CAquifer();
    enum    Model   { Infinite, Sealed, Constant };

    virtual bool    isLinear() const = 0;
    virtual double  getArea() const = 0;
    double	    getVolume() const;

    virtual void    manualEntry();
    virtual void    fileEntry(const std::string&);

    virtual double  getU() const = 0; ///< U = Constante de Influxo de Água do Aquífero

    double	    getH() const;
    double	    getPi() const;
    double	    getPo() const;
    SFluid	    getFluid() const;
    SRock	    getRock() const;
    void	    getHistoric(std::vector<double>&,std::vector<double>&);

    void	    setH(double);
    void	    setPi(double);
    void	    setPo(double);

    void	    setPressure(std::vector<double>);
    void	    setTime(std::vector<double>);

    Model	    model;

    double value;
    std::string assing, variable;

    std::map<std::string, double> expressions;

    typedef void (CAquifer::*MPF)(double);
    typedef std::map<std::string, MPF>::iterator it_functions;
    std::map<std::string, MPF> functions;
    void assign_values_to_variables(std::map<std::string, double>);

protected:
    double h;	///< Height (thickness)
    double pi;	///< Initial pressure
    double po;	///< Reservoir contact pressure

    SFluid fluid;
    SRock  rock;

    std::vector<double> pressure;   ///< Pressure historic
    std::vector<double> time;	    ///< Time historic

private:
    void setcf(double);
};

#endif // CAQUIFER_H
