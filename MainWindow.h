#pragma once
#include "DrawPane.h"

class MainWindow : public wxFrame
{
	wxPanel* topPanel;
	DrawPane* dp;
	wxBoxSizer* dpSizer;
public:
	MainWindow();
};

