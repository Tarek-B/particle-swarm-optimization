#include <iostream>
#include <vector>

#define SOLUTION_H
#ifndef SOLUTION_H

class Solution{
  public:
    
  private:
    //Vecteur des coordonnées de la position courant
    vector<double> d_pCurrent;
    //Vecteur des coordonnées de la meilleure position jusqu'à présent
    vector<double> d_pbest;
    //Vecteur des coordonnées de la vitesse d'une particule
    vector<double> d_velocity;
    //Cout de fitness de la particule
    double d_current_fitness;
    //Un problème donné (par rapport aux six fonctions de tests données dans le pdf)
    const Problem& d_pbm;
};

#endif
