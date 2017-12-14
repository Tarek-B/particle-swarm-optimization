#ifndef PROBLEM_H
#define PROBLEM_H

#include <cmath>
#include <iostream>

class Problem
{	
	
	public:
		Problem();
	
		friend std::ostream& operator<< (std::ostream&, const Problem&);
		
		int dimension() const;
		/*
		double UpperLimit(int ) const;  ?
		double LowerLimit(int ) const;	? 
		
		Comment gérer les limites : dimension x donc [LIMIT]^x ? (vecteur?)
		à quel point faut-t-il les utiliser dans les fonctions correspondant?
		*/
	
		double Problem::Rosenbrock(/* X HELP!*/);
		double Problem::Rastrigin(/* X HELP!*/);
		double Problem::Ackley(/* X HELP!*/);
	
		double Schwefel(vector<double>& argument);
		double Schaffer(vector<double>& argument);
		double Weierstrass(vector<double>& argument);
		// le significat des arguments x1,...,Xn pour calculer le fitness?
		double calculateFitness(int functionNumber/* needed for the switch case, therefore (1 -> 6)*/);
	
		
	
	private:

		int _problemDimension;
		int _numFunction;
	

  };

double Problem::calculateFitness(int functionNumber) //I assume functionNumber is between 1 and 6 included
{	
	double fitnessValue;
 
	switch(functionNumber)
	{
		case 1 : fitnessValue = Rosenbrock(/*HEEEEEEELP: il faut un vecteur d'arguments X pour la fonction mais comment est  
							ce que ces arguments sont liés aux autres classes? Notamment la classe 
							solution?*/);
			break;
		case 2 : fitnessValue = Rastrigin(/* de même ici...*/)
			break;
			
		case 3 : fitnessValue = Ackley(/* de même ici...*/)
			break;
			
		case 4 : fitnessValue = Schwefel(/* de même ici...*/)
			break;
			
		case 5 : fitnessValue = Schaffer(/* de même ici...*/)
			break;
		
		case 6 : fitnessValue = Weierstrass(/* de même ici...*/)
			break;
	}
}


double Problem::Rosenbrock(/* X HELP!*/) //Où sont les bornes?
{
	double fitness = 0.0;

	for(int i = 0 ; i < nbVariablesEnX() -1 ; i++)
	{
	fitness += 100.0*pow(X[i+1] - pow(X[i],2), 2) + pow(1.0 - X[i], 2);
	}

	return(fitness+390);
}

double Problem::Rastrigin(/* X HELP!*/) //encore une fois, où sont les bornes?
{
	double fitness = 0.0;

	fitness = 10.0 * nbVariablesEnX();

	for(int i = 0; i < nbVariablesEnX() ; i++)
	{
		fitness+= pow(X[i], 2) - 10.0 * cos(2.0 * pi * X[i]);
	}

	return fitness;
}

double Problem::Ackley(/* X HELP!*/) 
{
	double fitness = 0.0;
	double firstMember = 0.0;
	double secondMember = 0.0;

	for(int i = 0; i < nbVariablesEnX() ; i++)
	{
		firstMember += pow(X[i],2);
		secondMember += cos(2*pi*X[i]);
	}

	fitness = -20*exp(-0.2*sqrt((1.0/nbVariablesEnX())*firstMember)) - exp((1.0/nbVariablesEnX())*secondMember) + 20 + exp(1);


	return (fitness);
}

double Problem :: Schwefel(vector<double>& argument)
{
	double fitness = 0.0;

	fitness = 418.9829 * NombreDeVariables();

	for(int i = 0 ; i < NombreDeVariables() ; i++)
	{
		fitness -= argument[i] * sin(sqrt(fabs(argument[i])));
	}

	return(fitness);
}

double Problem :: Schaffer(vector<double>& argument)
{
	double fitness = 0.0;

	for(int i = 0; i<NombreDeVariables()-1;i++)
	{
		fitness += 0.5 + (pow(sin(sqrt(pow(argument[i],2)+pow(argument[i+1],2))),2)+0.5)/pow((1+0.001*(pow(argument[i],2)+pow(argument[i+1],2))),2);
	}

	return(fitness);
}

double Problem :: Weierstrass(vector<double>& argument)
{
	double fitness = 0.0;
	double premierMembre = 0.0;
	double secondMembre = 0.0;

	for(int i=0;i<NombreDeVariables();i++)
	{
		for(int j = 0; j<=20;j++)
		{
			premierMembre+=pow(0.5,j)*cos(2*pi*pow(3,j)*(argument[i]+0.5));
		}
	}

	for(int i=0;i<=20;i++)
	{
		secondMembre+=pow(0.5,i)*cos(2*pi*pow(3,i)*0.5);
	}

	secondMembre*=NombreDeVariables();

	fitness = premierMembre - secondMembre;
	return(fitness);

}
  #endif











#ifndef PROBLEM_H
#define PROBLEM_H
#include "Benchmarks.h"
#include <iostream>

class Problem
{	
	
	public:
		Problem(benchmark* bench);
		~Problem();
		friend std::ostream& operator<< (std::ostream&, const Problem&);

		
		
		int dimension() const;
		double UpperLimit(int index) const;
		double LowerLimit(int index) const;
		benchmark* getBenchmark() const;
	
		
	
	private:

		benchmark* d_bench;
	

  };


  #endif
