#include <iostream>
#include <string>
#include <cmath>
#include "./shape.h"
#include "./rectangle.h"

using namespace std;

Rectangle::Rectangle(string n, string c, float w, float h) : Shape(n, c) {
    this->width = w;
    this->height = h;
}

float Rectangle::get_width() {
    return width;
}

float Rectangle::get_height() {
    return height;
}

float Rectangle::area() const {
    return (width * height);
}

bool Rectangle::operator> (const Rectangle &r) {
    float r1_area = area();
    float r2_area = r.area();

    return (r1_area > r2_area);
}

bool Rectangle::operator< (const Rectangle &r) {
    float r1_area = area();
    float r2_area = r.area();

    return (r1_area < r2_area);
}