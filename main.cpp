// includes VIEW
#include <QApplication>
#include <QMessageBox>
#include "FenetrePrincipale.h"

// includes MODEL
#include <cppconn/exception.h>
#include "model/Carte.h"
#include "model/BDD.h"

int main(int argc, char **argv) {

	QApplication app(argc, argv);

	std::string host, base, user, pwd;

	std::cout << "Lecture base plans" << std::endl;
	Carte carte;
	Contour contour;
	Route route;

	try {
		// Connexion BD
		BDD bdd("tcp://"+host+":3306", base, user, pwd);
		// Récupération des contours
		carte = bdd.ajouterContours(carte);
		// Récupération des routes
		carte = bdd.ajouterRoutes(carte);
		// Récupération des waypoints
		carte = bdd.ajouterRoutes(carte);
		carte.affiche();
	}
	catch (sql::SQLException &e) {
		std::cout << "Erreur MySQL. Sortie de l'application\n";
		QMessageBox msg( QMessageBox::Critical, "Erreur mySQL", e.what());
		msg.exec();
		return 1;
	}
	
	FenetrePrincipale mw ( carte );
	mw.show();

	return app.exec();
}
