#ifndef BENCHMARKS_H
#define BENCHMARKS_H
#include <vector>

using namespace std;

class benchmark{

	private:
		int d_nombreDeVariables;
		vector <double> d_lowerLimit;
		vector <double> d_borneSuperieure;
	public:
		benchmark(int nombreDeVar, vector <double> borneInf, vector <double> borneSup);
		benchmark();
		virtual ~benchmark();

		int getNombreDeVariables() const;
		double getBorneInferieure(int index) const;
		double getBorneSuperieure(int index) const;

		void setNombreDeVariables(int nombreDeVar);
		void setBorneInferieure(vector <double>& borneInf);
		void setBorneSuperieure(vector <double>& borneSup);

		virtual double getFitness(vector <double>& argument) = 0;
};

class Rosenbrock : public benchmark{
	public:
		Rosenbrock(int nb);
		virtual ~Rosenbrock() override;

		double getFitness(vector <double>& argument) override;
};

class Rastrigin : public benchmark{
	public:
		Rastrigin(int nb);
		virtual ~Rastrigin() override;

		double getFitness(vector <double>& argument) override;
};

class Ackley : public benchmark{
	public:
		Ackley(int nb);
		virtual ~Ackley() override;

		double getFitness(vector <double>& argument) override;
};

class Schwefel : public benchmark{
	public:
		Schwefel(int nb);
		virtual ~Schwefel() override;

		double getFitness(vector <double>& argument) override;
};

class Schaffer : public benchmark{
	public:
		Schaffer(int nb);
		virtual ~Schaffer() override;

		double getFitness(vector <double>& argument) override;
};

class Weierstrass : public benchmark{
	public:
		Weierstrass(int nb);
		virtual ~Weierstrass() override;

		double getFitness(vector <double>& argument) override;
};

#endif
