#ifndef SOLUTION_H
#define SOLUTION_H


#include <iostream>
#include <vector>
#include "Problem.h"

using std::vector;

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
	vector<double> get_pCurrent()const;

	/*
	@return the coordinates of the best position of a particle
	**/
	vector<double> get_pBest()const;

	/*
	@return the coordinates of the velocity of a particle
	**/
	vector<double> get_Velocity()const;

	/*
	@ return the fitness of the position of a particle
	**/
	double get_currentFitness()const;

	/*
	@ return the fitness of the best position of a particle
	**/
	double get_BestFitness()const;

	/*
	@Return the size
	**/
	int size()const;
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
		Initialize all the coordinates
	**/
		void initialize();
	/*
	@calculate the current fitness of a particle
	**/
	double currentFitness();

	/*
	@calculate the fitness oh the best position of a particle
	**/
	double bestFitness();

	/*
	@calculate the new position
	**/
	void newPosition();

	/*
	@calculate the new velocity
	**/
	void newVelocity(const vector<double>& gBest);

	/*
	@update the coordinates of the best position
	**/
	void updateBestPosition();

	/*
	@print the fitness of particles
	**/
	void print(std::ostream& ost);
  private:
   		 //Vector of the coordinates of the current position
    vector<double> d_pCurrent;
    	//Vector of the coordinates of the best position
    vector<double> d_pBest;
    	//Vector of the coordinates of the current velocity
    vector<double> d_Velocity;
   		 //Fitness of a position a particul
    double d_currentFitness;
       		 //Fitness of the best position of a particul
    double d_bestFitness;
    	//Un probleme donne (par rapport aux six fonctions de tests donnees dans le pdf)
    const Problem& d_pbm;
};

#endif
