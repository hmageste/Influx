#include <iostream>
#include "ccartertracy.h"
#include "ceverdingenhurst.h"
#include "cfetkovich.h"
#include "sfluid.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    CRadialAquifer aquifer;
    CFetkovich fetkovich( &aquifer );
    CCarterTracy cartertracy( &aquifer );
    CEverdingenHurst everdingenHurst( &aquifer );
    SFluid water;

    return 0;
}
