#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <exception>
#include "./shape.h"
#include "./rectangle.h"
#include "./square.h"

using namespace std;

Square::Square(string n, string c, float s) : Rectangle(n, c, s, s) {}