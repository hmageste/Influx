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
};

#endif // CEVERDINGENHURST_H
