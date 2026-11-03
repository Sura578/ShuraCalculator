#include "logic.h"
#include <cmath>
void logic::logicadd(double numbera, double numberb, double* result)
{
    *result=numbera+numberb;
}
void logic::logicsubtract(double numbera, double numberb, double* result)
{
    *result=numbera-numberb;
}
void logic::logicsmultiply(double numbera, double numberb, double* result)
{
    *result=numbera * numberb;
}
void logic::logicdivide(double numbera, double numberb, double* result)
{
    *result=numbera/numberb;
}
void logic::logicgetpower(int numberx,int numbery, double* result)
{
    *result=1;
    for(int counting=1; counting<=numbery; counting++)
    {
        *result=*result*numberx;
    }
}
bool logic::logiccheckdivision(double numberb)
{
    return numberb!=0;
}
bool logic::logiccalculate(int option, double numbera,double numberb, double* result)
{
    switch(option)
    {
        case 1:
            logicadd(numbera,numberb,result);
            return true;
        case 2:
            logicsubtract(numbera,numberb,result);
            return true;
        case 3:
            logicsmultiply(numbera,numberb,result);
            return true;
        case 4:
            if(logiccheckdivision(numberb))
            {
                logicdivide(numbera,numberb,result);
                return true;
            }
            else
            {
                return false;
            }
        case 5:
            logicgetpower(static_cast<int>(numbera),static_cast<int>(numberb),result);
            return true;
        default:
            return false;
    }
}