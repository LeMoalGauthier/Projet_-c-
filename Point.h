#ifndef POINT_H
#define POINT_H
#include <iostream>
#include "Contour.h"

using namespace std;

class Point{

    private :
        float lat;
        float lon;
        int num;

    public :
        Point (){};
        ~Point(){};
        float getLon(){return lon;}
        float getLat(){return lat;}
};

#endif;