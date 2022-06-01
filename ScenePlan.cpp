#include "ScenePlan.h"
#include "model/BDD.h"
#include "model/Carte.h"

std::map<std::string, QColor> ScenePlan::tab_couleurs =
 {{"rouge", Qt::red}, {"vert", Qt::green}};

ScenePlan::ScenePlan(Carte &carte)
{
	// Ajout des items graphiques dans la scène
	creer_carte(carte);
}

void ScenePlan::creer_carte(Carte &carte){
	qreal epais = 1;// épaisseur mur
	std::string text_tooltip;
	
	for (auto &contour : carte.getContour().getPoints() ){
		Point *point=&contour;
		QColor coul = tab_couleurs["black"];
		int nb_points = sizeof(contour);
		//if ( !nb_points ) continue;
		
		QGraphicsLineItem *ligne = nullptr;

		for ( int i=1; i < nb_points; ++i ){

			ligne = new QGraphicsLineItem (point[i-1].getLat(),point[i-1].getLon(),
						  point[i].getLat(), point[i].getLon());
			ligne->setPen(QPen(coul, epais, Qt::SolidLine));

			this->addItem(ligne);

			/*QGraphicsLineItem *point = new QGraphicsLineItem ( -epais/2, -epais/2, epais, epais);
			point->setPos(points[i].getLat(), points[i].getLon());
			point->setPen(QPen(Qt::black,0,Qt::SolidLine));
			point->setBrush(QBrush(Qt::gray,Qt::SolidPattern));*/

			//text_tooltip = points[i].getInfos();
			/*point->setToolTip(QString::fromStdString(text_tooltip));

			point->setParentItem(ligne);*/
		} // fin création point
		// Dernier point
		QGraphicsEllipseItem *points = new QGraphicsEllipseItem ( -epais/2, -epais/2, epais, epais);
		points->setPos(point[nb_points-1].getLat(), point[nb_points-1].getLon());
		points->setPen(QPen(Qt::black,0,Qt::SolidLine));
		points->setBrush(QBrush(Qt::gray,Qt::SolidPattern));

		/*text_tooltip = points[nb_points-1].getInfos();
		point->setToolTip(QString::fromStdString(text_tooltip));*/

		points->setParentItem(ligne);

	}// fin création mur

	// Matérialisation du point origine de la scène (taille = épaisseur mur)
	qreal taille_o = epais;
	QGraphicsEllipseItem *origine = new QGraphicsEllipseItem(-taille_o/2,-taille_o/2,taille_o,taille_o);
	origine->setPos(0,0);
	origine->setPen(QPen(Qt::black,0,Qt::SolidLine));
	this->addItem(origine);

}