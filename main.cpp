//A simple calculator program. made by ShuraKawai 23OCT26
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;
void uiinvalidoption()
{
    cout<<"Invalid digit, try again"<<endl;
}

void showtotal(double result)
{
    //*just to debuggin*/cout<<numbera<<numberb;
    cout<<"THE RESULT OF THE OPERATION IS :"<<result;
}
void uimenu()
{
    cout<<"\n====== CALCULATOR ======\n";
    cout<<"1. ADD \n";
    cout<<"2. SUBTRACT \n";
    cout<<"3. MULTIPLIE \n";
    cout<<"4. DIVIDE \n";
    cout<<"5. TO THE X POWER \n";
    cout<<"0. CLOSE \n";
}
void uigoodbye()
{
    cout<<"Goodbye"<<endl;
}
void unabledivition()
{
    cout<<"It iss not possible to divide by 0"<<endl<<"Try again"<<endl;
}
double uigetnumber()
{
    double number;
    cout<<"TYPE NUMBER"<<endl;
    while(!(cin>>number))
    {
        cout<<"invalid input. Please enter a valid number"<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}
int uigetpowery()
{
    int numbery;
    cout<<"Type the number Y to elevate "<<endl;
    while(!(cin>>numbery)||numbery<0)
    {
        uiinvalidoption();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return numbery;
}
int uigetpowerx()
{
    int numberx;
    cout<<"X ^ Y"<<endl;
    cout<<"Type the number X to elevate "<<endl;
    while(!(cin>>numberx))
    {
        uiinvalidoption();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return numberx;
}
void logicadd(double numbera, double numberb, double* result)
{
    *result=numbera+numberb;
}
void logicsubtract(double numbera, double numberb, double* result)
{
    *result=numbera-numberb;
}
void logicsmultiplie(double numbera, double numberb, double* result)
{
    *result=numbera * numberb;
}
void logicdivide(double numbera, double numberb, double* result)
{
    *result=numbera/numberb;
}
int logicgetoption()
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
            uiinvalidoption();
        }
    }
}
void logicgetpower(int numberx,int numbery, int* result)
{
    *result=1;
    for(int counting=1; counting<=numbery; counting++)
    {
        *result=*result*numberx;
    }
}
bool logiccheckdivition(double numberb)
{
    if(numberb==0)
    return false;
    else
    return true;
}
void runmenu()
{
    int option;
    do
    {
        uimenu();
        option=logicgetoption();
        switch(option)
        {
            case 1:
            {
                double numbera,numberb,result;
                numbera=uigetnumber();
                numberb=uigetnumber();
                logicadd(numbera,numberb,&result);
                showtotal(result);
                break;
            }
            case 2:
            {
                double numbera,numberb,result;
                numbera=uigetnumber();
                numberb=uigetnumber();
                logicsubtract(numbera,numberb,&result);
                showtotal(result);
                break;
            }
            case 3:
            {
                double numbera,numberb,result;
                numbera=uigetnumber();
                numberb=uigetnumber();
                logicsmultiplie(numbera,numberb,&result);
                showtotal(result);
               break;
            }
            case 4:
            {
                double numbera,numberb,result;
                numbera=uigetnumber();
                numberb=uigetnumber();
                if(logiccheckdivition(numberb)==false)
                {
                    unabledivition();
                    break;
                }
                logicdivide(numbera,numberb,&result);
                showtotal(result);
               break;
            }
            case 5:
            {
                int numberx,numbery,result;
                numberx=uigetpowerx();
                numbery=uigetpowery();
                logicgetpower(numberx,numbery,&result);
                showtotal(result);
                break;
            }
            case 0:
                uigoodbye();
                break;
            default:
                uiinvalidoption();
        }
    }while(option!=0);
}
int main()
{
    runmenu();
    return 0;
}