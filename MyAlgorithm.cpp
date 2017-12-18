#include <iostream>
#include <vector>
#include "Solution.h"
#include "Problem.h"
#include "SetUpParams.h"
#include <limits>

/*
	Constructor
**/
MyAlgorithm::MyAlgorithm(Problem* pbm,const SetUpParams& setup) : //d_pbm{pbm},
		 d_setup{&setup}, 
         d_solutions{}, 
		 d_upper_cost{0},
{
	for(int i=0;i<d_setup->population_size();i++)
	{
		d_solutions.push_back(new Solution{d_pbm});
	}
}


/*
	Destructor
**/
MyAlgorithm::~MyAlgorithm()
{
	for(int i=0;i<d_solutions.size();i++)
	{
		delete d_solution[i];
	}
}

/***********Focnction qui renvoie 
un pointeur vers un objet de 
paramètres de la classe SetUpParams
*************************************/

SetUpParams& MyAlgorithm::setup() const
{
	return *d_setup;
}

/*********Fonction qui renvoie le tableau des solutions
ableau de pointeurs sur particules*********************/

vector<Solution*>& MyAlgorithm::solutions() const
{
	return d_solutions;
}

/*
@Return the best solution of the population
**/
Solution MyAlgorithm :: best_solution() 
{
 	d_gBest = d_solutions[0] ; 
 	for (int i=1 ; i<d_solutions.size() ; i++ )
 	{
 		if (d_gBest->get_currentFitness() < d_solutions[i].get_currentFitness())
 		{
 			d_gBest = d_solutions[i] ; 
		}
	}
}

/*
@Return the particle in the position'index' in the population
**/
Solution& solution(const unsigned int index) const
{
	return d_solutions[index];
}

/*
@Return the best fitness of a particle
**/
unsigned int MyAlgorithm::upper_cost() const
{
  float max=std::numeric_limits<float>::min();
  int position;
  for(int i=0;i<d_solutions.size();i++)
  { 
      if(max<d_solutions[i]->get_fitness()) 
      {
        max = d_solutions[i]->get_fitness();
        position = i;
      }
	return d_solutions[position]->get_fitness();
}

/*
@Initialize all the individuals of the population
**/
void MyAlgorithme::initialize()
{
	for(int i = 0; i < d_solution.size(); i++)
	{
		d_solution[i].initialize();	
	}
}

// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
void MyAlgorithm::evaluate()
 {
   for (int i=0 ; i<d_solutions.size(); i++) 
   {
   	if (d_solutions[i].currentFitness()< d_solutions[i].BestFitness())
   	{
   		d_solution[i].updateBestPosition () ; 
    }
   }
 }
 
 void MyAlgorithm :: evolution () 
 {
 	int j=0 ; 
 	while (j< d_setup->nb_evolution_steps())
 	{
 		for (int i=0; i<d_solutions.size(); i++)
 		{
 			d_solutions[i].newVelocity(d_gBest.get_pCurrent()) ; 
 			d_solutions[i].newPosition() ; 
 			evaluate() ; 
 			d_gBest = best_solution() ;  		
 		
		}
		j++ ; 
	}
 	
 }
 

  

