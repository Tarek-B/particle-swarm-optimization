#include <iostream>
#include <cstdlib>
#include "MyAlgorithm.h"

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
		cin>>choix>>endl;
	}while(choix<=0 || choix>7);
	
	//Créer un problem à partir du choix de l'utilisateur
	SetUpParams setup{};
	Problem *pbm{setup.solution_size(), choix};
	
	MyAlgorithm algorithm{pbm, setup};
	
	
}
int main(int argc, char** argv) {
	return 0;
}
