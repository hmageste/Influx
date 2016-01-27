#ifndef CFETKOVICH_H
#define CFETKOVICH_H

#include "cbaseclass.h"
#include "cradialaquifer.h"

class CFetkovich : public CBaseClass
{
public:
	    CFetkovich();
	    CFetkovich(CRadialAquifer*);
	    ~CFetkovich();

    double  calcWe();

protected:

private:
    CRadialAquifer* aquifer;

};

#endif // CFETKOVICH_H
