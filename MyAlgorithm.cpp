#include "MyAlgorithm.h"
#include "Solution.h"
#include "Problem.h"
#include "SetUpParams.h"
#include <iostream>
#include <vector>
#include <limits>

/*
	Constructor
**/
MyAlgorithm::MyAlgorithm( Problem& pbm, SetUpParams& setup) : d_pbm{&pbm},d_setup{setup},d_solutions{},d_upper_cost{}
{
	for(int i=0;i<d_setup.population_size();i++)
	{
		d_solutions.push_back(new Solution{*d_pbm});
	}
}


/*
	Destructor
**/
/*MyAlgorithm::~MyAlgorithm()
{
	for(int i=0;i<d_solutions.size();i++)
	{
	//	delete d_solution[i];
	}
}*/

/***********Focnction qui renvoie
un pointeur vers un objet de
paramètres de la classe SetUpParams
*************************************/

SetUpParams MyAlgorithm::setup() const
{
	return d_setup;
}

/*********Fonction qui renvoie le tableau des solutions
ableau de pointeurs sur particules*********************/

std::vector<Solution*>& MyAlgorithm::solutions()
{
	return d_solutions;
}

/*
@Return the best solution of the population
**/
Solution& MyAlgorithm :: best_solution()
{
 	d_gBest = d_solutions[0] ;
 	for (int i=1 ; i<d_solutions.size() ; i++ )
 	{
 		if (d_gBest->get_currentFitness() < d_solutions[i]->get_currentFitness())
 		{
 			d_gBest = d_solutions[i] ;
		}
	}
}

/*
@Return the particle in the position'index' in the population
**/
Solution& MyAlgorithm::solution(int index)
{
	return *d_solutions[index];
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
      if(max<d_solutions[i]->get_currentFitness())
      {
        max = d_solutions[i]->get_currentFitness();
        position = i;
      }
	return d_solutions[position]->get_currentFitness();
  }
}
/*
@Initialize all the individuals of the population
**/
void MyAlgorithm::initialize()
{
	for(int i = 0; i < d_solutions.size(); i++)
	{
		d_solutions[i]->initializePosition();
	}
}

// creates a array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
void MyAlgorithm::evaluate()
 {
   for (int i=0 ; i<d_solutions.size(); i++)
   {
   	if (d_solutions[i]->currentFitness()< d_solutions[i]->bestFitness())
   	{
   		d_solutions[i]->updateBestPosition() ;
    }
   }
 }

 void MyAlgorithm :: evolution ()
 {
 	int j=0 ;
 	while (j< d_setup.nb_evolution_steps())
 	{
 		for (int i=0; i<d_solutions.size(); i++)
 		{
 			d_solutions[i]->newVelocity(d_gBest->get_pCurrent()) ;
 			d_solutions[i]->newPosition() ;
 			evaluate() ;
 			d_gBest = &best_solution() ;
		}
		j++ ;
	}

 }




