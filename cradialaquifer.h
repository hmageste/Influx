#ifndef CRADIALAQUIFER_H
#define CRADIALAQUIFER_H

#include "caquifer.h"

class CRadialAquifer : public CAquifer
{
public:
    CRadialAquifer();

    inline bool isLinear() const	{ return false; }
    void	calcU();

    void	manualEntry();

private:
    double re;	    ///< Aquiver extern radius
    double ro;	    ///< Reservoir radius
    double theta;   ///< Aquifer circular sector
    double f;	    ///< Reservoir angle (theta/2*pi)
    double ct;	    ///< total compressibility (ct = cf + cw)
};

#endif // CRADIALAQUIFER_H
