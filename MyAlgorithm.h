#ifndef MYALGORITHM_H
#define MYALGORITHM_H


#include <iostream>
#include <vector>
#include "Solution.h"
#include "Problem.h"
#include "SetUpParams.h"




class MyAlgorithm
  {
		public:
		/*#include "SetUpParams.h"
		Constructor with a paroblem and paramSETUPPARAMS_Heters
		**/
		MyAlgorithm( Problem& pbm, SetUpParams& setup);
		
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
		double best_solution();

		/*
		@Return the particle in the position'index' in the population
		**/
		Solution& solution(int index);

		/*
		@Return the best fitness of a particle
		**/
		void find_gBest();

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
		!!!!! checks if the current position of the particule (any) is better than all previouses and then updates it
        **/
		void update_pBest();

		/*
		@makes an evolution step
		**/
		void evolution();
        void print_population(std::ostream& ost);

		void run();
		void execute();
		
		private:
			//Individuals of the population
		vector<Solution*> d_solutions; 
			// Parameters
		const SetUpParams& d_setup;
			// Upper fitness of individuals in population
        float d_upper_cost;
			//The best particle of the population
 		Solution* d_gBest;
 		Problem* d_pbm;
};


#endif
