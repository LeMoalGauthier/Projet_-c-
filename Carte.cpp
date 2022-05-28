#include "Carte.h"

Carte::Carte(){

        // Création des vector qui stockerons les informations de la table ville pour les comparer à la table Waypoint 
        vector<Ville> tab_info_ville;
        vector<string> tab_nom_ville;
        int i_deb, i_fin;
        bool verif;

    	sql::Connection *con;
		/* Create a connection */
		sql::Driver *driver = get_driver_instance();
		con = driver->connect("localhost","root","isen29");

		/* Connect to the MySQL database */
		con->setSchema("db_projet");

		sql::Statement *stmt = con->createStatement();

        //récupération de la table ville
 		sql::ResultSet *res = stmt->executeQuery("select * from ville");
		res->next();

        //Remplissage des tableaux comprenant les infos de la table ville
		while(res->next()){ 
			tab_info_ville.push_back(Ville(res->getString(2),res->getInt(3),res->getString(4)));
            tab_nom_ville.push_back(res->getString(1));
		}

        //récupération de la table waypoint
        sql::ResultSet *res1 = stmt->executeQuery("select * from waypoint");
		res1->next();

        //parcours de la table
        while(res1->next()){ 

            verif = false;

            //vérification de l'état du Waypoint
            for(int i = 0; i < tab_nom_ville.size(); i++){

                //Si le waypoint est une ville, création d'une Ville en combinant les infos de la table waypoint de ville
                if(res1->getString(1) == tab_nom_ville[i]){
                    waypoint.push_back(Ville(res1->getString(1),res1->getDouble(3),res1->getDouble(2),tab_info_ville[i].getCodePostal(),tab_info_ville[i].getNbHabitants(),tab_info_ville[i].getSite()));
                    verif = true;
                    break;
                }
            }
            //Si ce n'est pas une Ville, création d'un simple Waypoint
            if(!verif){
                waypoint.push_back(Waypoint(res1->getString(1),res1->getDouble(3),res1->getDouble(2)));
            }
		}

        //récupération de la table route
        sql::ResultSet *res2 = stmt->executeQuery("select * from route");
		res2->next();

        //parcours de la table
        while(res2->next()){

            for(int i = 0; i < waypoint.size(); i++ ){

                //si le nom de départ de la route est le nom du waypoint au rang i, on sauvegarde ce i pour id de départ et on cherche l'id de la route d'arrivée
                if(res2->getString(1) == waypoint[i].getNom()){

                    i_deb = i;
                    for(int j = 0; j < waypoint.size(); j++){
                        cout << res2->getString(2) << waypoint[j].getNom() << endl;

                        if(res2->getString(2) == waypoint[j].getNom()){
                            i_fin = j;
                        }
                    }
        
                }
                
            }
                
            //création de la route avec les infos récupérées
            route.push_back(Route(i_deb,i_fin,res2->getInt(3)));
        }

		delete con;
}