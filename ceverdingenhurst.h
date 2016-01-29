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
    double	    rd; ///< dimensionless radius
    double	    wd;	///< Dimensionless cumulative water influx
    double	    we;	///< Cumulative water influx
    double	    wei; ///< Initial water in place

    double	    getWd(double,double);
};

#endif // CEVERDINGENHURST_H
