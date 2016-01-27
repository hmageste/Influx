#include "cfetkovich.h"

CFetkovich::CFetkovich()
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

CFetkovich::~CFetkovich()
{}

double CFetkovich::calcWe()
{
/*
    We=0;
    for (int i=1; i<n; i++)
    {
	    We= Wei/pi*(pi*(1-We/Wei)-(p[i-1]+p[i])/2)*(1-pow(2.718,(-(J*pi*deltat[i])/Wei)));
    }
*/
    return 0.0;
}
