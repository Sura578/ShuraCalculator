#include "logic.h"
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
int logic::logicgetoption(ui& interface)
{
    int option;
    string input;
    while (true)
    {
        cin>>input;
        stringstream ss(input);
        if(ss>>option && ss.eof())
        {
            return option;
        }
        else
        {
            interface.uiinvalidoption();
        }
    }
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
    if(numberb==0)
    return false;
    else
    return true;
}
void runmenu()
{
    logic math;
    ui interface;
    int option;
    do
    {
        interface.uimenu();
        option=math.logicgetoption(interface);
        switch(option)
        {
            case 1:
            {
                double numbera,numberb,result;
                numbera=interface.uigetnumber();
                numberb=interface.uigetnumber();
                math.logicadd(numbera,numberb,&result);
                interface.showtotal(result);
                break;
            }
            case 2:
            {
                double numbera,numberb,result;
                numbera=interface.uigetnumber();
                numberb=interface.uigetnumber();
                math.logicsubtract(numbera,numberb,&result);
                interface.showtotal(result);
                break;
            }
            case 3:
            {
                double numbera,numberb,result;
                numbera=interface.uigetnumber();
                numberb=interface.uigetnumber();
                math.logicsmultiply(numbera,numberb,&result);
                interface.showtotal(result);
               break;
            }
            case 4:
            {
                double numbera,numberb,result;
                numbera=interface.uigetnumber();
                numberb=interface.uigetnumber();
                if(math.logiccheckdivision(numberb)==false)
                {
                    interface.unabledivision();
                    break;
                }
                math.logicdivide(numbera,numberb,&result);
                interface.showtotal(result);
               break;
            }
            case 5:
            {
                int numberx,numbery;
                double result;
                numberx=interface.uigetpowerx();
                numbery=interface.uigetpowery();
                math.logicgetpower(numberx,numbery,&result);
                interface.showtotal(result);
                break;
            }
            case 0:
                interface.uigoodbye();
                break;
            default:
                interface.uiinvalidoption();
        }
    }while(option!=0);
}