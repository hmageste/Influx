#include <iostream>
#include <cmath>
#include "ccartertracy.h"
#include "ceverdingenhurst.h"
#include "cfetkovich.h"
#include "sfluid.h"
#include "cgnuplot.h"

using namespace std;

int main( int argc, char *argv[] )
{
    SFluid water;
    SRock rock;
    CRadialAquifer raquifer;
    raquifer.model = CAquifer::Sealed;

    cout << "Entry aquifer data file: ";
    string data_file( "exemplo6.4-Rosa.dat" );
    //cin >> data_file;
    raquifer.loadData( data_file );

    cout << "Entry aquifer's history file: ";
    string history_file( "exemplo6.4-Rosa.ods" );
    //cin >> history_file;
    raquifer.loadHistory( history_file );
    raquifer.setPo( 90.0 );

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

	resp = 1; // Remove after tests are ok
	switch( resp )
	{
	    case 1: method = new CEverdingenHurst( &raquifer );	break;
	    case 2: method = new CFetkovich( &raquifer );	break;
	    case 3: method = new CCarterTracy( &raquifer );	break;
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
