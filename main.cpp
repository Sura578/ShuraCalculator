//A simple calculator program. made by ShuraKawai 23OCT26
#include <wx/wx.h>
#include "ui.h"
class ShurasCalculator : public wxApp
{
public:
    bool OnInit() override
    {
        ui* window = new ui();
        window->Show(true);
        return true;
    }
};
wxIMPLEMENT_APP(ShurasCalculator);