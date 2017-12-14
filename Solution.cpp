#include "Solution.h"
#include <ctime>

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

double Solution :: get_fitness()const
{
	return d_currentFitness;
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

double Solution :: fitness()
{
	switch(d_pbm.getNumFonction())
		case 1:
			d_pbm.getBench()->
}

/*
	Calculer les coordonnées de la nouvelle position d'une particule
	x’= x+ v’
**/
void Solution :: newPosition()
{
	for(int i=0; i<d_pCurrent.size();i++)
	{
		d_pCurrent[i]+=d_Velocity[i];
	}
}

/*
	Calculer les coordonnées de la nouvelle vitesse d'une particule
	v’= v+ c1.r1(pBest - x)+ c2.r2(gBest - x)
**/
void Solution :: newVelocity(const vector<double>& gBest)
{
	double r1=randomDouble(0,1);
	double r2=randomDouble(0,1);
	
	for(int i=0; i<d_Velocity.size(); i++)
	{
		d_Velocity[i]+= c1*r1 (d_pBest[i]- d_pCuurent[i]) + c2*r2(gBest[i] - d_pCuurent[i]);
	}
}

}
