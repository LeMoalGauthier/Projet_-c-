#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class Route{

    private :
        int i_deb;
        int i_fin;
        int distance;
        // ? string infos; pas compris l'utilité de ça donc je laisse ça comme ça 

    public :
        Route(){};
        Route(int new_i_deb, int new_i_fin, int new_distance){i_deb = new_i_deb; i_fin = new_i_fin; distance = new_distance;};
        ~Route(){};
        int getDeb(){return i_deb;}
        int getFin(){return i_fin;}
        int getDistance(){return distance;}
        // ? string getInfos(){return infos;}
        void affiche(){cout << "Ville de départ : " << i_deb << " Ville d'arrivé : " << " distance : " << distance << endl;};
};

#endif;