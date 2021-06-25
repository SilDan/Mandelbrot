#include "MyApp.h"
#include "DrawPane.h"

IMPLEMENT_APP(MyApp)

BEGIN_EVENT_TABLE(DrawPane, wxPanel)
EVT_PAINT(DrawPane::paintEvent)
END_EVENT_TABLE()

MyApp::MyApp()
{
}

bool MyApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	Mandelbrot = new MainWindow();
	Mandelbrot->Show(true);

	return true;
}