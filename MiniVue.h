#ifndef MINIVUE_H
#define MINIVUE_H
#include <QGraphicsView>
#include <QPolygon>
#include <vector>
#include "Carte.h"
#include "Contour.h"
#include "Point.h"

#include "ScenePlan.h"

class MiniVue : public QGraphicsView {
	Q_OBJECT
	public :
		MiniVue(ScenePlan *scene, QWidget *w):QGraphicsView(scene, w){
			Q_UNUSED(scene);
			scale(1, -1); // inversion des y
		}
		~MiniVue(){}
	public slots:
		void trace_viewport( QRectF rect_viewport){
			cadre = rect_viewport;
			viewport()->update();
		}
	private:

		void drawForeground( QPainter *painter, const QRectF &) override {
			//painter->save(); // pas utile
			//painter->setBrush(QBrush(Qt::NoBrush));// par défaut
			painter->setPen(QPen(Qt::black, 0));
			painter->drawRect(cadre);
			//painter->restore(); // pas utile
		}
		// Gestionnaires d'évènements

		// Fit de la vue sur les limites de la scène
		void resizeEvent (QResizeEvent * ) override {
			if ( this->transform().m11() == 1 ){
				this->fitInView(sceneRect(), Qt::KeepAspectRatio);
			}
		}

	private:
		QRectF cadre;
};


#endif
