#ifndef LOGIC_H
#define LOGIC_H
class logic
{
public:
    void logicadd(double numbera, double numberb, double* result);
    void logicsubtract(double numbera, double numberb, double* result);
    void logicsmultiply(double numbera, double numberb, double* result);
    void logicdivide(double numbera, double numberb, double* result);
    void logicgetpower(int numberx, int numbery, double* result);
    bool logiccheckdivision(double numberb);
    bool logiccalculate(int option, double numbera, double numberb, double* result);
};
#endif