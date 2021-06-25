#include "DrawPane.h"

DrawPane::DrawPane(wxPanel* parent) : wxPanel(parent, window::ids::DP, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE)
{
    brot = new Sequence();
    z = new ComplexNumbers(0.,0.);
    yScal = 3.0;
}

void DrawPane::initColors()
{
    //colors
    black = make_tuple(0, 0, 0);
    white = make_tuple(1, 1, 1);
    hellGruen = make_tuple(0, 255, 0);
    dunkelGruen = make_tuple(0, 170, 0);
    hellRot = make_tuple(255, 0, 0);
    dunkelRot = make_tuple(170, 0, 0);
    aquamarine = make_tuple(220, 250, 255);
    dunkelBlau = make_tuple(0, 0, 200);
    tuerkis = make_tuple(0, 200, 200);
    orange = make_tuple(10, 5, 0);
    gelb = make_tuple(5, 5, 0);
    violet = make_tuple(16,3,8);
}

void DrawPane::paintEvent(wxPaintEvent& evt)
{

    wxPaintDC dc(this);
    render(dc);
}


void DrawPane::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void DrawPane::scal(double xS, double yS)
{
    xScal = yScal * xS / yS;
}

void DrawPane::initRender(wxDC& dc)
{
    wxSize dpSize = this->GetSize();
    w = dpSize.GetWidth();
    h = dpSize.GetHeight();
    n = 0;
    Anzahl = 40;
    dc.SetPen(getBlackPen(2));
    dc.SetDeviceOrigin(w / 2, h / 2);
    dc.SetAxisOrientation(true, true);
}

wxPen DrawPane::getBlackPen(int m)
{
    return wxPen(wxColor(0, 0, 0), m);
}

void DrawPane::render(wxDC& dc)
{
    initRender(dc);
    drawMandelbrotSet(dc);
    drawAxis(dc);
}

void DrawPane::drawMandelbrotSet(wxDC& dc)
{
    for (int ih = -h / 2; ih < h / 2; ih++)
        for (int iw = -w / 2; iw < w / 2; iw++)
        {
            setValueAndIterate(iw, ih);
            drawPoint(dc, iw, ih);
        }
}

void DrawPane::drawPoint(wxDC& dc, int iw, int ih)
{
    if (n == Anzahl)
        drawConvergencePoint(dc, iw, ih);
    else
        drawDivergencePoint(dc, iw, ih);
}

void DrawPane::setValueAndIterate(int iw, int ih)
{
    z->setValues(getXScaled(iw, w), getYScaled(ih, h));
    brot->iterate(z, Anzahl, n);
}

void DrawPane::drawDivergencePoint(wxDC& dc, int iw, int ih)
{
    dc.SetPen(defineColor(n,violet,2));
    dc.DrawLine(iw, ih, iw, ih);
}

void DrawPane::drawConvergencePoint(wxDC& dc, int iw, int ih)
{
    dc.SetPen(getBlackPen(2));
    dc.DrawLine(iw, ih, iw, ih);
}

void DrawPane::drawAxis(wxDC& dc)
{
    dc.SetPen(getDottedBlackPen());
    dc.DrawLine(0, -h / 2, 0, h / 2);
    dc.DrawLine(-w / 2, 0, w / 2, 0);
}

double DrawPane::getYScaled(int ih, int h)
{
    return yScal * (double)ih / (double)h;
}

double DrawPane::getXScaled(int iw, int w)
{
    return xScal * (double)iw / (double)w;
}

wxPen DrawPane::getDottedBlackPen()
{
    return wxPen(createColorFromRGB(100,white), 1, wxPENSTYLE_DOT);
}

wxPen DrawPane::defineColor(int n,tuple<int,int,int> RGBColor, int thickness)
{
    
    return wxPen(createColorFromRGB(n,RGBColor), thickness);
}

wxColour DrawPane::createColorFromRGB(int n, tuple<int, int, int> RGBColor)
{
    int r = get<0>(RGBColor);
    int g = get<1>(RGBColor);
    int b = get<2>(RGBColor);
    return wxColour(n*r, n*g, n*b);
}
