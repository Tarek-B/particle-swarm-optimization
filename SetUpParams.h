#define SETUPPARAMS_H
#ifndef SETUPPARAMS_H


class SetUpParams
{  	
	private:
		unsigned int   d_independent_runs;         //number of independent runs
		unsigned int   d_nb_evolution_steps;       // number of iterations per run
		unsigned int   d_population_size;		// number of solutions in the population
		unsigned int   d_solution_size;	        // size of each particle

	public:
		//Builder
		SetUpParams ();
		//Destructive
		~SetUpParams();
 		/** output Operator
			@param[in, out] is - the output stream
			@param[in] setup - the parameters of the problem
			@return is - the output stream
		*/
			
	    int   independent_runs() const;
		/** Turn the number of iterations per run
			@return d_nb_evolution_steps - the number of iterations per run
		*/	
		int   nb_evolution_steps() const; 
		/** Turn the size of the population
			@return d_population_size - the size of the population
		*/
		int   population_size() const;
		int   solution_size() const;
		/**Modify the number of launches
			@param[in] d_independent_runs - the number of launches
		*/
		void independent_runs(const int val);
		/**Modify the number of iterations per run
			@param[in] d_nb_evolution_steps - the number of iterations per run
		*/
		void nb_evolution_steps(const int val);
		/**Modify the size of the population
			@param[in] d_population_size - the size of the population
		*/
		void population_size(const int val);
		
		void solution_size(const int val);

		~SetUpParams();
};

#endif
  
