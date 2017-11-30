#include"MyAlgorithm.h"

MyAlgorithm :: MyAlgorithm(const Problem& pbm,const SetUpParams& setup) : d_solutions{}, d_pbm{pbm}, d_setup{setup}, d_upper_cost{0}
{
	for(int i=0; i<d_setup.population_size(); i++)
	{
		d_solutions.push_back(new Solution{pbm});
	}
}

MyAlgorithm :: ~MyAlgorithm()
{
	for(auto s : d_solutions)
	{
		delete s;
	}
	delete d_pbm;
	delete d_setup;
}
