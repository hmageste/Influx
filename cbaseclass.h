#ifndef CBASECLASS_H
#define CBASECLASS_H


class CBaseClass
{
public:
		    CBaseClass();
		    ~CBaseClass();

    virtual double  calcWe() = 0;
    virtual void    manualEntry();
    virtual void    fileEntry();

protected:
    double re; ///< Aquiver extern radius
    double ro; ///< Reservoir radius
    double cf; ///< Formation compressibility
    double cw; ///< Water compressibility
    double h;  ///< Aquifer height
    double f;  ///<
    double k;  ///< Water permeability
    double ko; ///< Oil permeability
    double Mi; ///< Water viscosity
    double pi; ///< Aquifer intern pressure
    double po; ///< Aquifer extern pressure
    double wd; ///<
    double t;  ///< Time
    double phi;///< Aquifer porosity
    double we;
    double wei;
    double td;
    double deltapo;
    double j;
    double ct;

private:
};

#endif // CBASECLASS_H
