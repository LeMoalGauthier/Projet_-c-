#ifndef VILLE_H
#define VILLE_H

#include "Waypoint.h"

class Ville : public Waypoint {

    private:
        string code_postal;
        int nb_habitants;
        string site;
    public:
        string getSite(){return site;};
        bool isVille(){return true;};
        string getInfo(){};
        void affiche(){cout << "Code postal : " << code_postal << " Nombre d'habitants : " << nb_habitants << " Site : " <<site;}



};


#endif;