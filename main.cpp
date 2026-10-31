//A simple calculator program. made by ShuraKawai 23OCT26
#include <iostream>
#include <sstream>
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
        void unabledivition();
        double uigetnumber();
        int uigetpowery();
        int uigetpowerx();
};
void ui::uiinvalidoption()
{
    cout<<"Invalid digit, try again"<<endl;
}
void ui::showtotal(double result)
{
    //*just to debuggin*/cout<<numbera<<numberb;
    cout<<"THE RESULT OF THE OPERATION IS :"<<result;
}
void ui::uimenu()
{
    cout<<"\n====== CALCULATOR ======\n";
    cout<<"1. ADD \n";
    cout<<"2. SUBTRACT \n";
    cout<<"3. MULTIPLIE \n";
    cout<<"4. DIVIDE \n";
    cout<<"5. TO THE X POWER \n";
    cout<<"0. CLOSE \n";
}
void ui::uigoodbye()
{
    cout<<"Goodbye"<<endl;
}
void ui::unabledivition()
{
    cout<<"It iss not possible to divide by 0"<<endl<<"Try again"<<endl;
}
double ui::uigetnumber()
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
int ui::uigetpowery()
{
    int numbery;
    cout<<"Type the number Y to elevate "<<endl;
    while(!(cin>>numbery)||numbery<0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        uiinvalidoption();
    }
    return numbery;
}
int ui::uigetpowerx()
{
    int numberx;
    cout<<"X ^ Y"<<endl;
    cout<<"Type the number X to elevate "<<endl;
    while(!(cin>>numberx))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        uiinvalidoption();
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
int logicgetoption(ui& interface)
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
    ui interface;
    int option;
    do
    {
        interface.uimenu();
        option=logicgetoption(interface);
        switch(option)
        {
            case 1:
            {
                double numbera,numberb,result;
                numbera=interface.uigetnumber();
                numberb=interface.uigetnumber();
                logicadd(numbera,numberb,&result);
                interface.showtotal(result);
                break;
            }
            case 2:
            {
                double numbera,numberb,result;
                numbera=interface.uigetnumber();
                numberb=interface.uigetnumber();
                logicsubtract(numbera,numberb,&result);
                interface.showtotal(result);
                break;
            }
            case 3:
            {
                double numbera,numberb,result;
                numbera=interface.uigetnumber();
                numberb=interface.uigetnumber();
                logicsmultiplie(numbera,numberb,&result);
                interface.showtotal(result);
               break;
            }
            case 4:
            {
                double numbera,numberb,result;
                numbera=interface.uigetnumber();
                numberb=interface.uigetnumber();
                if(logiccheckdivition(numberb)==false)
                {
                    interface.unabledivition();
                    break;
                }
                logicdivide(numbera,numberb,&result);
                interface.showtotal(result);
               break;
            }
            case 5:
            {
                int numberx,numbery,result;
                numberx=interface.uigetpowerx();
                numbery=interface.uigetpowery();
                logicgetpower(numberx,numbery,&result);
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
int main()
{
    runmenu();
    return 0;
}