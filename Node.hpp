#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    string name;
    float latitude;
    float longitude;
    int gifts;

public:
    // Constructor
    Node(string n = "", float lat = 0.0f, float lon = 0.0f, int g = 0){
        name = n;
        latitude = lat;
        longitude = lon;
        gifts = g;
    }

    // Setter functions
    void set_name(string n) { name = n; }
    void set_latitude(float lat) { latitude = lat; }
    void set_longitude(float lon) { longitude = lon; }
    void set_gifts(int g) { gifts = g; }

    // Getter functions (marked as const)
    string get_name() const { return name; }
    float get_latitude() const { return latitude; }
    float get_longitude() const { return longitude; }
    int get_gifts() const { return gifts; } // Marked as const
};
