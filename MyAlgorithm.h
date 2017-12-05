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
		
		vector<Solution*> d_solutions;   //vecteur de pointeur sur des particules. Il représente la population
		vector<struct particle> _fitness_values; //vecteur de structure particule (index, fitness)
		// Parameters
				
		const SetUpParams& d_setup; //c'est un objet qui contient le nbr_runs nb_evolution_steps population_size solution_size
		unsigned int d_upper_cost; // Upper fitness of individuals in population
 		unsigned int d_lower_cost; //lower fitness of individuals in population
 		
	public:
		
			MyAlgorithm(const Problem& pbm,const SetUpParams& setup); 	 //c'est fait 
			~MyAlgorithm();		//c'est fait 

		friend ostream& operator<< (ostream& os, const MyAlgorithm& myAlgo);
		friend istream& operator>> (istream& is, MyAlgorithm& myAlgo);
		MyAlgorithm& operator= (const MyAlgorithm& myAlgo);
		const SetUpParams& setup() const;
	  	void initialize();
 
		// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
        	void evaluate();
	 
	 	const vector<Solution*>& solutions() const; //retourne le vecteur de solution (particules)
		unsigned int upper_cost() const; //retourne la meilleure valeur de get_fitness de solution
		unsigned int lower_cost() const; //retourne le min de get_fitness de solution
		Solution& solution(const unsigned int index) const; //retourne la valeur de l'index dans le tableau de solution
        	vector<struct particle>&  fitness_values(); // on en a pas besoin parce qu'on a enlever le vecteur de struct particule
		double fitness(const unsigned int index) const; // pareil on en a pas besoin parce qu'on se sert pas du vector particule
         
		 
		double best_cost() const; //
		double worst_cost() const; //
		Solution& best_solution() const; //
		Solution& worst_solution() const; //
		 
		void evolution(int iter); /*makes an evolution step*/

};
  
  
#endif
