#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <exception>

using namespace std;

class Shape {
    private:
        string name;
        string color;
    
    public:
        Shape(string, string);
        void print_shape_info(Shape&);
        virtual float area() const = 0;
};