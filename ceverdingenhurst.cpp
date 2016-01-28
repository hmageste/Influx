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

double CEverdingenHurst::calcWe( double t )
{
    const double deltapo = aquifer->getPi() - aquifer->getPo();
    SRock rock = aquifer->getRock();
    const double ct = rock.cf + aquifer->getFluid().cf;
    const double ro = aquifer->getRo();
    const double phi = rock.phi;
    const double mi = 1; // aquifer->getFluid().mi;
    td = 0.008362*k*t/(phi*mi*ct);
    return aquifer->getU()*deltapo*aquifer->getWd();
}
