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
    double cw; ///< Water compressibility
    double ct; ///< Total compressibility
    double f;  ///<
    double k;  ///< Water permeability
    double ko; ///< Oil permeability
    double Mi; ///< Water viscosity
    double t;  ///< Time
    double td;
    double deltapo;
    double j;

private:
};

#endif // CBASECLASS_H
