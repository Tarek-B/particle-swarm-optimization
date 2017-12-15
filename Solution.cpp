#include "Solution.h"
#include <ctime>
#include <cmath>
/*
	Constructeur à partir d'un probleme
**/
Solution :: Solution(const Problem& pbm) :
	d_pCurrent{},
	d_pBest{},
	d_Velocity{}
{
	d_pCurrent.resize(d_pbm.dimension());
	d_pBest.resize(d_pbm.dimension());
	d_Velocity.resize(d_pbm.dimension());
}

/*
	Constructeur par recopie
**/
Solution :: Solution fitness(const Solution& sol) : 
	d_pCurrent{sol.get_pCurrent()}, 
	d_pBest{sol.get_pBest()}, 
	d_Velocity{sol.get_Velocity()}, 
	d_currentFitness{sol.get_fitness()}, 
	d_pbm{sol.get_problem()}
	
{}

// Getters

vector<double>& Solution :: get_pCurrent()const
{
	return d_pCurrent;
}

vector<double>& Solution :: get_pBest()const
{
	return d_pBest;
}

vector<double>& Solution :: get_Velocity()const
{
	return d_Velocity;
}

double Solution :: get_currentFitness()const
{
	return d_currentFitness;
}

double Solution :: get_BestFitness()const
{
	return d_bestFitness;	
}

const Problem& Solution :: get_problem() const
{
	return d_pbm;
}
/*
	Méthode generant un reel aleatoire
**/
double Solution :: randomDouble(double min, double max)
{
	return rand() % (max-min)+min; 
}

/*
	Initialiser la position aleatoirement
**/
void Solution :: initializePosition()
{
	for(int i=0; i<d_pCurrent.size(); i++)
	{
		d_pCurrent[i]=randomDouble(d_pbm.LowerLimit(), d_pbm.UpperLimit());
	}
}

/*
	Initialiser la vitesse aleatoirement
**/
void Solution :: initializeVelocity()
{
	for(int i=0; i<d_Velocity.size(); i++)
	{
		d_Velocity[i]=randomDouble(d_pbm.LowerLimit(), d_pbm.UpperLimit());
	}
}

/*
	Initialiser la meilleure position
**/
void Solution ::initializeBestPosition()
{
	for(int i=0; i<d_pbest.size(); i++)
	{
		d_pbest[i]= d_pCurrent[i];	//Initialiser sa meilleure position comme étant sa position initiale
	}

}

/*
	Calculate the fitness of the current position of a particle
**/
double Solution :: currentFitness()
{
	switch(d_pbm.getNumFunction())
		case 1: //Rosenbrock
			for(int i=0; i<d_pCurrent.size()-1; i++)
				d_currentFitness += 100 * pow(d_pCurrent[i+1] - pow(d_pCurrent[i],2) , 2) + pow(1-d_pCurrent[i],2);
		case 2: //Rastrigin
			for(int i=0; i<d_pCurrent.size(); i++)
				d_currentFitness += pow(d_pCurrent[i],2)- 10* cos(2*pi*d_pCurrent[i]);
			d_currentFitness *= 10*d_p^Current.size();
		case 3:	//Ackley	
			double firstMember = 0.0;
			double secondMember = 0.0;
			for(int i=0; i<d_pCurrent.size(); i++)
			{
				firstMember += pow(d_pCurrent[i],2);
				secondMember += cos(2*pi*d_pCurrent[i]);
			}
			d_currentFitness = -20 * exp(-0.2*sqrt((1.0/d_pCurrent.size()*firstMember)) - exp((1.0/d_pCurrent.size())*secondMember) + 20 + exp(1);
		case 4: //Schwefel
			d_currentFitness = 418.9829* d_pCurrent.size();
			for(int i=0; i<d_pCurrent.size(); i++)
			{
				d_currentFitness -= d_pCurrent[i] * sin(sqrt(fabs(d_pCurrent[i])))
			}
		case 5:	//Schaffer
			for(int i=0; i<d_pCurrent.size(); i++)
				d_currentFitness += 0.5 + (pow(sin(sqrt(pow(d_pCurrent[i],2)+pow(d_pCurrent[i+1],2))),2)+0.5)/pow((1+0.001*(pow(d_pCurrent[i],2)+pow(d_pCurrent[i+1],2))),2);
		case 6:	//Weierstrass
			double premierMembre = 0.0;
			double secondMembre = 0.0;
			for(int i=0; i<d_pCurrent.size(); i++)
			{
				for(int j = 0; j<=20;j++)
					premierMembre+=pow(0.5,j)*cos(2*pi*pow(3,j)*(d_pCurrent[i]+0.5));
				for(int i=0;i<=20;i++)
					secondMembre+=pow(0.5,i)*cos(2*pi*pow(3,i)*0.5);
				secondMembre*=d_pCurrent.size();
			}
			d_currentFitness = premierMembre - secondMembre;	
}

/*
	Calculate the fitness of the best position of a particle
**/
double Solution :: bestFitness()
{
	switch(d_pbm.getNumFunction())
		case 1: //Rosenbrock
			for(int i=0; i<d_pBest.size()-1; i++)
				d_currentFitness += 100 * pow(d_pBest[i+1] - pow(d_pBest[i],2) , 2) + pow(1-d_pBest[i],2);
		case 2: //Rastrigin
			for(int i=0; i<d_pBest.size(); i++)
				d_currentFitness += pow(d_pBest[i],2)- 10* cos(2*pi*d_pBest[i]);
			d_currentFitness *= 10*d_pBest.size();
		case 3:	//Ackley	
			double firstMember = 0.0;
			double secondMember = 0.0;
			for(int i=0; i<d_pBest.size(); i++)
			{
				firstMember += pow(d_pBest[i],2);
				secondMember += cos(2*pi*d_pBest[i]);
			}
			d_currentFitness = -20 * exp(-0.2*sqrt((1.0/d_pBest.size()*firstMember)) - exp((1.0/d_pBest.size())*secondMember) + 20 + exp(1);
		case 4: //Schwefel
			d_currentFitness = 418.9829* d_pBest.size();
			for(int i=0; i<d_pBest.size(); i++)
			{
				d_currentFitness -= d_pBest[i] * sin(sqrt(fabs(d_pBest[i])))
			}
		case 5:	//Schaffer
			for(int i=0; i<d_pBest.size(); i++)
				d_currentFitness += 0.5 + (pow(sin(sqrt(pow(d_pBest[i],2)+pow(d_pBest[i+1],2))),2)+0.5)/pow((1+0.001*(pow(d_pBest[i],2)+pow(d_pBest[i+1],2))),2);
		case 6:	//Weierstrass
			double premierMembre = 0.0;
			double secondMembre = 0.0;
			for(int i=0; i<d_pBest.size(); i++)
			{
				for(int j = 0; j<=20;j++)
					premierMembre+=pow(0.5,j)*cos(2*pi*pow(3,j)*(d_pBest[i]+0.5));
				for(int i=0;i<=20;i++)
					secondMembre+=pow(0.5,i)*cos(2*pi*pow(3,i)*0.5);
				secondMembre*=d_pBest.size();
			}
			d_currentFitness = premierMembre - secondMembre;	
}
