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

	//do
	//{
		cout<<"Veuillez saisir votre choix: "<<endl;
		cin>>choix;
		cout<<endl;
//}while(choix<=0 || choix>7);

	//Créer un problem à partir du choix de l'utilisateur
	SetUpParams param{};
	Problem pbm{param.solution_size(), choix};
	cout<<pbm.getDimension()<<" "<<pbm.getLowerLimit()<<endl;
    MyAlgorithm algorithm{pbm, param};
    algorithm.initialize();
    //cout<<"initialize marche"<<endl
    //cout<<algorithm.solution(1).get_problem().getLowerLimit()<<"on peut acceder aux données du problème depuis la solution (i) dans le vecteur de solutions de MyAllgorythm"
    algorithm.find_gBest();
    cout<<"Fitness de gbest = "<<algorithm.best_solution().currentFitness()<<endl;
    algorithm.evolution();
    cout<<"Fitness de nouvelle gbest = "<<algorithm.best_solution().currentFitness()<<endl;

	/*cout<<"Meilleure particule :";
	algorithm.best_solution();
	cout<<endl;
	algorithm.best_solution().print(cout);
	*/return 0;
}
