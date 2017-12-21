#include <iostream>

#include "SetUpParams.h"
 

/** Builder
	
*/
SetUpParams::SetUpParams ():  d_independent_runs{30}, d_nb_evolution_steps{66667}, d_population_size{30}, d_solution_size {30}
{}
/** Destructive 
*/
SetUpParams::~SetUpParams()
{}
/** Turn the number of launches
	@return d_independent_runs - The number of independent launches
*/
int   SetUpParams::independent_runs() const
{
	return d_independent_runs;
}
/** Turn the number of iterations per run
	@return d_nb_evolution_steps - the number of iterations per run
*/
int   SetUpParams::nb_evolution_steps() const
{
	return d_nb_evolution_steps;
}
/** Turn the size of the population
	@return d_population_size - the size of the population
*/
int   SetUpParams::population_size() const
{
	return d_population_size;
}
int   solution_size() const
{ 
	return d_solution_size ;
}
/**Modify the number of launches
	@param[in] d_independent_runs - the number of launches
*/

void SetUpParams::independent_runs(int val)
{
	 d_independent_runs=val;
}

/**Modify the number of iterations per run
	@param[in] d_nb_evolution_steps - the number of iterations per run
*/
void SetUpParams::nb_evolution_steps(int val)
{
	d_nb_evolution_steps=val;
}
/**Modify the size of the population
	@param[in] d_population_size - the size of the population
*/
void SetUpParams::population_size(int val)
{
	d_population_size=val;
}
void solution_size(const unsigned int val)
{
	d_solution_size = val ; 
}


/** output Operator
	@param[in, out] is - the output stream
	@param[in] setup - the parameters of the problem
	@return is - the output stream
*/
std::ostream& operator<< (std::ostream& os, const SetUpParams& setup)
{
	os<<"Nb of idependant Run"<< setup.independent_runs()<< std::endl;
	os<<"Nb of iteration per Run"<< setup.nb_evolution_steps()<< std::endl;
	os<<"Nb of solution in Population"<< setup.population_size()<< std::endl;
	return os;
}
/** input operator 
	@param[in, out] is - The input stram 
	@param[in] setup - the parameters of the problem
	@return is - the input stream
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

