#ifndef CCARTERTRACY_H
#define CCARTERTRACY_H

#include "cbaseclass.h"


class CCarterTracy : public CBaseClass
{
public:
	    CCarterTracy();
	    ~CCarterTracy();

    double  calcWe();

protected:
    double  red;
    double  u;
};

#endif // CCARTERTRACY_H
