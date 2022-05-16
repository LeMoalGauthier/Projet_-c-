#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <string>
#include <vector>
#include "Contour.h"
#include "Waypoint.h"
#include "Route.h"

using namespace std;

class Carte {
    private :
        vector<Route> route;
        vector<string> nom;
        Contour contour;
    public :
        Carte(){};
        ~Carte(){};
        Contour getContour(){return contour;}
        float getEchelleLon(){return lon;}
        vector<Route> getRoutes(){return route;}
        vector<string> getNomsVilles(){return nom;}
        void ajoutUnWaypoint(Waypoint);
        void ajoutUneRoute(Route);
        void insereUneVille(Ville *);
        void affiche();

        
};

#endif;