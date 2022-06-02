﻿#include "FenetrePrincipale.h"


FenetrePrincipale::FenetrePrincipale(Carte &carte_init) : carte(carte_init){

	setWindowTitle(tr("Itinéraire"));
	widget_general = new QWidget;

	QHBoxLayout * qbl_general = new QHBoxLayout;
	widget_general->setLayout(qbl_general);
	this->setCentralWidget(widget_general);

	largeur = 600;
	hauteur = 400; 
	setMinimumSize(largeur,hauteur);

	myscene = new ScenePlan(carte);
	grandeVue = new GrandeVue(myscene, this, 0);

	qbl_general->addWidget(itineraire()); // Ajout de la GroupBox
	qbl_general->addWidget(grandeVue); // Ajout de la grande vue
	barre_statut = statusBar(); // Ajout des coordonnées

    connect( grandeVue, &GrandeVue::position, this, &FenetrePrincipale::affiche_pos_scene); // Slot permettant de nous retourner la position de la souris en temps réel

	

}

FenetrePrincipale::~FenetrePrincipale() {
}

QGroupBox * FenetrePrincipale::itineraire() { // Création de la GroupBox itinéraire
	QGroupBox *itineraire = new QGroupBox;
	itineraire->setMaximumWidth(largeur/3);
	QLabel *depart = new QLabel(tr("Ville de départ"));
	QLineEdit *nameDepart = new QLineEdit;
	QLabel *arrivee = new QLabel(tr("Ville d'arrivée"));
	QLineEdit *nameArrivee = new QLineEdit;
	QPushButton *calculer = new QPushButton(tr("Calculer"));
	QLabel *distance = new QLabel(tr("Distance : "));
	miniVue = new MiniVue(myscene, this);

	QVBoxLayout *vbox = new QVBoxLayout;

	vbox->addWidget(depart);
	vbox->addWidget(nameDepart);
	vbox->addWidget(arrivee);
	vbox->addWidget(nameArrivee);
	vbox->addWidget(calculer);
	vbox->addWidget(distance);
	vbox->addWidget(miniVue);

	itineraire->setLayout(vbox);

	return itineraire;
}

void FenetrePrincipale::affiche_pos_scene( QPointF p){ // Suivi de la position de la souris
        QString msg = "Coordonnées géographiques ("
                        + QString::number(p.x(),'f',2) + ","
                        + QString::number(p.y(),'f',2) + ")";
        barre_statut->showMessage(msg);
}


