#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>

class Problem{
	public:
		/*
			Constructor with the dimension and the number function
		**/
		Problem(int dimension, int numF);

		/*
			Automatically created but there is no usage of dynamic allocation, therefore
			doesn't need to exist
		**/
		//~Problem();

		//Getters
		/*
			@ return the dimension of the current problem
		**/
		int getDimension() const;

		/*
			@ return the lower limit of the current problem
		**/
		double getLowerLimit()const;

		/*
			@ return the upper limit of the current problem
		**/
		double getUpperLimit()const;

		/*
			@ return the function's (problem) number
		**/
		int getNumFunction()const;

		//Setters
		/*
			Sets the problem's number:
				1 = Rosenbrock
				2 = Rastrigin
				3 = Ackley
				4 = Schwefel
				5 = Schaffer
				6 = Weierstrass
			@param numF
		**/
		void setNumFonction(int numF);

	private:
		// problem's dimension
		int d_dimension;
		// problem's number
	  	int d_numf;
	  	double d_lowerLimit;
	  	double d_upperLimit;
};

#endif
























