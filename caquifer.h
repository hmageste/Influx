#ifndef CAQUIFER_H
#define CAQUIFER_H


class CAquifer
{
public:
    CAquifer();

protected:
    double re; ///< Aquiver extern radius
    double ro; ///< Reservoir radius
    double cf; ///< Formation compressibility
    double h;  ///< Aquifer height
    double pi; ///< Aquifer intern pressure
    double po; ///< Aquifer extern pressure
    double wd; ///<
    double phi;///< Aquifer porosity
    double we;
    double wei;
};

#endif // CAQUIFER_H
