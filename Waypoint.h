#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <iostream>
#include <string>

using namespace std;

class Waypoint {

    protected:
        string nom;
        float lon;
        float lat;

    public:
        Waypoint(){};
        Waypoint(string new_nom, float new_lon , float new_lat){nom = new_nom; lon = new_lon; lat = new_lat;};
        ~Waypoint(){};
        string getNom(){return nom;};
        float getLon(){return lon;};
        float getLat(){return lat;};
        virtual bool isVille(){return false;};
        //string getInfos();
        void affiche() {cout<< "Nom : " << nom << " Longitude : " << lon << " Latitude" << lat << endl;};

};

#endif