#include "Problem.h"


/*
	@Constructor
**/
Problem :: Problem(int dimension, int numF) : d_dimension{dimension} , d_numf{numF}
{
	switch(d_numf)
	{
        case 1:
			d_lowerLimit = -2.048;
			d_upperLimit = 2.048;
			break;
		case 2:
			d_lowerLimit = -5.12;
			d_upperLimit = 5.12;
			break;
		case 3:
			d_lowerLimit = -5;
			d_upperLimit = 5;
			break;
		case 4:
			d_lowerLimit = -500;
			d_upperLimit = 500;
			break;
		case 5:
			d_lowerLimit = -100;
			d_upperLimit = 100;
			break;
		case 6:
			d_lowerLimit = -2;
			d_upperLimit =  2;
			break;
	}

}



/*
	@return the dimension
**/
int Problem :: getDimension() const
{
	return d_dimension;
}



/*
	@return the lower limit
**/
double Problem :: getLowerLimit()const
{
	return d_lowerLimit;
}



/*
	return the upper limit
**/
double Problem :: getUpperLimit()const
{
	return d_upperLimit;
}



/*
	@ return the num of the function
**/
int Problem :: getNumFunction()const
{
	return d_numf;
}



/*
	@affect a num to a function
**/
void Problem :: setNumFonction(int numF)
{
	d_numf = numF;
}



























