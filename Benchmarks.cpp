#include "Benchmarks.h"
#include <cmath>
#include <vector>


const double pi = 3.14159265359;

using namespace std;

/**
	Constructeur de benchmark
	@param[in] nombreDeVar - nombre d'arguments de la fonction
	@param[in] borneInf - tableau contenant la limite inférieure de chaque parametre
	@param[in] borneSup - tableau contenant la limite supérieure de chaque parametre
*/
benchmark::benchmark(int nombreDeVar, vector <double> borneInf, vector <double> borneSup):d_nombreDeVariables(nombreDeVar),d_lowerLimit{borneInf},d_upperLimit{borneSup}
{
}

benchmark::benchmark() : d_nombreDeVariables{}, d_lowerLimit{}, d_upperLimit{}
{
}
/**
	Destructeur de benchmark
*/
benchmark::~benchmark()
{
}
/**
	Renvoie le nombre d'arguments
	@return nombre d'arguments
*/
int benchmark::getNombreDeVariables() const
{
	return d_nombreDeVariables;
}
/**
	renvoie le tableau contenant les limites inférieures
*/
double benchmark::getBorneInferieure(int index) const
{
	return d_lowerLimit[index];
}
/**
	renvoie le tableau contenant les limites supérieures
*/
double benchmark::getBorneSuperieure(int index) const
{
	return d_upperLimit[index];
}
/**
	modifier nombres d'arguements
	@param[in] nombreDeVar - nombre d'arguments
*/
void benchmark::setNombreDeVariables(int nombreDeVar)
{
	d_nombreDeVariables = nombreDeVar;
}
/**
	modifie limites inférieures
	@param[in] borneInf - tableau contenant les limites
*/
void benchmark::setBorneInferieure(vector <double>& borneInf)
{
	d_lowerLimit = borneInf;
}
/**
	modifie limites supérieures
	@param[in] borneInf - tableau contenant les limites
*/
void benchmark::setBorneSuperieure(vector <double>& borneSup)
{
	d_upperLimit = borneSup;
}
/**
	Constructeur de Rastrigin, qui fait appel à celui de Benchmark
*/
Rastrigin::Rastrigin(int nb) : benchmark{nb,vector<double>(nb,-5.12),vector<double>(nb,5.12)}
{

}

Rastrigin::~Rastrigin()
{
}

/**
	Aplique la focntion aux arguments passés en paramètres
	@param[in] - tableau contenant les arguments
*/
double Rastrigin::getFitness(vector <double>& argument)
{
	double fitness = 0.0;

	fitness = 10.0 * getNombreDeVariables();

	for(int i = 0; i < getNombreDeVariables() ; i++)
	{
		fitness+= pow(argument[i], 2) - 10.0 * cos(2.0 * pi * argument[i]);
	}

	return fitness;
}

/**
	Constructeur de Rosenbrock, qui fait appel à celui de Benchmark
*/

Rosenbrock::Rosenbrock(int nb) : benchmark{nb,vector<double>(nb,-2.048),vector<double>(nb,2.048)}
{

}

Rosenbrock::~Rosenbrock()
{
}
/**
	Aplique la focntion aux arguments passés en paramètres
	@param[in] - tableau contenant les arguments
*/
double Rosenbrock::getFitness(vector <double>& argument)
{
	double fitness = 0.0;

	for(int i = 0 ; i < getNombreDeVariables() -1 ; i++)
	{
	fitness += 100.0*pow(argument[i+1] - pow(argument[i],2), 2) + pow(1.0 - argument[i], 2);
	}

	return(fitness+390);
}
/**
	Constructeur de Ackley, qui fait appel à celui de Benchmark
*/

Ackley::Ackley(int nb) : benchmark{nb,vector<double>(nb,-5.0),vector<double>(nb,5.0)}
{

}

Ackley::~Ackley()
{
}
/**
	Aplique la focntion aux arguments passés en paramètres
	@param[in] - tableau contenant les arguments
*/
double Ackley::getFitness(vector <double>& argument)
{
	double fitness = 0.0;
	double premierMembre = 0.0;
	double secondMembre = 0.0;

	for(int i = 0; i < getNombreDeVariables() ; i++)
	{
		premierMembre += pow(argument[i],2);
		secondMembre += cos(2*pi*argument[i]);
	}

	fitness = -20*exp(-0.2*sqrt((1.0/getNombreDeVariables())*premierMembre)) - exp((1.0/getNombreDeVariables())*secondMembre) + 20 + exp(1);


	return (fitness);
}
/**
	Constructeur de Schwefel, qui fait appel à celui de Benchmark
*/
Schwefel::Schwefel(int nb) : benchmark{nb,vector<double>(nb,-500.0),vector<double>(nb,500.0)}
{

}

Schwefel::~Schwefel()
{
}
/**
	Aplique la focntion aux arguments passés en paramètres
	@param[in] - tableau contenant les arguments
*/
double Schwefel::getFitness(vector <double>& argument)
{
	double fitness = 0.0;

	fitness = 418.9829 * getNombreDeVariables();

	for(int i = 0 ; i < getNombreDeVariables() ; i++)
	{
		fitness -= argument[i] * sin(sqrt(fabs(argument[i])));
	}

	return(fitness);
}

/**
	Constructeur de Schaffer, qui fait appel à celui de Benchmark
*/
Schaffer::Schaffer(int nb) : benchmark{nb,vector<double>(nb,-100.0),vector<double>(nb,100.0)}
{

}

Schaffer::~Schaffer()
{
}
/**
	Aplique la focntion aux arguments passés en paramètres
	@param[in] - tableau contenant les arguments
*/
double Schaffer::getFitness(vector <double>& argument)
{
	double fitness = 0.0;

	for(int i = 0; i<getNombreDeVariables()-1;i++)
	{
		fitness += 0.5 + (pow(sin(sqrt(pow(argument[i],2)+pow(argument[i+1],2))),2)+0.5)/pow((1+0.001*(pow(argument[i],2)+pow(argument[i+1],2))),2);
	}

	return(fitness);
}
/**
	Constructeur de Weierstrass, qui fait appel à celui de Benchmark
*/
Weierstrass::Weierstrass(int nb) : benchmark{nb,vector<double>(nb,-2.0),vector<double>(nb,2.0)}
{}

Weierstrass::~Weierstrass()
{}
/**
	Aplique la focntion aux arguments passés en paramètres
	@param[in] - tableau contenant les arguments
*/
double Weierstrass::getFitness(vector <double>& argument)
{
	double fitness = 0.0;
	double premierMembre = 0.0;
	double secondMembre = 0.0;

	for(int i=0;i<getNombreDeVariables();i++)
	{
		for(int j = 0; j<=20;j++)
		{
			premierMembre+=pow(0.5,j)*cos(2*pi*pow(3,j)*(argument[i]+0.5));
		}
	}

	for(int i=0;i<=20;i++)
	{
		secondMembre+=pow(0.5,i)*cos(2*pi*pow(3,i)*0.5);
	}

	secondMembre*=getNombreDeVariables();

	fitness = premierMembre - secondMembre;
	return(fitness);

}
