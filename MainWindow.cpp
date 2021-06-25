#include "MainWindow.h"

MainWindow::MainWindow() : 
	wxFrame(nullptr,window::ids::MainWindowID, _("Mandelbrot"), wxPoint(-1, -1))
{
	int xScal = 1300;
	int yScal = 700;
	topPanel = new wxPanel(this, window::ids::TopPanelID);
	topPanel->SetBackgroundColour(wxColor(200, 200, 200));
	dpSizer = new wxBoxSizer(wxHORIZONTAL);
	dpSizer->SetMinSize(wxSize(xScal, yScal));
	dp = new DrawPane(topPanel);
	dp->initColors();
	dp->scal((double)xScal, (double)yScal);
	dpSizer->Add(dp, 1, wxALL|wxEXPAND, 5);
	topPanel->SetSizer(dpSizer);
	Centre();
}
