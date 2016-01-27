#include "ccartertracy.h"

#include <cmath>

CCarterTracy::CCarterTracy()
    : red(0.0)
    , u(0.0)
{
    //red=re/ro;

    //u=2*3.14*f*phi*ct*h*(pow(ro,2));
}

CCarterTracy::CCarterTracy( CRadialAquifer* aq )
    : aquifer(aq)
    , red(0.0)
    , u(0.0)
{}

CCarterTracy::~CCarterTracy()
{}

void CCarterTracy::setAquifer( CRadialAquifer* aq )
{
    aquifer = aq;
}

CRadialAquifer* CCarterTracy::getAquifer() const
{
    return aquifer;
}

double CCarterTracy::calcWe()
{
/*
    double td_anterior = 0.0;
    double We_anterior = 0.0;

    double pd_;
    double tda;

    double dt = t/(p.size() - 1);

    for ( int j=1; j<p.size(); j++ )
    {
	    td = k*j*dt/(phi*Mi*ct*pow(L,2));

	    tda = td/(3.14*(red*red - 1.0));

	    if ( tda < 0.1 )
	    {
		    pd = (log(td) + 0.80907)/2.0;
		    pd_ = 1.0/(2.0*td);
	    }
	    else
	    {
		    pd = 2.0*td/red/red + log(red) - 0.75;
		    pd_ = 2.0/red/red;
	    }

	    We = We_anterior + (U*(p[0] - p[j]) - We_anterior*pd_)/(pd - td_anterior*pd_)*(td - td_anterior);

	    We_anterior = We;
	    td_anterior = td;
    }
*/

    return 0.0;
}
