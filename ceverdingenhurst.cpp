#include "ceverdingenhurst.h"

#include <cmath>

CEverdingenHurst::CEverdingenHurst()
{
/*
    ct=cf+cw;

    U=2*3,14*f*phi*ct*h*(pow(ro,2));

    td= (k*t)/(phi*Mi*ct*(pow(L,2)));

    deltapo = pi - po;

    Wd = (k*sqrt(Mi))/(Mi*(pow(Mi,3/2))ko);
*/
}

CEverdingenHurst::CEverdingenHurst( CRadialAquifer* aq )
    : aquifer(aq)
{}

CEverdingenHurst::~CEverdingenHurst()
{}

double CEverdingenHurst::calcWe()
{
    const double deltapo = aquifer->getPi() - aquifer->getPo();
    return aquifer->getU()*deltapo*aquifer->getWd();
}
