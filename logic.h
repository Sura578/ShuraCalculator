#ifndef LOGIC_H
#define LOGIC_H
#include "ui.h"
#include <iostream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

class logic
{
    public:
        void logicadd(double numbera, double numberb, double* result);
        void logicsubtract(double numbera, double numberb, double* result);
        void logicsmultiply(double numbera, double numberb, double* result);
        void logicdivide(double numbera, double numberb, double* result);
        int logicgetoption(ui& interface);
        void logicgetpower(int numberx,int numbery, double* result);
        bool logiccheckdivision(double numberb);
};
#endif