// includes VIEW
#include <QApplication>
#include <QMessageBox>
#include "FenetrePrincipale.h"

// includes MODEL
#include <cppconn/exception.h>
#include "Carte.h"

int main(int argc, char **argv) {

	QApplication app(argc, argv);
	Carte carte;
	std::string host, base, user, pwd;
	// Initialisation des variables

	std::cout << "Lecture base plans" << std::endl;
	
	FenetrePrincipale mw (carte);
	mw.show();
	// Affichage de l'onglet principale

	return app.exec();
}
