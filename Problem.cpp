#include "Problem.h"

Problem :: Problem(int dimension, int numF) : d_dimension{dimension} , d_numf{numF} 
{
	switch(d_numf)
		case 1:
			d_lowerLimit = -2.048;
			d_upperLimit = 2.048;
		case 2:
			d_lowerLimit = -5.12;
			d_upperLimit = 5.12;
		case 3:
			d_lowerLimit = -5;
			d_upperLimit = 5;
		case 4:
			d_lowerLimit = -500;
			d_upperLimit = 500;
		case 5:
			d_lowerLimit = -100;
			d_upperLimit = 100;
		case 6:
			d_lowerLimit = -2;
			d_upperLimit =  2;
}

int Problem :: getDimension() const
{
	return d_dimension;
}

double Problem :: getLowerLimit()const
{
	return d_lowerLimit;
}

double Problem :: getUpperLimit()const
{
	return d_upperLimit;
}

double problem :: getNumFunction()const
{
	get d_numf;
}
void Problem :: setNumFonction(int numF)
{
	d_numf = numF;
}



























