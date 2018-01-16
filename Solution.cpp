#include "Solution.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
const double pi = 3.14;
/*
	@Constructor from a problem
**/
Solution :: Solution(const Problem& pbm) : d_pCurrent{}, d_pBest{}, d_Velocity{}, d_pbm{pbm}
{
	d_pCurrent.resize(d_pbm.getDimension());
	d_pBest.resize(d_pbm.getDimension());
	d_Velocity.resize(d_pbm.getDimension());
}



/*
	Constructor by recopying
**/
Solution :: Solution(const Solution& sol) : d_pCurrent{sol.get_pCurrent()}, d_pBest{sol.get_pBest()}, d_Velocity{sol.get_Velocity()},d_currentFitness{sol.get_currentFitness()},d_pbm{sol.get_problem()}

{}




// Getters
/*
	@return the current position
**/
vector<double> Solution :: get_pCurrent()const
{
	return d_pCurrent;
}



/*
	@return the best postion
**/
vector<double> Solution :: get_pBest()const
{
	return d_pBest;
}



/*
	@return the velocity
**/
vector<double> Solution :: get_Velocity()const
{
	return d_Velocity;
}




/*
	@return the current fitness
**/
double Solution :: get_currentFitness()const
{
	return d_currentFitness;
}



/*
	@return the best fitness
**/
double Solution :: get_BestFitness()const
{
	return d_bestFitness;
}




/*
	@return the problem
**/
const Problem& Solution :: get_problem() const
{
	return d_pbm;
}




/*
	@return the solution size
**/
int Solution :: size()const
{
	return d_pbm.getDimension();
}



/*
	@function that generate a random float
**/
double Solution :: randomDouble(double min, double max)
{
	return (rand()/(double)RAND_MAX) * (max-min)+min;
}



/*
	@intialize the population randomly 
**/
void Solution :: initializePosition()
{
	for(int i=0; i<d_pCurrent.size(); i++)
	{
		d_pCurrent[i]=randomDouble(d_pbm.getLowerLimit(), d_pbm.getUpperLimit());
	}
}



/*
	@intialize the velocity randomly
**/
void Solution :: initializeVelocity()
{
	for(int i=0; i<d_Velocity.size(); i++)
	{
		d_Velocity[i]=randomDouble(d_pbm.getLowerLimit(), d_pbm.getUpperLimit());
	}
}




/*
	@initialize the best position
**/
void Solution ::initializeBestPosition()
{
	for(int i=0; i<d_pBest.size(); i++)
	{
		d_pBest[i]= d_pCurrent[i];	//Initialiser sa meilleure position comme étant sa position initiale
	}

}



/*
	Initialiser une particule
**/
void Solution :: initialize()
{
	initializePosition();
	initializeBestPosition();
	initializeVelocity();
	currentFitness();
	bestFitness();
}



/*
	@calculate the current fitness
**/
double Solution :: currentFitness()
{
	switch(d_pbm.getNumFunction())
	{
		case 1: //Rosenbrock
			for(int i=0; i<d_pCurrent.size()-1; i++)
				d_currentFitness += 100 * pow(d_pCurrent[i+1] - pow(d_pCurrent[i],2) , 2) + pow(1-d_pCurrent[i],2);
			return d_currentFitness;
		case 2: //Rastrigin
			for(int i=0; i<d_pCurrent.size(); i++)
				d_currentFitness += pow(d_pCurrent[i],2)- 10* cos(2*pi*d_pCurrent[i]);
			d_currentFitness *= 10*d_pCurrent.size();
			return d_currentFitness;
		case 3:	//Ackley
		    {
                double firstMember = 0.0;
                double secondMember = 0.0;
                for(int i=0; i<d_pCurrent.size(); i++)
                {
                    firstMember += pow(d_pCurrent[i],2);
                    secondMember += cos(2*pi*d_pCurrent[i]);
                }
                d_currentFitness = -20 * exp(-0.2*sqrt((1.0/d_pCurrent.size()*firstMember)) - exp((1.0/d_pCurrent.size())*secondMember) + 20 + exp(1));
                return d_currentFitness;
		    }

		case 4: //Schwefel
			d_currentFitness = 418.9829* d_pCurrent.size();
			for(int i=0; i<d_pCurrent.size(); i++)
			{
				d_currentFitness -= d_pCurrent[i] * sin(sqrt(fabs(d_pCurrent[i])));
			}
			return d_currentFitness;
		case 5:	//Schaffer
			for(int i=0; i<d_pCurrent.size(); i++)
				d_currentFitness += 0.5 + (pow(sin(sqrt(pow(d_pCurrent[i],2)+pow(d_pCurrent[i+1],2))),2)+0.5)/pow((1+0.001*(pow(d_pCurrent[i],2)+pow(d_pCurrent[i+1],2))),2);
			return d_currentFitness;
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
			return d_currentFitness;
	}

}



/*
	@calculate the best fitness
**/
double Solution :: bestFitness()
{
	switch(d_pbm.getNumFunction())
	{
		case 1: //Rosenbrock
			for(int i=0; i<d_pBest.size()-1; i++)
				d_bestFitness += 100 * pow(d_pBest[i+1] - pow(d_pBest[i],2) , 2) + pow(1-d_pBest[i],2);
			return d_bestFitness;
		case 2: //Rastrigin
			for(int i=0; i<d_pBest.size(); i++)
				d_currentFitness += pow(d_pBest[i],2)- 10* cos(2*pi*d_pBest[i]);
			d_bestFitness *= 10*d_pBest.size();
			return d_bestFitness;
		case 3:	//Ackley
		    {
                double firstMember = 0.0;
                double secondMember = 0.0;
                for(int i=0; i<d_pBest.size(); i++)
                {
                    firstMember += pow(d_pBest[i],2);
                    secondMember += cos(2*pi*d_pBest[i]);
                }
                d_bestFitness = -20 * exp(-0.2*sqrt((1.0/d_pBest.size()*firstMember)) - exp((1.0/d_pBest.size())*secondMember) + 20 + exp(1));
                return d_bestFitness;
		    }

		case 4: //Schwefel
			d_currentFitness = 418.9829* d_pBest.size();
			for(int i=0; i<d_pBest.size(); i++)
			{
				d_bestFitness -= d_pBest[i] * sin(sqrt(fabs(d_pBest[i])));
			}
			return d_bestFitness;
		case 5:	//Schaffer
			for(int i=0; i<d_pBest.size(); i++)
				d_bestFitness += 0.5 + (pow(sin(sqrt(pow(d_pBest[i],2)+pow(d_pBest[i+1],2))),2)+0.5)/pow((1+0.001*(pow(d_pBest[i],2)+pow(d_pBest[i+1],2))),2);
			return d_bestFitness;
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
			d_bestFitness = premierMembre - secondMembre;
			return d_bestFitness;
	}

}



/*
	@calculate the new position
**/
void Solution :: newPosition()
{
	for(int i=0; i<d_pCurrent.size(); i++)
		d_pCurrent[i] += d_Velocity[i];
}



/*
	Calculer the new velocity
**/
void Solution :: newVelocity(const vector<double>& gBest)
{
	double r1=randomDouble(0,1);
	double r2=randomDouble(0,1);
	double c1=1.4;
	double c2=1.4;
	for(int i=0; i<d_Velocity.size(); i++)
		d_Velocity[i] += c1*r1*(d_pBest[i]-d_pCurrent[i])+c2*r2*(gBest[i]-d_pCurrent[i]);
}



/*
	@update the new best position
**/
void Solution :: updateBestPosition()
{
    if(d_currentFitness<d_bestFitness) // comparer avant de mettre à jour   MINIMISATION
	{
	    for(int i=0; i<d_pBest.size(); i++)
        {
            d_pBest[i]= d_pCurrent[i];
        }

    }
}



/*
	@print the fitness of particles
**/
void Solution :: print(std::ostream& ost)
{
	ost<<"fitness courante: "<<get_currentFitness()<<std::endl;
	ost<<"Meilleure fitness: "<<get_BestFitness()<<std::endl;
}
