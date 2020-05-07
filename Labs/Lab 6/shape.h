#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Shape {
    private:
        string name;
        string color;
    
    public:
        Shape(string, string);
        string get_name();
        string get_color();
        void set_name(string);
        void set_color(string);
        float area();
};