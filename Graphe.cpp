#include "Graphe.h"

Graphe::Graphe(){
    // TODO Construction de la fonction qui calcul les routes vers chaque waypoint de la map. Il s'agit d'un vecteur de vecteur string.
    // TODO Les données sont stocké sous forme de string formaté pour en extraire les informations souhaité plus tard.
    // TODO Pour une route allant de A à B et passant par C puis E et enfin B, les données sont stockée tel que
    // TODO "id_waypoint_C-id_waypoint_E-id_waypoint_B"



}

vector<int> Graphe::Voisins(int indice){

    vector<int> voisins;
    //string nom_waypoint = waypoint[indice].getNom();
    
    for(int i = 0; i < route.size(); i++){

        //vérification si la route commence à la ville souhaité
        if(route[i].getDeb() == indice){

            //ajout de la ville voisine au tableau 
            voisins.push_back(route[i].getFin());

        //vérification si la route arrive à la ville souhaité
        }else if(route[i].getFin() == indice){

            //ajout de la ville voisine au tableau 
            voisins.push_back(route[i].getDeb());

        }
    }
    //renvoi le tableau contenant les indices des voisins
    return voisins;

};

int Graphe::Distance(int ind_deb, int ind_fin){

    //parcours de toutes les routes connues
    for(int i = 0; i < route.size(); i++){
        //vérification de la coresspondance des 2 extrémitées de la route
        if(route[i].getDeb() == ind_deb && route[i].getFin() == ind_fin){
            
            //renvoi de la distance de la route souhaité
            return route[i].getDistance();
        
        //protection si la route est enregistré dans le sens inverse de celui renseigné
        }else if(route[i].getDeb() == ind_fin && route[i].getFin() == ind_deb){

            //renvoi de la distance de la route souhaité
            return route[i].getDistance();

        }
    }
};