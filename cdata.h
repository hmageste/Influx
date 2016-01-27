#ifndef CDATA_H
#define CDATA_H


class CData
{
public:
	    CData();
	    ~CData();
    void    ManualEntry();
    void    FileEntry();

protected:

private:
    double re; ///< aquiver extern radius
    double ro; ///< reservoir radius
    double cf; ///< Formation compressibility
    double cw; ///< Water compressibility
    double h;  ///< Aquifer height
    double f;  ///<
    double k;  ///< Water permeability
    double ko; ///< Oil permeability
    double Mi; ///< Water viscosity
    double pi; ///< Aquifer intern pressure
    double po; ///< Aquifer extern pressure
    double Wd; ///<
    double t;  ///< Time
    double phi;///< Aquifer porosity
    double We;
    double Wei;
    double U;
    double td;
    double deltapo;
    double red;
    double J;
};

#endif // CDATA_H
