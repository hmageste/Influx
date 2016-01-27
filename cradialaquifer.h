#ifndef CRADIALAQUIFER_H
#define CRADIALAQUIFER_H

#include "caquifer.h"

class CRadialAquifer : public CAquifer
{
public:
    CRadialAquifer();
private:
    double re; ///< Aquiver extern radius
    double ro; ///< Reservoir radius
};

#endif // CRADIALAQUIFER_H
