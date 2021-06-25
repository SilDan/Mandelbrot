#pragma once
#include <math.h>
class ComplexNumbers
{
	double x;
	double y;
public:
	ComplexNumbers(double X, double Y);
	void setZero();
	void setValues(double X, double Y);
	double getX();
	double getY();
	void add(ComplexNumbers* c);
	void times(ComplexNumbers* c);
	void calc(ComplexNumbers* c);
	void pow2();
	double absoluteValue();
};

