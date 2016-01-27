#ifndef CRADIALAQUIFER_H
#define CRADIALAQUIFER_H

#include "caquifer.h"

class CRadialAquifer : public CAquifer
{
public:
    CRadialAquifer();

    inline bool isLinear() const	{ return false; }

    void	manualEntry();

private:
    double re; ///< Aquiver extern radius
    double ro; ///< Reservoir radius
};

#endif // CRADIALAQUIFER_H
