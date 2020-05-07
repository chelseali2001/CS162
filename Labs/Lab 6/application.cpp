#include <iostream>
#include <string>
#include <cmath>
#include "./shape.h"
#include "./rectangle.h"
#include "./circle.h"
#include "./square.h"

using namespace std;

int main() {
    Shape s("shape", "white");
    Rectangle r1("rectangle", "blue", 2, 3);
    Rectangle r2("rectangle", "green", 5, 6);
    Circle c("circle", "red", 3);
    Square sq("square", "yellow", 2);

    cout << "Shape s: " << s.get_name() << ", color: " << s.get_color() << ", area = " << s.area() <<endl;
    cout << "Shape r1: " << r1.get_name() << ", color: " << r1.get_color() << ", area = " << r1.area() <<endl;
    cout << "Shape r2: " << r2.get_name() << ", color: " << r2.get_color() << ", area = " << r2.area() <<endl;

    if (r1 > r2)
        cout << "r1 has a greater area than r2" <<endl;
    else if (r1 < r2)
        cout << "r1 has a smaller area than r2" <<endl;
    
    cout << "Shape c: " << c.get_name() << ", color: " << c.get_color() << ", area = " << c.area() <<endl;
    cout << "Shape sq: " << sq.get_name() << ", color: " << sq.get_color() << ", area = " << sq.area() <<endl;

    return 0;
}