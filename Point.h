#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

class Point{

    private :
        int num;
        float lat;
        float lon;
        

    public :
        Point (){};
        Point (int new_num, float new_lat, float new_lon) {num = new_num; lat = new_lat; lon = new_lon;}
        ~Point(){};
        float getLon(){return lon;}
        float getLat(){return lat;}
        void affiche(){cout << "Num : " << num << " Latitude : " << lat << " Longitude : " << lon << endl;}
};

#endif