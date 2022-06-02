#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

#include "Contour.h"
#include "Point.h"
#include "Carte.h"

class ScenePlan : public QGraphicsScene {
	Q_OBJECT
	public :
		ScenePlan(Carte &);
		void creer_carte(Carte &);
	private:
		static std::map<std::string, QColor> tab_couleurs;
};

#endif