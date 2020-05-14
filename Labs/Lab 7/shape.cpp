#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <exception>
#include "./shape.h"

using namespace std;

Shape::Shape(string n, string c) {
    this->name = n;
    this->color = c;
}

void Shape::print_shape_info(Shape &shape) {
    cout << "Shape name: " << shape.name <<endl;
    cout << "Shape color: " << shape.color <<endl;
    cout << "Shape area: " << area() <<endl;
}