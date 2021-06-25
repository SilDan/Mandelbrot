#include "Sequence.h"

Sequence::Sequence()
{
	z = new ComplexNumbers(0.,0.);
}

bool Sequence::checkInRange(ComplexNumbers* z)
{
	return  z->absoluteValue()<=100.;
}

void Sequence::iterate(ComplexNumbers* c, int Anzahl, int &counter)
{
	z->setZero();
	counter = 0;
	while (counter < Anzahl && checkInRange(z))
	{
		z->calc(c);
		counter++;
	}
}