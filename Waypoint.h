#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <iostream>
#include <string>

using namespace std;

class Waypoint {

    private:
        string nom;
        float lon;
        float lat;

    public:
        string getNom(){return nom;};
        float getLon(){return lon;};
        float getLat(){return lat;};
        virtual bool isVille(){return false;};
        string getInfos();
        void affiche() {cout<< "Nom : " << nom << " Longitude : " << lon << " Latitude" << lat;};

};

#endif;