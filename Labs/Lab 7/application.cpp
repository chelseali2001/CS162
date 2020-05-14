#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <exception>
#include "./shape.h"
#include "./rectangle.h"
#include "./circle.h"
#include "./square.h"

using namespace std;

int main() {
    Shape *shape;
    Rectangle rectangle("rectangle", "blue", 2, 3);
    Circle circle("circle", "red", 3);
    Square square("square", "yellow", 4);
    
    try {
        Rectangle throw_rectangle("rectangle", "blue", 0, 3);
    } catch (const invalid_argument& e) {
        cout << e.what() <<endl;
    }

    try {
        Circle throw_circle("circle", "red", 0);
    } catch (const invalid_argument& e) {
        cout << e.what() <<endl;
    }


    try {
        Square throw_square("square", "yellow", 0);
    } catch (const invalid_argument& e) {
        cout << e.what() <<endl;
    }
 
    shape = &rectangle;
    shape->print_shape_info(*shape);
    
    shape = &circle;
    shape->print_shape_info(*shape);
    
    shape = &square;
    shape->print_shape_info(*shape);

    return 0;
}
