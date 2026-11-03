#include "ui.h"
#include <stdexcept>
ui::ui()
:wxFrame(nullptr, wxID_ANY, "Calculadora", wxPoint(30, 30), wxSize(400, 300))
{
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    //Tittle
    wxStaticText* title = new wxStaticText(panel, wxID_ANY, "ShuraKalculator");
    title->SetFont(wxFontInfo(18).Bold());
    //Getting number A
    mainSizer->Add(new wxStaticText(panel, wxID_ANY, "Enter the first number:"),0, wxALL, 5);
    numbera=new wxTextCtrl(panel, wxID_ANY);
    mainSizer->Add(numbera,0,wxEXPAND|wxALL,5);
    //Getting number B
    mainSizer->Add(new wxStaticText(panel, wxID_ANY, "Enter the second number:"),0, wxALL, 5);
    numberb=new wxTextCtrl(panel, wxID_ANY);
    mainSizer->Add(numberb,0,wxEXPAND|wxALL,5);
    //Menu of operations
    mainSizer->Add(new wxStaticText(panel, wxID_ANY, "Choose an operation:"),0, wxALL, 5);
    operation = new wxChoice(panel, wxID_ANY);
    operation->Append("Addition");
    operation->Append("Subtraction");
    operation->Append("Multiplication");
    operation->Append("Division");
    operation->Append("Power X^Y");
    operation->SetSelection(0);
    mainSizer->Add(operation,0,wxEXPAND|wxALL,5);
    //Button to calculate
    wxButton* calculateButton = new wxButton(panel, wxID_ANY, "Calculate");
    mainSizer->Add(calculateButton,0, wxEXPAND | wxALL | 5);
    calculateButton->Bind(wxEVT_BUTTON, &ui::calculate, this);
    //Result
    result = new wxStaticText(panel,wxID_ANY, "Result: ");
    result->SetFont(wxFontInfo(15).Bold());
    mainSizer->Add(result,0,wxALL,5);
    panel->SetSizer(mainSizer);
    mainSizer->Insert(0, title, 0, wxALIGN_CENTER | wxALL, 10);
}
void ui::uiinvalidoption()
{
    wxMessageBox("Invalid option. Please select a valid operation.", "Error", wxOK | wxICON_ERROR);
}
void ui::showtotal(double total)
{
    result->SetLabel("The result is: " + std::to_string(total));
}
void ui::uigoodbye()
{
    Close(true);
}
void ui::unabledivision()
{
    wxMessageBox("Error: Division by Zero. \n Try again.","Division Error", wxOK | wxICON_ERROR);
}
double ui::uigetnumber(wxTextCtrl* input)
{
    double number;
    if(!input->GetValue().ToDouble(&number))
    {
        throw std::invalid_argument("Invalid input. Please enter a valid number.");
    }
    return number;
}
void ui::calculate(wxCommandEvent& event)
{
    double numberA, numberB, answer;
    if(!numbera->GetValue().ToDouble(&numberA))
    {
        uiinvalidoption();
        return;
    }
    if(!numberb->GetValue().ToDouble(&numberB))
    {
        uiinvalidoption();
        return;
    }
    int option = operation->GetSelection() + 1;
    if(!math.logiccalculate(option, numberA, numberB, &answer))
    {
        if(option == 4)
        {
            unabledivision();
        }
        else
        {
            uiinvalidoption();
        }
        return;
    }
    showtotal(answer);
}