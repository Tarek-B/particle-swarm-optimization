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
    //création de la population
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
 	find_gBest();
 	return *d_gBest;

 	/*d_gBest = d_solutions[0] ;
 	for (int i=1 ; i<d_solutions.size() ; i++ )
 	{
 		if (d_gBest->get_currentFitness() < d_solutions[i]->get_currentFitness())
 		{
 			d_gBest = d_solutions[i] ;
		}
	}*/
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
void MyAlgorithm::find_gBest()
{   /*on modifie la fonction qui retournait la meilleure solution (valeur)
    pour qu'elle fasse pointer gbest sur la meilleure particule*/
  //float max=std::numeric_limits<float>::min();
  //int position;
  d_gBest = d_solutions[0];
  for(int i=1;i<d_solutions.size();i++)
  {
      if(d_gBest->get_currentFitness()<d_solutions[i]->get_currentFitness())// MINIMISATION
      {
        d_gBest = d_solutions[i];
        //position = i;
      }
	//return d_solutions[position]->get_currentFitness();
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
	find_gBest();   //initialise gBest à la meilleure particule du début
}

// creates an array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
void MyAlgorithm::update_pBest()
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
 	for (int j=0;j< d_setup.nb_evolution_steps();j++)
 	{
 		for (int i=0; i<d_solutions.size(); i++)
 		{
 			d_solutions[i]->newVelocity(d_gBest->get_pCurrent()) ;
 			d_solutions[i]->newPosition() ;
 			d_solutions[i]->updateBestPosition() ;
 			//d_gBest = &best_solution() ;
		}
    }
    find_gBest();
 }




