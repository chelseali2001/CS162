#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Square : public Rectangle {
    public:
        Square(string, string, float);
        float area();
};