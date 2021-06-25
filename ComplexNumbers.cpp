#include "ComplexNumbers.h"

ComplexNumbers::ComplexNumbers(double X, double Y)
{	
	x = X;
	y = Y;
}

void ComplexNumbers::setZero()
{
	x = 0.0;
	y = 0.0;
}

void ComplexNumbers::setValues(double X, double Y)
{
	x = X;
	y = Y;
}

double ComplexNumbers::getX()
{
	return x;
}

double ComplexNumbers::getY()
{
	return y;
}

void ComplexNumbers::calc(ComplexNumbers* c)
{
	double X = x;
	x = x * x - y * y + c->getX();
	y = X * y + y * X+ c->getY();
}


double ComplexNumbers::absoluteValue()
{
	return x*x+y*y;
}