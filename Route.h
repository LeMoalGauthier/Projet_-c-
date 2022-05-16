#ifndef ROUTE_H
#define ROUTE_H
#include <iostream>
#include <string>

using namespace std;

class Route{

    private :
        int i_deb;
        int i_fin;
        int distance;
        string infos;

    public :
        Route(){};
        ~Route(){};
        int getDeb(){return i_deb;}
        int getFin(){return i_fin;}
        int getDistance(){return distance;}
        string getInfos(){return infos;}
        void affiche();
};

#endif;