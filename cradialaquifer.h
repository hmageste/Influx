#ifndef CRADIALAQUIFER_H
#define CRADIALAQUIFER_H

#include "caquifer.h"

class CRadialAquifer : public CAquifer
{
public:
    CRadialAquifer();
    CRadialAquifer(const SRock&,const SFluid&);

    inline bool isLinear() const	{ return false; }

    void	manualEntry();

    double	getArea() const;
    double	getCt() const;
    double	getF() const;  ///< Reservoir angle (theta/2*pi)
    double	getRe() const;
    double	getRo() const;
    double	getTheta() const;

    double	getU() const;

    void	setRe(double);
    void	setRo(double);
    void	setTheta(double);

protected:
    void	setVariables(std::map<std::string,double>&);

private:
    double re;	    ///< Aquiver extern radius
    double ro;	    ///< Reservoir radius
    double theta;   ///< Aquifer circular sector
};

#endif // CRADIALAQUIFER_H
