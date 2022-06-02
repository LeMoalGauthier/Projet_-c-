#ifndef GRAPHE_H
#define GRAPHE_H

#include "Carte.h"

#define INF 10000

class Graphe : public Carte {
    private:
        //vector de pair (rang dans le vector = id noeud, 1er int = distance à ce point depuis le point de départ, 2nd int = waypoint permettant d'accéder à celui-ci)
        vector< pair<int,int> > adjascence;
    public:
    Graphe();
    ~Graphe(){};
    vector< pair<int,int> > GetAdjascence(){return adjascence;}
    void Voisins(int, vector< pair<int,int> > &);
    int Distance(int ind_deb, int ind_fin);
    vector<Route> Trajet(int ind_deb, int ind_fin);

};

#endif