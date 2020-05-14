#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <exception>

using namespace std;

class Circle : public Shape {
    private:
        float radius;

    public:
        Circle(string, string, float);
        float area() const;
};