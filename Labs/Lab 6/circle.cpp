#include <iostream>
#include <string>
#include <cmath>
#include "./shape.h"
#include "./circle.h"

using namespace std;

Circle::Circle(string n, string c, float r) : Shape(n, c) {
    radius = r;
}

float Circle::area() {
    return (pow(radius, 2) * 3.14);
}