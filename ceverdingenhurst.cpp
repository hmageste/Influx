#include "ceverdingenhurst.h"

#include <cmath>
#include <boost/math/special_functions/bessel.hpp>

using namespace boost::math;
using namespace std;


CEverdingenHurst::CEverdingenHurst()
{}

CEverdingenHurst::CEverdingenHurst( CRadialAquifer* aq )
    : aquifer(aq)
{}

CEverdingenHurst::~CEverdingenHurst()
{}

// temporary declaration to allow use of the functions
//****************************************************
double l_infinite_radial_aquifer(double,double);
double l_sealed_radial_aquifer(double,double);
double l_constant_radial_aquifer(double,double);
double gavsteh(double (*)(double,double),double,double,int);
//****************************************************

double CEverdingenHurst::getWd( double td, double red )
{
    if ( aquifer->model == CAquifer::Infinite )
    {
	return gavsteh( &l_infinite_radial_aquifer, td, red, 10) ;
    }
    else if ( aquifer->model == CAquifer::Sealed )
    {
	return l_sealed_radial_aquifer( td, red );
    }
    else if ( aquifer->model == CAquifer::Constant )
    {
	return l_constant_radial_aquifer( td, red );
    }
    else
	return 0.0;
}

double CEverdingenHurst::calcWe( double t )
{
    const double deltapo = aquifer->getPi() - aquifer->getPo();
    SRock rock = aquifer->getRock();
    const double ct = rock.cf + aquifer->getFluid().cf;
    const double ro = aquifer->getRo();
    const double phi = rock.phi;
    const double mi = aquifer->getFluid().viscosity;
    const double k = aquifer->getRock().k;
    const double td = 0.008362*k*t/(phi*mi*ct*ro*ro);
    const double red = aquifer->getRe()/ro;
    const double wd = getWd( td, red );
    return aquifer->getU()*deltapo*wd;
}

// Laplace functions
typedef double (*function)(int,double);
function I = &cyl_bessel_i, K = &cyl_bessel_k;

double l_infinite_radial_aquifer( double u, double )
{
    const double arg1 = sqrt(u);
    return K(1,arg1) / ( pow(u,3.0/2.0)*K(0,arg1) );
    //return cyl_neumann( 1, sqrt(u) )/( pow(u,3.0/2.0)*cyl_neumann( 0, sqrt(u) ) );
    //return bessel_k1( sqrt(u), BOOST_MATH_DOMAIN_ERROR_POLICY )/( pow(u,3.0/2.0)*bessel_k0( sqrt(u), BOOST_MATH_DOMAIN_ERROR_POLICY ) );
}

double l_sealed_radial_aquifer( double u, double red )
{
    const double arg1 = sqrt(u) ;
    const double arg2 = red*arg1;

    return ( I(1,arg2)*K(1,arg1) - I(1,arg1)*K(1,arg2) ) / ( pow(u,3.0/2.0)*( I(0,arg1)*K(1,arg2) + I(1,arg2)*K(0,arg1) ) );
}

double l_constant_radial_aquifer( double u, double red )
{
    const double arg1 = sqrt(u) ;
    const double arg2 = red*arg1;

    return (  I(0,arg2)*K(1,arg1) + I(1,arg1)*K(0,arg2) ) / ( pow(u,3.0/2.0)*( I(0,arg2)*K(0,arg1) - I(0,arg1)*K(0,arg2) ) );
}

int factorial( int n )
{
    if ( n < 2 )
	return 1;

    return n*factorial(--n);
}

// Numerical Inverse Laplace Transform using Gaver-Stehfest method
double gavsteh( double (*func)(double,double), double t, double red, int L )
{
    const int nn2 = L/2;
    std::vector<double> v;

    for ( int n = 1; n <= L; n++ )
    {
	double z( 0 );
	for ( int k = floor((n+1)/2); k <= min(n,nn2); k++ )
	{
	    z = z + ( pow(k,nn2)*factorial(2*k) )/( factorial(nn2-k)*factorial(k)*factorial(k-1)*factorial(n-k)*factorial(2*k - n) );
	}
	v.push_back( z*pow(-1,(n+nn2)) );
    }

    double sum = 0.0;
    double ln2_on_t = log(2.0) / t;
    for ( int n = 1; n <= L; n++ )
    {
	const double p = n*ln2_on_t;
	sum = sum + v[n]*func(p,red);
    }

    return sum*ln2_on_t;
}

/*
function ilt=gavsteh(funname,t,L)
nn2 = L/2;
nn21= nn2+1;

for n = 1:L
    z = 0.0;
    for k = floor( ( n + 1 ) / 2 ):min(n,nn2)
	z = z + ((k^nn2)*factorial(2*k))/ ...
	    (factorial(nn2-k)*factorial(k)*factorial(k-1)* ...
	    factorial(n-k)*factorial(2*k - n));
    end
    v(n)=(-1)^(n+nn2)*z;
end

sum = 0.0;
ln2_on_t = log(2.0) / t;
for n = 1:L
    p = n * ln2_on_t;
    sum = sum + v(n) * feval(funname,p);
end
	ilt = sum * ln2_on_t;
*/

/*
function ilt = gavsteh(funname, t, reD, L)
nn2 = L/2;

v = zeros(1,L); %CS

for n = 1:L
    z = 0.0;
    for k = floor( (n+1)/2 ) : min (n,nn2)
	z = z + ((k^nn2)*factorial(2*k))/ ...
	    (factorial(nn2-k)*factorial(k)*factorial(k-1)* ...
	    factorial(n-k)*factorial(2*k - n));
    end
    v(n)=(-1)^(n+nn2)*z;
end

sum = 0.0;
ln2_on_t = log(2.0) ./ t;
for n = 1:L
    p = n * ln2_on_t;
    sum = sum + v(n) * feval(funname,p,reD);
end

ilt = sum .* ln2_on_t;
*/

