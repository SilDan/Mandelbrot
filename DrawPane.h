#pragma once
#include "ids.h"
#include "Sequence.h"
#include <tuple>
#include <wx/event.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

using namespace std;

class DrawPane : public wxPanel
{
	Sequence* brot;
	ComplexNumbers* z;
	double xScal;
	double yScal;
	int w;
	int h;
	int n; 
	int Anzahl;
	//colors
	tuple<int, int, int> black;
	tuple<int, int, int> white;
	tuple<int, int, int> hellGruen;
	tuple<int, int, int> dunkelGruen;
	tuple<int, int, int> hellRot;
	tuple<int, int, int> dunkelRot;
	tuple<int, int, int> aquamarine;
	tuple<int, int, int> dunkelBlau;
	tuple<int, int, int> tuerkis;
	tuple<int, int, int> orange;
	tuple<int, int, int> gelb;
	tuple<int, int, int> violet;

public:
	DrawPane(wxPanel* parent);
	void paintEvent(wxPaintEvent& evt);
	void initColors();
	void paintNow();
	void scal(double xS, double yS);
	void initRender(wxDC& dc);
	wxPen getBlackPen(int m);
	void render(wxDC& dc);
	void drawMandelbrotSet(wxDC& dc);
	void drawPoint(wxDC& dc, int iw, int ih);
	void setValueAndIterate(int iw, int ih);
	void drawDivergencePoint(wxDC& dc, int iw, int ih);
	void drawConvergencePoint(wxDC& dc, int iw, int ih);
	void drawAxis(wxDC& dc);
	double getYScaled(int ih, int h);
	double getXScaled(int iw, int w);
	wxPen getDottedBlackPen();
	wxPen defineColor(tuple<int, int, int> RGBColor, int thickness);
	wxColour createColorFromRGB(int n, tuple<int, int, int> RGBColor);
	wxPen defineColor(int n, tuple<int, int, int> RGBColor, int thickness);
	wxColour createColorFromRGB(int r, int g, int b);
	DECLARE_EVENT_TABLE()
};

