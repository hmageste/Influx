#include "cfetkovich.h"

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

CFetkovich::CFetkovich()
    : aquifer(0)
{
/*
    for (int i = 0; i<n; i++)                               //Corre de 0 a n, pegando os valores de P
	{
		cout << "Pressao (" << i+1 << ") (kgf/cm2):";
	    cin >> p[i];
	    cin.get();
			if (i==0) pi=p[i];
	    }
	for (int i = 0; i<n; i++)                               //Corre de 0 a n, pegando os valores de P
	{
		cout << "Deltat (" << i+1 << ") (dias):";
	    cin >> deltat[i];
	    cin.get();
	    }

	Wei = (cf+cw)*(3.14*(pow(re,2)-pow(ro,2)*h*phi) )*pi;

	J = (2*3.14*1*k*h)/Mi*log(re/ro);
*/
}

CFetkovich::CFetkovich( CRadialAquifer* aq )
    : aquifer(aq)
{}

CFetkovich::~CFetkovich()
{}

double CFetkovich::calcWe( double t_ )
{
    double we( 0.0 );
    if ( !aquifer->isLinear() )
    {
	const double wi = aquifer->getVolume()*aquifer->getRock().phi;
	const double pi = aquifer->getPi();
	const double wei = aquifer->getCt()*wi*pi;

	vector<double> t, p;
	aquifer->getHistoric( t, p );

	vector<double> deltat( t.size(), 0.0 );
	adjacent_difference( t.begin(), t.end(), deltat.begin() );

	double pmedaq( pi ), pmedcont( pi );
	for ( int i = 1; i < t.size(); i++ )
	{
	    pmedcont = (p[i-1] + p[i])/2.0;
	    we += wei/pi * ( pmedaq - pmedcont) * (1 - pow(2.718, (-(getJ() * pi * deltat[i])/wei)));
	    pmedaq = pi*(1-we/wei);
	}
    }
    return we;
}

double CFetkovich::getJ() const
{
    double j( 0.0 );
    if ( aquifer->model == CAquifer::Sealed )
    {
	j = 2.0*M_PI*aquifer->getF()*aquifer->getRock().k*aquifer->getH() / \
	    aquifer->getFluid().viscosity / ( log(aquifer->getRe()/aquifer->getRo()) - 0.75 );
    }
    else if ( aquifer->model == CAquifer::Constant )
    {
	j = 2.0*M_PI*aquifer->getF()*aquifer->getRock().k*aquifer->getH() / \
	    aquifer->getFluid().viscosity / log(aquifer->getRe()/aquifer->getRo());
    }
    else if ( aquifer->model == CAquifer::Infinite )
	cerr << "Fetkovich method is not valid for infinite flow model." << endl;

    return 0.05255*j/(2*M_PI);
}
