#ifndef MYSCENE_H
#define MYSCENE_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>

#include "model/Contour.h"
#include "model/Point.h"
#include "model/Carte.h"

class ScenePlan : public QGraphicsScene {
	Q_OBJECT
	public :
		ScenePlan(Carte &);
		void creer_carte(Carte &carte);
	private:
		static std::map<std::string, QColor> tab_couleurs;
};

#endif