#include <iostream>
#include <vector>
#include "Solution.h"
#include "Problem.h"
#include "SetUpParams.h"

#define MYALGORITHM_H
#ifndef MYALGORITHM_H

/*
	Class representing our program
**/

class MyAlgorithm
  {
	private:
		// individuals in population
		vector<Solution*> d_solutions;   
		// A problem
		const Problem& d_pbm;
		// Parameters
		const SetUpParams& d_setup;
		// Upper fitness of individuals in population
		unsigned int d_upper_cost; 
 		//d_lower_cost; lower fitness of individuals in population
 		//vector<struct particle> _fitness_values;
	public:
		/*
		  Constructor with a problem and parameters
		**/
			MyAlgorithm(const Problem& pbm,const SetUpParams& setup); 	 //c'est fait 
		/*
		  Destructor
		**/
			~MyAlgorithm();		//c'est fait 

		friend ostream& operator<< (ostream& os, const MyAlgorithm& myAlgo);
		friend istream& operator>> (istream& is, MyAlgorithm& myAlgo);
		MyAlgorithm& operator= (const MyAlgorithm& myAlgo);
		const SetUpParams& setup() const;
	  	void initialize();
 
		// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
        void evaluate();
	 
	 	const vector<Solution*>& solutions() const;
		unsigned int upper_cost() const;
		unsigned int lower_cost() const;
		Solution& solution(const unsigned int index) const;
        vector<struct particle>&  fitness_values();
		double fitness(const unsigned int index) const;
         
		 
		double best_cost() const;
		double worst_cost() const;
		Solution& best_solution() const;
		Solution& worst_solution() const;
		 
		void evolution(int iter); /*makes an evolution step*/

};
  
  
#endif
