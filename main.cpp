#include <iostream>
#include <cstdlib>
#include "MyAlgorithm.h"
#include "Solution.h"
#include "Problem.h"
#include "SetUpParams.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using std::cout;
using std::cin;
using std::endl;

void run()
{
	//Faire saisir l'utilisateur un choix
	int choix;
	do
	{
		cout<<"Veuillez saisir votre choix: "<<endl;
		cin>>choix;
		cout<<endl;
	}while(choix<=0 || choix>7);

	//Créer un problem à partir du choix de l'utilisateur
	SetUpParams param{};
	Problem pbm{param.solution_size(), choix};

	MyAlgorithm algorithm{pbm, param};
	algorithm.evolution();
	cout<<"Meilleure particule :";
	algorithm.best_solution();
	cout<<endl;
	algorithm.best_solution().print(cout);

}
int main(int argc, char** argv) {
	run();
	return 0;
}
