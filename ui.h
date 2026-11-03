#ifndef UI_H
#define UI_H
#include <wx/wx.h>
#include "logic.h"
class ui : public wxFrame
{
public:
    ui();
    void uiinvalidoption();
    void showtotal(double result);
    void uigoodbye();
    void unabledivision();

private:
    logic math;
    wxTextCtrl* numbera;
    wxTextCtrl* numberb;
    wxChoice* operation;
    wxStaticText* result;
    void uimenu();
    double uigetnumber(wxTextCtrl* input);
    void calculate(wxCommandEvent& event);
};
#endif