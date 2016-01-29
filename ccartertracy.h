#ifndef CCARTERTRACY_H
#define CCARTERTRACY_H

#include "cbaseclass.h"
#include "cradialaquifer.h"


class CCarterTracy : public CBaseClass
{
public:
        CCarterTracy();
        CCarterTracy(CRadialAquifer*);
        ~CCarterTracy();

    void    setAquifer(CRadialAquifer*);
    CRadialAquifer* getAquifer() const;

    double  calcWe(double);

protected:
    double  red;

private:
    CRadialAquifer* aquifer;
};

#endif // CCARTERTRACY_H
