#include "Graphe.h"

Graphe::Graphe(){

    for(int i = 0; i< waypoint.size(); i++){
        adjascence.push_back(make_pair(INF,INF));
    }
}

void Graphe::Voisins(int indice, vector< pair<int,int> > &voisins){
   
    for(int i = 0; i < route.size(); i++){

        //vérification si la route commence à la ville souhaité
        if(route[i].getDeb() == indice){

            //ajout de la ville voisine au tableau 
            voisins.push_back(make_pair(route[i].getDistance() ,route[i].getFin()));

        //vérification si la route arrive à la ville souhaité
        }else if(route[i].getFin() == indice){

            //ajout de la ville voisine au tableau 
            voisins.push_back(make_pair(route[i].getDistance() ,route[i].getDeb()));

        }
    }
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


vector<Route> Graphe::Trajet(int ind_deb, int ind_fin){

    // * Cette algorithme se base sur l'algorithme de Dijkstra

    //voisins permet de stocker les voisins du noeud ou l'on est (1er int = distance, 2eme int = noeud destination) chemin récupère la liste de ville à parcourir pour atteindre la destination (en commencant par l'arrivée)
    vector< pair<int,int> > voisins, chemin;

    //id_position stocke notre position actuel idistance stocke la distance le voisin le + proche meilleur_voisin sauvegarde le meilleur voisin
    int id_position = ind_deb, idistance, proche_waypoint = ind_deb;

    //visité permet de savoir si l'on a déjà été à un waypoint
    vector<bool> visite; 
    //Permet de savoir si le waypoint le plus proche est un voisin du point actuel
    bool is_voisin;

    //Permet de sauvegarder les route à parcourir pour atteindre la destination depuis le point de départ
    vector<Route> trajet;

    //Modification du Graph en fonction point de départ
    adjascence[ind_deb].first = 0;
    adjascence[ind_deb].second = 0;

    //initialisation visite
    for(int i = 0; i < waypoint.size(); i++){
        if(i == ind_deb){
            visite.push_back(true);
        }else{
            visite.push_back(false);
        }
    }

    //cout << 0 << endl;

    // * Début Algo --------------------------------------------

    while(adjascence[ind_fin].first == INF){
        //Récupération des voisins du noeud de départ
        Voisins(id_position, voisins);

        //Initialisation de idistance
        idistance = INF;

        //recherche du noeud le plus proche du point de position (dans adjascence)
        for(int i = 0; i < adjascence.size(); i++){
            if(!visite[i] && adjascence[i].first < idistance){
                idistance = adjascence[i].first;
                proche_waypoint = i;
            }
        }

        //recherche du noeud le plus proche du point de position (dans voisin)
        for(int i = 0; i < voisins.size(); i++){
            if(!visite[voisins[i].second] && voisins[i].first < idistance){

                idistance = voisins[i].first;
                proche_waypoint = voisins[i].second;
            }    
        }

        //cin.ignore();
        //cout << "Waypoint : " << proche_waypoint << " Distance : " << idistance;
        
        //mise à jour des données pour la prochaine boucle
        adjascence[proche_waypoint].first = idistance;
        adjascence[proche_waypoint].second =  id_position;
        visite[proche_waypoint] = true;
        id_position = proche_waypoint;

        // // for(int i = 0; i < voisins.size() ; i++){
        // //     if(voisins[voisins.size()-i].second == proche_waypoint){
        // //         voisins.erase(voisins.end() - i);
        // //     }
        // // }

    }

    //récupération du chemin
    while(id_position != ind_deb){
        chemin.push_back(adjascence[id_position]);
        id_position = adjascence[id_position].second;
    }

    //création du trajet (de route)
    for(int i = 0; i < chemin.size(); i++){
        trajet.push_back(Route(id_position, chemin[chemin.size()-i].second, chemin[chemin.size()-i].first));
        id_position = chemin[chemin.size()-i].second;
    }

        trajet.push_back(Route(id_position, ind_fin, Distance(id_position,ind_fin)));

    return trajet;
}

