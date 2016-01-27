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

    double  calcWe();

protected:

private:
    CRadialAquifer* aquifer;
};

#endif // CEVERDINGENHURST_H
