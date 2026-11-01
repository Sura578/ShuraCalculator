#ifndef UI_H
#define UI_H
#include <iostream>
#include <string>
#include <limits>
using namespace std;
class ui
{
    public:
        void uiinvalidoption();
        void showtotal(double result);
        void uimenu();
        void uigoodbye();
        void unabledivision();
        double uigetnumber();
        int uigetpowery();
        int uigetpowerx();  
};
#endif