#ifndef NODE_HPP
#define NODE_HPP

#include <string>
using namespace std;

class Node{
    private:
        string name;
        float latitude;
        float longitude;
        int gifts;

    public:
        //constructor
        Node(string n = "", float lat =0.0f, float lon = 0.0f, int g = 0)
            : name(n), latitude(lat), longitude(lon), gifts(g) {}

        //setters functions
        void set_name(string n){name = n;}
        void set_latitude(float lat){latitude = lat;}
        void set_longitude(float lon){longitude = lon;}
        void set_gifts(int g){gifts = g;}

        //getters functons
        string get_name(){return name;}
        float get_latitude(){return latitude;}
        float get_longitude(){return longitude;}
        int get_gifts(){return gifts;}
};

#endif