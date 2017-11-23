#include "SetUpParams.h"
 

/** Builder
	
*/
SetUpParams::SetUpParams ():  d_independent_runs{64}, d_nb_evolution_steps{30}, d_population_size{30}, d_solution_size {30}
{}
/** Destructive 

*/
SetUpParams::~SetUpParams()
{}
/** Turn the number of launches
	@return d_independent_runs - The number of independent launches
*/
const unsigned int   SetUpParams::independent_runs() const
{
	return d_independent_runs;
}
/** Turn the number of iterations per run
	@return d_nb_evolution_steps - the number of iterations per run
*/
const unsigned int   SetUpParams::nb_evolution_steps() const
{
	return d_nb_evolution_steps;
}
/** Turn the size of the population
	@return d_population_size - the size of the population

*/
const unsigned int   SetUpParams::population_size() const
{
	return d_population_size;
}
const unsigned int   solution_size() const
{ 
	return d_solution_size ;
}
/**Modify the number of launches
	@param[in] d_independent_runs - the number of launches

*/

void SetUpParams::independent_runs(const unsigned int val)
{
	 d_independent_runs=val;
}

/**Modify the number of iterations per run
	@param[in] d_nb_evolution_steps - the number of iterations per run

*/
void SetUpParams::nb_evolution_steps(const unsigned int val)
{
	d_nb_evolution_steps=val;
}
/**Modify the size of the population
	@param[in] d_population_size - the size of the population

*/
void SetUpParams::population_size(const unsigned int val)
{
	d_population_size=val;
}
void solution_size(const unsigned int val)
{
	d_solution_size = val ; 
}


/** Operateur de Sortie
	@param[in, out] is - le flux de sortie
	@param[in] setup - les parametres du probleme
	@return is - le flux de sortie


*/
std::ostream& operator<< (std::ostream& os, const SetUpParams& setup)
{
	os<<"Nb of idependant Run"<< setup.independent_runs()<< std::endl;
	os<<"Nb of iteration per Run"<< setup.nb_evolution_steps()<< std::endl;
	os<<"Nb of solution in Population"<< setup.population_size()<< std::endl;
	return os;
}
/** Operateur d'Entree
	@param[in, out] is - le flux d'entree
	@param[in] setup - les parametres du probleme
	@return is - le flux d'entree

*/
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




