#ifndef CRADIALAQUIFER_H
#define CRADIALAQUIFER_H

#include "caquifer.h"

class CRadialAquifer : public CAquifer
{
public:
    CRadialAquifer();

    inline bool isLinear() const	{ return false; }

    void	manualEntry();
    void	fileEntry();

    double	getCt() const;
    double	getF() const;  ///< Reservoir angle (theta/2*pi)
    double	getRe() const;
    double	getRo() const;
    double	getTheta() const;

    double	getU() const;

    void	setRe(double);
    void	setRo(double);
    void	setTheta(double);

private:
    double re;	    ///< Aquiver extern radius
    double ro;	    ///< Reservoir radius
    double theta;   ///< Aquifer circular sector
};

#endif // CRADIALAQUIFER_H
