#include <iostream>
#include <vector>
#include "Solution.h"
#include "Problem.h"
#include "SetUpParams.h"

#define MYALGORITHM_H
#ifndef MYALGORITHM_H



class MyAlgorithm
  {
	private:
			//Individuals of the population
		vector<Solution*> d_solutions;  
			// Parameters			
		const SetUpParams& d_setup; //c'est un objet qui contient le nbr_runs nb_evolution_steps population_size solution_size
			// Upper fitness of individuals in population
		unsigned int d_upper_cost; 
			//The best particle of the population
 		Solution* d_gBest ; 
	public:
		/*
		Constructor with a paroblem and parameters
		**/
		MyAlgorithm(const Problem& pbm,const SetUpParams& setup);
		/*
		Destructor
		**/ 
		~MyAlgorithm();	

		friend ostream& operator<< (ostream& os, const MyAlgorithm& myAlgo);
		friend istream& operator>> (istream& is, MyAlgorithm& myAlgo);
		MyAlgorithm& operator= (const MyAlgorithm& myAlgo);
		
		//Getters
		/*
		@Return the parameters
		**/
		SetUpParams& setup() const;
		
		/*
		@Return the particles of the population
		**/
		vector<Solution*>& solutions() const;
		
		/*
		@Return the best particle of the population
		**/
		Solution& best_solution() const;
		
		/*
		@Return the particle in the position'index' in the population
		**/
		Solution& solution(const unsigned int index) const; //retourne la valeur de l'index dans le tableau de solution

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
		void evolution(int iter); 

};
  
  
#endif
