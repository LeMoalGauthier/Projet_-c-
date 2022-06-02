#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H
#include <QGroupBox>
#include <QLayout>
#include <QGraphicsView>
#include <QLabel>
#include <QMainWindow>
#include <QStatusBar>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QSlider>
#include <QPainter>

#include "ScenePlan.h"
#include "GrandeVue.h"
#include "MiniVue.h"
#include "Carte.h"


class FenetrePrincipale : public QMainWindow {
	Q_OBJECT
	public:
		FenetrePrincipale(Carte &carte);
		~FenetrePrincipale();
	private:
		QGroupBox *itineraire();
	private slots:
		void affiche_pos_scene( QPointF p);
	private:
		QWidget *widget_general;
		ScenePlan *myscene;
		GrandeVue *grandeVue;
		MiniVue *miniVue;
		QStatusBar *barre_statut;
		Carte &carte;
		
		int hauteur;
		int largeur;
		
};
#endif
