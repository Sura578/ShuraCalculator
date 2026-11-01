#include "ui.h"
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
    cout<<"3. MULTIPLY \n";
    cout<<"4. DIVIDE \n";
    cout<<"5. TO THE X POWER \n";
    cout<<"0. CLOSE \n";
}
void ui::uigoodbye()
{
    cout<<"Goodbye"<<endl;
}
void ui::unabledivision()
{
    cout<<"It is not possible to divide by 0"<<endl<<"Try again"<<endl;
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