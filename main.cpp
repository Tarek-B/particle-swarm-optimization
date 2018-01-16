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

void lancerAlgorithme()
{
	srand(time(NULL));
	int choix;
	do{	
		cout<<"choix de la fonction :"<<endl;
		cout<<" 1) Fonction Rosenbrock"<<endl;
		cout<<" 2) Fonction Rastrigin"<<endl;
		cout<<" 3) Fonction Ackley"<<endl;
		cout<<" 4) Fonction Schwefel"<<endl;
		cout<<" 5) Fonction Schaffer"<<endl;
		cout<<" 6) Fonction Weierstrass"<<endl;
		cout<<"Veuillez saisir votre choix: "<<endl;
		cin>>choix;
		cout<<endl;
		system("cls");
	}while(choix<=0 && choix >=7);
	
	SetUpParams param{};
	Problem pbm{param.solution_size(), choix};
	MyAlgorithm algorithm{pbm, param};
	algorithm.run();
}

int main(int argc, char** argv) {

	int choix = 0;
	do
	{
		cout<<"1) Lancer l'algorithme "<<endl;
		cout<<"2) Quitter "<<endl;
		cin>>choix;
		switch(choix)
		{
			case 1:
				lancerAlgorithme();
				break;
			case 2:
				break;
		}
	}while(choix != 2);
	return 0;
}
