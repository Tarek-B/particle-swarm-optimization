#ifndef PROBLEM_H
#define PROBLEM_H
#include "Benchmarks.h"
#include <iostream>

class Problem{
	public:
		Problem(int dimension, int numF);
		~Problem();
		
		//Getters
		int getDimension() const;
		double getLowerLimit()const;
		double getUpperLimit()const;
		double getNumFunction()const;	
		
		//Setters
		void setNumFonction(int numF);
		
	private:
		int d_dimension;
	  	int d_numf;
	  	double d_lowerLimit;
	  	double d_upperLimit;
};


























