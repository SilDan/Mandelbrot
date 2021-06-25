#pragma once
#include "ComplexNumbers.h"
class Sequence
{
	ComplexNumbers* z;
public:
	Sequence();
	bool checkInRange(ComplexNumbers* c);
	void iterate(ComplexNumbers* c, int Anzahl, int& n);
};

