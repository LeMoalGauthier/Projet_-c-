#include "Graphe.h"

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

vector<int> Graphe::Trajet(int ind_deb, int ind_fin){
    // * Cette algorithme se repose sur l'algorithme de Dijkstra
    vector<int> trajet;

    //création du tableau qui stocke les distance entre le point de départ et les autres points sur toute la carte 
    vector<int> dist;
    vector<bool> visite;

    //création des variables qui nous serviront de à retenir les information à chaque tour de boucle
    int dist_min, id_voisin_proche, id_position = ind_deb;

    //initialisation du tableau de distance et de visité
    for (int i = 0; i < waypoint.size() ; i++){
        if(i == id_position){
            dist.push_back(0);
            visite.push_back(true);
        }else{
            dist.push_back(100000);
            visite.push_back(false);
        }

    }
    //tant que l'on est pas 
    while(!visite[ind_fin]){
    
        //récupération des waypoints voisins du point actuel
        vector<int> voisins = Voisins(id_position);

        //initialisation de dist_min pour pour pouvoir ensuite retrouver le voisins le plus proche de la position actuelle
        dist_min = 10000;

        //récupération de la distance la plus courte entre les voisins
        for(int i = 0; i < voisins.size(); i++){
            if(dist[voisins[i]] > Distance(id_position, voisins[i])){
                dist[voisins[i]] = Distance(id_position, voisins[i]);
            }
        }

        //récupération du voisin le plus proche 
        for(int i = 0; i < waypoint.size(); i++){
            if(dist[i] < dist_min && !visite[i]){
                dist_min = dist[i];
                id_voisin_proche = i;
            }
        }

        //ajout de l'id de la route à mettre en rouge pour atteindre la destination
        for(int i = 0; i < route.size(); i++){
            if(route[i].getDeb() == id_position && route[i].getFin() == id_voisin_proche){
                trajet.push_back(i);
            }
        }

        //"déplacement" au voisin le plus court et mise à jour du tableau
        visite[id_voisin_proche] = true;
        id_position = id_voisin_proche;

        //sortie de la recherche du chemin le plus cours si la position actuelle est celle recherché

    }

    return trajet;

}