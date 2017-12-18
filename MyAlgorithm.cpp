#include <iostream>
#include <vector>
#include "Solution.h"
#include "Problem.h"
#include "SetUpParams.h"
#include <limits>

/**************************************************************Paramètres***********************************
   
    		vector<Solution*> d_solutions;
		// Parameters
		const SetUpParams& d_setup;
		// Upper fitness of individuals in population
		unsigned int d_upper_cost; 
 		unsigned int d_lower_cost; lower fitness of individuals in population
 		vector<struct particle> _fitness_values;
    ********************************************************************************************************/

/********Constructeur qui prends en paramètre 
un problème 
un objet setup contenant les paramètres de base
et initialise les aures paramètre de la classe à 0 ******/

MyAlgorithm::MyAlgorithm(Problem* pbm,const SetUpParams& setup) : d_pbm{pbm}, d_setup{&setup}, 
                                                                  d_solutions{}, d_upper_cost{0}, d_lower_cost{0}
{
	for(int i=0;i<d_setup->population_size();i++)
	{
		d_solutions.push_back(new Solution{d_pbm});
	}
}


/*****Destructeur
qui vide le contenue des vector en 
plus de détruire l'objet
****************/

MyAlgorithm::~MyAlgorithm()
{
	for(int i=0;i<d_solutions.size();i++)
	{
		delete d_solution[i];
	}
	for(int i=0;i<_fitness_values.size();i++)
	{
		delete _fitness_values[i];
	}
}

/***********Focnction qui renvoie 
un pointeur vers un objet de 
paramètres de la classe SetUpParams
*************************************/

const SetUpParams& MyAlgorithm::setup() const
{
	return *d_setup;
}


//Initialisation de la population
void MyAlgorithme::initialize()
{
	for(int i = 0; i < d_solution.size(); i++)
	{
		d_solution[i].initializePosition();	
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
 
 Solution MyAlgorithm :: best_solution() 
 {
 	d_gBest = d_solutions[0] ; 
 	for (int i=1 ; i<d_solutions.size() ; i++ )
 	{
 		if (d_gBest->get_BestFitness() < d_solutions[i].get_BestFitness())
 		{
 			d_gBest = d_solutions[i] ; 
		}
	}
 }
 
 
 


/*********Fonction qui renvoie le tableau des solutions
ableau de pointeurs sur particules*********************/

const vector<Solution*>& MyAlgorithm::solutions() const
{
	return d_solutions;
}

/**********Renvoie la fitnesse la plus grande
du vactor solution**************************/

unsigned int MyAlgorithm::upper_cost() const
{
  floa max=std::numeric_limits<float>::min();
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

/**********Renvoie la fitnesse la plus petite
du vactor solution**************************/

unsigned int MyAlgorithm::upper_cost() const
{
  floa min=std::numeric_limits<float>::max();
  int position;
  for(int i=0;i<d_solutions.size();i++)
  { 
      if(min<d_solutions[i]->get_fitness()) 
      {
        min = d_solutions[i]->get_fitness();
        position = i;
      }
	return d_solutions[position]->get_fitness();
}
  
/********Méthode qui retourne la solution
à l'index donné en paramètre*************/
  
Solution& MyAlgorithm::solution(const unsigned int index) const
{
	return *d_solutions[index];
}
  


    
	  
	  
  void evolution(int iter); /*makes an evolution step*/
  {
    
  }  
    
	
	/************************************
Je sais pas ce qu'elle fait mais
je suppose qu'elle va retournée le vecteur 
de solution

vector<struct particle>&  MyAlgorithm::fitness_values();
  {
    reurn _fitness_values
  }
  
Pareil que celle d'en haut je suppose
qu'elle retourne une valeur à la position index
de _fitness_values
  
double fitness(const unsigned int index) const
{
  return _fitness_values[index];
}

Retourne la meilleure
valeur du _fitness_values
double MyAlgorithm::best_cost() const;
  {
    floa max=std::numeric_limits<float>::min();
    int position;
    for(int i=0;i<_fitness_values.size();i++)
     { 
        if(max<_fitness_values[i].fitness) 
        {
           max = _fitness_values[i].finess;
           position = i;
      }
	   return _fitness_values[position].fitness;
  }
  
  
  	  
	  
	  
double MyAlgorithm::worst_cost() const;
  {
    floa min=std::numeric_limits<float>::max();
    int position;
    for(int i=0;i<_fitness_values.size();i++)
     { 
        if(min<_fitness_values[i].fitness) 
        {
           min = _fitness_values[i].finess;
           position = i;
      }
	   return _fitness_values[position].fitness;
  }	  
	  
	  
Solution& MyAlgorithm::best_solution() const;
  {
    
  }
  
  
  
Solution& MyAlgorithm::worst_solution() const;
  {
    
  }

  
  ******************************/
  

