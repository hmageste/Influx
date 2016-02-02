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

    water.cf = 0; // 42.7e-6; // standard water compressibility
    water.viscosity = 1.0;
    rock.cf = 1e-5;
    rock.k = 100;
    rock.phi = 0.2;

    CRadialAquifer aquifer( rock, water );

    aquifer.model = CAquifer::Infinite;
    aquifer.setH( 1.0 );
    aquifer.setPi( 100.0 );
    aquifer.setPo( 90.0 );
    aquifer.setRe( 10000.0 );
    aquifer.setRo( 500.0 );
    aquifer.setTheta( 2*M_PI );

    vector<double> time, pressure;
    for ( int i = 0; i < 10; i++ )
    {
	time.push_back( 100*i );
	pressure.push_back( 200*i );
    }

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
	    cout << method->calcWe( 50.0 ) << endl;
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
