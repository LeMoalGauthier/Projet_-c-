#include "ScenePlan.h"

std::map<std::string, QColor> ScenePlan::tab_couleurs =
 {{"rouge", Qt::red}, {"vert", Qt::green}};

ScenePlan::ScenePlan(Carte &carte)
{
	// Ajout des items graphiques dans la scène
	creer_carte(carte);
}

void ScenePlan::creer_carte(Carte &carte){
	qreal epais = 0;// épaisseur mur
	std::string text_tooltip;
	
	for (auto &contour : carte.getContour().getPoints()){ // Boucle permettant de compter tous les contours et les points dans la base de données
		Point *point=&contour;
		QColor coul = tab_couleurs["black"];
		//(!nb_points ) continue;
		int taille_contour = carte.getContour().getPoints().size();
		
		QGraphicsLineItem *ligne = nullptr;

		for ( int i=1; i < taille_contour; i++ ){

			ligne = new QGraphicsLineItem (point[i-1].getLon(),point[i-1].getLat(),
						  point[i].getLon(), point[i].getLat());
			ligne->setPen(QPen(coul, epais, Qt::SolidLine)); // Ajout des contours

			this->addItem(ligne); // Ajout de la ligne

			/*QGraphicsLineItem *point = new QGraphicsLineItem ( -epais/2, -epais/2, epais, epais);
			point->setPos(points[i].getLat(), points[i].getLon());
			point->setPen(QPen(Qt::black,0,Qt::SolidLine));
			point->setBrush(QBrush(Qt::gray,Qt::SolidPattern));
			// Création de la ligne permettant de lier deux points du contour

			point->setParentItem(ligne);*/
		} // fin création contour
		// Dernier point
		QGraphicsEllipseItem *points = new QGraphicsEllipseItem ( -epais/2, -epais/2, epais, epais);
		points->setPos(point[taille_contour-1].getLat(), point[taille_contour-1].getLon());
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