#ifndef PROBLEM_H
#define PROBLEM_H
#include "Benchmarks.h"
#include <iostream>

class Problem
{	
	
	public:
		Problem(benchmark* bench);
		~Problem();
		friend std::ostream& operator<< (std::ostream&, const Problem&);

		
		
		int dimension() const;
		double UpperLimit(int index) const;
		double LowerLimit(int index) const;
		benchmark* getBenchmark() const;
	
		
	
	private:

		benchmark* d_bench;
	

  };


  #endif
