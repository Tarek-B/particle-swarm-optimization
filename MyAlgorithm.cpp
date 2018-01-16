#include "MyAlgorithm.h"
#include "Solution.h"
#include "Problem.h"
#include "SetUpParams.h"
#include <iostream>

#include <vector>


/*
	@Constructor
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
	@Return the parameters of the algorithm
**/
SetUpParams MyAlgorithm::setup() const
{
	return d_setup;
}



/*
	@Return the particles of the population
**/
std::vector<Solution*>& MyAlgorithm::solutions()
{
	return d_solutions;
}



/*
	@Return the best fitness of a particle
**/
void MyAlgorithm::find_gBest()
{   
	d_gBest = d_solutions[0];
	for(int i=1;i<d_solutions.size();i++)
	{
		if(d_gBest->get_BestFitness()>d_solutions[i]->get_BestFitness())// MINIMISATION
			d_gBest = d_solutions[i];
    }
}



/*
	@Return the best solution of the population
**/
double MyAlgorithm :: best_solution()
{	
	find_gBest();
 	d_upper_cost=d_gBest->get_currentFitness();
 	return d_upper_cost;
}



/*
	@Return the particle in the position'index' in the population
**/
Solution& MyAlgorithm::solution(int index)
{
	return *d_solutions[index];
}



/*
	@Initialize all the individuals of the population
**/
void MyAlgorithm::initialize()
{
	for(int i = 0; i < d_solutions.size(); i++)
	{
		d_solutions[i]->initialize();
	}
	find_gBest();
}



/*
	@creates an array with fitness of all solutions in MyAlgorithm and its position in the MyAlgorithm
**/
void MyAlgorithm::update_pBest()
{
	for (int i=0 ; i<d_solutions.size(); i++)
	{
		if (d_solutions[i]->currentFitness()< d_solutions[i]->bestFitness())
   	   		d_solutions[i]->updateBestPosition() ;
    }
}



/*
	@make nb_evolution_steps mutations
**/
void MyAlgorithm :: evolution ()
{
	for (int j=0;j< d_setup.nb_evolution_steps();j++)
 	{
 		for (int i=0; i<d_solutions.size(); i++)
 		{
 			d_solutions[i]->newVelocity(d_gBest->get_pCurrent()) ;
 			d_solutions[i]->newPosition() ;
 			d_solutions[i]->updateBestPosition() ;
 			d_solutions[i]->currentFitness();
 			d_solutions[i]->bestFitness();
		}
    }
    find_gBest();
}



/*
	@print results
**/
void MyAlgorithm :: print_population(std::ostream& ost)
 {
    for (int i=0; i<d_solutions.size(); i++)
    {
        ost<<"Particule "<<i+1<<": ";
        ost<<std::endl;
        d_solutions[i]->print(ost);
    }
}



/*
	@run the algorithm
**/
void MyAlgorithm :: run()
{
	initialize();
	print_population(std::cout);
	std::cout<<"\t Best fitness de meilleure particule :"<<best_solution()<<std::endl;
	for(int i=0; i<d_setup.independent_runs(); i++)
	{
		evolution();
		//std::cout<<"Execution "<<i<<": "<<std::endl;
		std::cout<<"Evolution "<<i+1<<": "<<std::endl;
		std::cout<<"\t Best fitness de meilleure particule :"<<best_solution()<<std::endl;
	}
}
