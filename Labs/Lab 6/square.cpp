#include <iostream>
#include <string>
#include <cmath>
#include "./shape.h"
#include "./rectangle.h"
#include "./square.h"

using namespace std;

Square::Square(string n, string c, float s) : Rectangle(n, c, s, s) {}

float Square::area() {
    return (get_width() * get_height());
}