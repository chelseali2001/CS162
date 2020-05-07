#include <iostream>
#include <string>
#include <cmath>
#include "./shape.h"

using namespace std;

Shape::Shape(string n, string c) {
    this->name = n;
    this->color = c;
}

string Shape::get_name() {
    return name;
}

string Shape::get_color() {
    return color;
}

float Shape::area() {
    return 0;
}