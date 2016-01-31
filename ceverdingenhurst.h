#ifndef CEVERDINGENHURST_H
#define CEVERDINGENHURST_H

#include "cbaseclass.h"
#include "cradialaquifer.h"


class CEverdingenHurst : public CBaseClass
{
public:
		    CEverdingenHurst();
		    CEverdingenHurst(CRadialAquifer*);
		    ~CEverdingenHurst();

    double	    calcWe(double);

protected:

private:
    CRadialAquifer* aquifer;

    double	    getWd(double,double);

// The fucntions below are defined in the laplace field
// and aren't meant to be used

    //double l_infinite_radial_aquifer(double,double);
    //double l_sealed_radial_aquifer(double,double);
    //double l_constant_radial_aquifer(double,double);
};

#endif // CEVERDINGENHURST_H
