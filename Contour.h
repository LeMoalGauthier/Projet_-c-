#ifndef CONTOUR_H
#define CONTOUR_H

#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

class Contour{
    private :
        vector<Point> point;

    public :
        Contour();
        ~Contour(){};

        vector<Point> getPoints(){return point;}
        void ajoutUnPoint(Point new_pt){point.push_back(new_pt);};
        
};

#endif;