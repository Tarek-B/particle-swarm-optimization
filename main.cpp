#include <iostream>
#include <cstdlib>

#include <ctime>

#include "MyAlgorithm.h"
#include "Solution.h"
#include "Problem.h"
#include "SetUpParams.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using std::cout;
using std::cin;
using std::endl;


int main(int argc, char** argv) {

    // A ne pas oublier !
    srand(time(NULL));

	//Faire saisir l'utilisateur un choix
	int choix;

	do
	{
		cout<<"Veuillez saisir votre choix: "<<endl;
		cin>>choix;
		cout<<endl;


	//Créer un problem à partir du choix de l'utilisateur
	SetUpParams param{};
	Problem pbm{param.solution_size(), choix};
	cout<<pbm.getDimension()<<" "<<pbm.getLowerLimit()<<endl;

    MyAlgorithm algorithm{pbm, param};
    algorithm.initialize();
    //cout<<"initialize marche"<<endl
    //cout<<algorithm.solution(1).get_problem().getLowerLimit()<<"on peut acceder aux données du problème depuis la solution (i) dans le vecteur de solutions de MyAllgorythm"
    //algorithm.find_gBest();
    //cout<<"Fitness de gbest = "<<algorithm.best_solution().currentFitness()<<endl;
    //algorithm.evolution();
    //cout<<"Fitness de nouvelle gbest = "<<algorithm.best_solution().currentFitness()<<endl;
    algorithm.print_population(cout);
    //algorithm.evolution();
    cout<<"\n\t=========================\t\n";
    //algorithm.print_population(cout);
	cout<<"Meilleure particule :";
	cout<<endl;
	cout<<algorithm.best_solution().get_BestFitness();
	cout<<endl;
	cout<<"\n\t================================================\t\n";
}while(choix!=0);
	return 0;
}
