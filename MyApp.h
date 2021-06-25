#pragma once
#include "ids.h"
#include "MainWindow.h"

class MyApp : public wxApp
{
	MainWindow* Mandelbrot;
public: 
	MyApp();
	bool OnInit();
};

DECLARE_APP(MyApp)