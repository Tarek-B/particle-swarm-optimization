#include "SetUpParams.h"


/** Constructor

*/
SetUpParams::SetUpParams ():  d_independent_runs{30}, d_nb_evolution_steps{66667}, d_population_size{30}, d_solution_size{30}
{

}



/*
	@construtor with a SetUpParams object in params
**/
SetUpParams :: SetUpParams(const SetUpParams& setup)
{
	d_independent_runs= setup.independent_runs() ;
	d_nb_evolution_steps= setup.nb_evolution_steps() ;
	d_population_size= setup.population_size() ;
	d_solution_size= setup.solution_size() ;
}



/* 
	@DESTRUCTEUR
**/
SetUpParams::~SetUpParams()
{

}



/* 
	@return d_independent_runs 
**/
 int   SetUpParams::independent_runs() const
{
	return d_independent_runs;
}



/*
	@return d_independent_runs 
**/
 int   SetUpParams::nb_evolution_steps() const
{
	return d_nb_evolution_steps;
}



/*
	@return d_population_size 
**/
 int   SetUpParams::population_size() const
{
	return d_population_size;
}



/*
	@return d_independent_runs 
**/
void SetUpParams::independent_runs( int val)
{
	 d_independent_runs=val;
}



/*
	@param[in] d_independent_runs 
**/
void SetUpParams::nb_evolution_steps( int val)
{
	d_nb_evolution_steps=val;
}



/*
	@param[in] d_population_size - la taille de la population
**/
void SetUpParams::population_size( int val)
{
	d_population_size=val;
}



/*
	@return d_child_population_size - la taille du tableau des enfants
**/
int SetUpParams::solution_size() const
{
	return d_solution_size;
}

/** Operateur de Sortie
	@param[in, out] is - le flux de sortie
	@param[in] setup - les parametres du probleme
	@return is - le flux de sortie


*/



/*
	@display the parametres
**/
std::ostream& operator<< (std::ostream& os, const SetUpParams& setup)
{
	os<<"Nb of idependant Run"<< setup.independent_runs()<< std::endl;
	os<<"Nb of iteration per Run"<< setup.nb_evolution_steps()<< std::endl;
	os<<"Nb of solutin in Population"<< setup.population_size()<< std::endl;
	return os;
}



/** Operateur d'Entree
	@param[in, out] is - le flux d'entree
	@param[in] setup - les parametres du probleme
	@return is - le flux d'entree
*/



/*
	@display
**/
std::istream& operator>> (std::istream& is, SetUpParams& setup)
{
	int runs,
		steps,
		population;

	is>>runs>>steps>>population;

	if (is.good())
	{
		setup.independent_runs(runs);
		setup.nb_evolution_steps(steps);
		setup.population_size(population);

	}
	return is;
}

