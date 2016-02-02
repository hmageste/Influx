#include <iostream>
#include <cmath>
#include "ccartertracy.h"
#include "ceverdingenhurst.h"
#include "cfetkovich.h"
#include "sfluid.h"
#include "cgnuplot.h"

using namespace std;

int main(int argc, char *argv[])
{
    SFluid water;
    SRock rock;

    water.cf = 42.7e-6; // standard water compressibility
    water.viscosity = 0.3;
    rock.cf = 56.9e-6;
    rock.k = 100;
    rock.phi = 0.2;

    CRadialAquifer aquifer( rock, water );

    aquifer.model = CAquifer::Sealed;
    aquifer.setH( 18.3 );
    aquifer.setPi( 246.13 );
    aquifer.setPo( 0.0 ); // Not constant in this example
    aquifer.setRe( 6096.0 );
    aquifer.setRo( 762.0 );
    aquifer.setTheta( 2*M_PI );

    // Only C++11
    //vector<double> time = { 0, 100, 200, 300, 400, 500 };
    //vector<double> pressure = { 246.13, 245.43, 244.44, 243.18, 242.19, 240.51};

    const double time_[] = { 0, 100, 200, 300, 400, 500 };
    const double pressure_[] = { 246.13, 245.43, 244.44, 243.18, 242.19, 240.51};
    vector<double> time( time_, time_+6 );
    vector<double> pressure( pressure_, pressure_+6 );

    aquifer.setPressure( pressure );
    aquifer.setTime( time );

    CBaseClass* method = NULL;

    int resp = 0;
    do
    {
	cout << "\n\nDigite o método de resolução"
	     << "\n1 - Everdingen & Hurst"
	     << "\n2 - Fetkovich"
	     << "\n3 - Carter-Tracy"
	     << "\n0 - Sair"
	     << "\nOpcao numero: ";
	//cin >> resp; cin.get();

	resp = 2; // Remove after tests are ok
	switch( resp )
	{
	    case 1: method = new CEverdingenHurst( &aquifer );	break;
	    case 2: method = new CFetkovich( &aquifer );	break;
	    case 3: method = new CCarterTracy( &aquifer );	break;
	    case 0: return 0;
	    default: cerr << "\nModelo incorreto! Escolha um modelo válido!" << endl; break;
	}

	if ( method != NULL )
	{
	    cout << method->calcWe( 500.0 ) << endl;
	    cin.get(); cin.get();

	    // Plotar com GnuPlot We x t
	    /*
	    CGnuplot gnuplot (x, y, "Pontos Observados", "points", "x", "y");

	    gnuplot.Style("lines");
	    gnuplot.PlotEquation( pobj->FuncaoAprox().erase(0,4) ); // plota função aproximadora sem
								    // os 4 caracteres iniciais: "y = "
	    */
	    delete method;
	    method = NULL;
	}
	getchar();
    } while (resp != 0);

    return 0;
}
