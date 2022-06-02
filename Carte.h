#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <string>
#include <vector>

#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "Ville.h"
#include "Waypoint.h"
#include "Contour.h"
#include "Route.h"

using namespace std;

class Carte {
    protected :
        vector<Route> route;
        vector<Waypoint> waypoint;
        Contour contour;
        int echelleLon;
    public :
        Carte();
        ~Carte(){};
        Contour getContour(){return contour;}
        float getEchelleLon(){return echelleLon;}
        vector<Waypoint> getWaypoint(){return waypoint;}
        vector<Route> getRoutes(){return route;}
        vector<string> getNomsVilles(){}
        void ajoutUnWaypoint(Waypoint){};
        void ajoutUneRoute(Route){};
        void insereUneVille(Ville *){};


        
};

#endif