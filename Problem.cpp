#include "Problem.h"

using std::cout;
using std::endl;


Problem::Problem(benchmark* bench) : d_bench{bench}
{}

Problem::~Problem()
{
	delete d_bench;
}

int Problem::dimension() const{
	return d_bench->getNombreDeVariables();
}

double Problem::UpperLimit(int index) const
{
	return d_bench->getBorneSuperieure(index);
}

double Problem::LowerLimit(int index) const
{	#pragma once
	return d_bench->getBorneInferieure(index);
}

benchmark* Problem::getBenchmark() const
{
	return d_bench;
}

std::ostream& operator<<(std::ostream& ost, const Problem& pbm){
	ost<<"Problem"<<endl;
	ost<<"-> Dimension : "<<pbm.dimension()<<endl;
	ost<<"-> Limits (";
	for(int i=0;i<pbm.dimension();i++)
	{
		ost<<pbm.LowerLimit(i)<<" ";
	}
	ost<<",";
	for(int i=0;i<pbm.dimension();i++)
	{
		ost<<pbm.UpperLimit(i)<<" ";
	}
}
