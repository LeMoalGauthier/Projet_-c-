#ifndef VILLE_H
#define VILLE_H

#include "Waypoint.h"

class Ville : public Waypoint {

    private:
        string code_postal;
        int nb_habitants;
        string site;
    public:
        Ville(){};
        Ville(string new_code_postal, int new_nb_habitants, string new_site)
                        {code_postal = new_code_postal; nb_habitants = new_nb_habitants; site = new_site;};
        Ville(string new_nom, float new_lon , float new_lat, string new_code_postal, int new_nb_habitants, string new_site)
                        {nom = new_nom; lon = new_lon; lat = new_lat; code_postal = new_code_postal; nb_habitants = new_nb_habitants; site = new_site;};
        ~Ville(){};
        string getCodePostal(){return code_postal;};
        int getNbHabitants(){return nb_habitants;};
        string getSite(){return site;};
        bool isVille(){return true;};
        string getInfo(){};
        void affiche(){cout << "Code postal : " << code_postal << " Nombre d'habitants : " << nb_habitants << " Site : " <<site << " Nom : " 
                        << nom << " Longitude : " << lon << " Latitude" << lat;}



};


#endif;