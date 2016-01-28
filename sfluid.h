#ifndef SFLUID_H
#define SFLUID_H

struct SFluid
{
    double cf;
    double viscosity;
};

struct SRock
{
    double cf;	///< Formation compressibility
    double phi;	///< Porosity
    double k;	///< Permeability
};

#endif // SFLUID_H
