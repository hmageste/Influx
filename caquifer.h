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
    void	    loadData(const std::string&);
    void	    loadHistory(const std::string&);

    virtual double  getU() const = 0; ///< U = Constante de Influxo de Água do Aquífero

    double	    getH() const;
    double	    getPi() const;
    double	    getPo() const;
    SFluid	    getFluid() const;
    SRock	    getRock() const;
    void	    getHistoric(std::vector<double>&,std::vector<double>&);

    void	    setH(double);
    void	    setModel(const std::string&);
    void	    setModel(int);
    void	    setPi(double);
    void	    setPo(double);

    void	    setPressure(std::vector<double>);
    void	    setTime(std::vector<double>);

    Model	    model;

protected:
    virtual void    setVariables(std::map<std::string,double>&);

    double h;	///< Height (thickness)
    double pi;	///< Initial pressure
    double po;	///< Reservoir contact pressure

    SFluid fluid;
    SRock  rock;

    std::vector<double> pressure;   ///< Pressure historic
    std::vector<double> time;	    ///< Time historic

private:
    //void setcf(double);
};

#endif // CAQUIFER_H
