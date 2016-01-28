#include <iostream>
#include <cstddef>
#include "ccartertracy.h"
#include "ceverdingenhurst.h"
#include "cfetkovich.h"
#include "sfluid.h"
#include "cgnuplot.h"

using namespace std;

int main(int argc, char *argv[])
{
    SFluid water;
    CRadialAquifer aquifer;
    // fulfill aquifer information

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
	cin >> resp; cin.get();

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
	    method->calcWe( 0.0 );

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
