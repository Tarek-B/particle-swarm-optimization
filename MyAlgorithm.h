#ifndef MYALGORITHM_H
#define MYALGORITHM_H


#include <iostream>
#include <vector>
#include "Solution.h"
#include "Problem.h"
#include "SetUpParams.h"




class MyAlgorithm
  {
	private:
			//Individuals of the population
		vector<Solution*> d_solutions;
			// Parameters
		const SetUpParams& d_setup; //c'est un objet qui contient le nbr_runs nb_evolution_steps population_size solution_size
			// Upper fitness of individuals in population
        int d_upper_cost;
			//The best particle of the population
 		Solution* d_gBest ;
 		Problem* d_pbm;
	public:
		/*#include "SetUpParams.h"
		Constructor with a paroblem and paramSETUPPARAMS_Heters
		**/
		MyAlgorithm( Problem& pbm, SetUpParams& setup);
		/*
		Destructor
		**/
		//~MyAlgorithm();

		//friend std::ostream& operator<< (std::ostream& os, const MyAlgorithm& myAlgo);
		//friend std::istream& operator>> (std::istream& is, MyAlgorithm& myAlgo);
		//MyAlgorithm& operator= (const MyAlgorithm& myAlgo);

		//Getters
		/*
		@Return the parameters
		**/
		SetUpParams setup() const;

		/*
		@Return the particles of the population
		**/
		std::vector<Solution*>& solutions();

		/*
		@Return the best particle of the population
		**/
		Solution& best_solution();

		/*
		@Return the particle in the position'index' in the population
		**/
		Solution& solution(int index); //retourne la valeur de l'index dans le tableau de solution

		/*
		@Return the best fitness of a particle
		**/
		unsigned int upper_cost() const; //retourne la meilleure valeur de get_fitness de solution

		/*
		@Return the best fitness of the best particle
		**/
		double best_cost() const; //

		/*
		@Initialize the particles of the population
		**/
	  	void initialize();

		/*
		@creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
        **/
		void evaluate();

		/*
		@makes an evolution step
		**/
		void evolution();

};


#endif
