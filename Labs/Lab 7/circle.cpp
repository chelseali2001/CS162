#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <exception>
#include "./shape.h"
#include "./circle.h"

using namespace std;

Circle::Circle(string n, string c, float r) : Shape(n, c) {
    radius = r;  
    
    if (radius == 0)
        throw invalid_argument("Invalid constructor argument");
}

float Circle::area() const {
    return (pow(radius, 2) * 3.14);
}