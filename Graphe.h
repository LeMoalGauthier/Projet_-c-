#ifndef GRAPHE_H
#define GRAPHE_H

#include "Carte.h"

#define INF 10000

class Graphe : public Carte {
    private:
        vector< pair<int,int> > adjascence;
    public:
    Graphe();
    ~Graphe(){};
    vector< pair<int,int> > GetAdjascence(){return adjascence;}
    //Ces 2 fonctions ci-dessous ont été abandonné après changement de la manie dont la donnée est stocké
    // void AjouterAdjascence(string new_adjascence ){adjascence.push_back(new_adjascence);};
    // void ModifierAdjascence(string new_adjascence, int rang){adjascence[rang] = new_adjascence;}
    void Voisins(int, vector< pair<int,int> > &);
    int Distance(int ind_deb, int ind_fin);
    vector<Route> Trajet(int ind_deb, int ind_fin);

};



#endif