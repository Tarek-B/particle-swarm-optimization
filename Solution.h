#include <iostream>
#include <vector>
#include "Problem.h"

#define SOLUTION_H
#ifndef SOLUTION_H

/*
	Class representing a solution (a particle)
**/

class Solution{
  public:
  	/*
	  Constructor with a Problem
	  @param pbm a problem
	**/
    	Solution (const Problem& pbm);
    /*
	  Constructor par recopie
	**/
		Solution (const Solution& sol);

	
	//getters
	/*
	@ return the coordinates of the current position of a particle
	**/
	vector<double>& get_pCurrent()const;
	
	/*
	@return the coordinates of the best position of a particle  
	**/
	vector<double>& get_pBest()const;
	
	/*
	@return the coordinates of the velocity of a particle
	**/
	vector<double>& get_Velocity()const;
	
	/*
	@ return the fitness of a particle
	**/
	double get_fitness()const;
	
	/*
	@ return a problem 
	**/
	const Problem& get_problem() const;
	
	//Initialization
	/*
	  Generate reel random
	  @param min 
	  @param max
	**/
		double randomDouble(double min, double max);
	/*
	  Initialize the coordinates of the position of a particle randomly 
	  
	**/
		void initializePosition();
	/*
	  Initialize the coordinates of the velocity of a particle randomly 
	  
	**/
		void initializeVelocity();
	/*
	  Initialize the coordinates of the best position of a particle  
	**/
		void initializeBestPosition();
		
	/*
	@calculate the fitness of a particle 
	**/
	double fitness(); 
	
	/*
	@calculate the new position of a particle
	**/
	void newPosition();
	/*
	@calculate the new velocity of a particle
	**/
	void newVelocity(const vector<double>& gBest);
  private:
   		 //Vector of the coordinates of the current position
    vector<double> d_pCurrent;
    	//Vector of the coordinates of the best position
    vector<double> d_pbest;
    	//Vector of the coordinates of the current velocity
    vector<double> d_Velocity;
   		 //Fitness of a particul
    double d_currentFitness;
    	//Un probleme donne (par rapport aux six fonctions de tests donnees dans le pdf)
    const Problem& d_pbm;
};

#endif
