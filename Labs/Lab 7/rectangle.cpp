#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <exception>
#include "./shape.h"
#include "./rectangle.h"

using namespace std;

Rectangle::Rectangle(string n, string c, float w, float h) : Shape(n, c) {
    this->width = w;
    this->height = h;
    
    if (width == 0 || height == 0)
        throw invalid_argument("Invalid constructor argument");
}

float Rectangle::area() const {
    return (width * height);
}