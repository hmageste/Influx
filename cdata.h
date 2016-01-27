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
    double u;
    double td;
    double deltapo;
    double red;
    double j;
};

#endif // CDATA_H
