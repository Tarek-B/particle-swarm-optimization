#include "Solution.h"
#include <ctime>

/*
	Constructeur � partir d'un probleme
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
	M�thode generant un reel aleatoire
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
		d_pbest[i]= d_pCurrent[i];	//Initialiser sa meilleure position comme �tant sa position initiale
	}

}
