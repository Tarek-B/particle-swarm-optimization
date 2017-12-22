#include "SetUpParams.h"



SetUpParams::SetUpParams ():  d_independent_runs{30}, d_nb_evolution_steps{66667}, d_population_size{30}, d_solution_size{30}
{

}
SetUpParams :: SetUpParams(const SetUpParams & setup) 
{
	d_independent_runs= setup.independent_runs() ; 
	d_nb_evolution_steps= setup.nb_evolution_steps() ; 
	d_population_size= setup.population_size() ; 
	d_solution_size= setup.solution_size() ; 
}	

SetUpParams::~SetUpParams()
{

}

 int   SetUpParams::independent_runs() const
{
	return d_independent_runs;
}

 int   SetUpParams::nb_evolution_steps() const
{
	return d_nb_evolution_steps;
}

 int   SetUpParams::population_size() const
{
	return d_population_size;
}

void SetUpParams::independent_runs( int val)
{
	 d_independent_runs=val;
}

void SetUpParams::nb_evolution_steps( int val)
{
	d_nb_evolution_steps=val;
}

void SetUpParams::population_size( int val)
{
	d_population_size=val;
}

int SetUpParams::solution_size() const
{
	return d_solution_size;
}


std::ostream& operator<< (std::ostream& os, const SetUpParams& setup)
{
	os<<"Nb of idependant Run"<< setup.independent_runs()<< std::endl;
	os<<"Nb of iteration per Run"<< setup.nb_evolution_steps()<< std::endl;
	os<<"Nb of solutin in Population"<< setup.population_size()<< std::endl;
	return os;
}

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

