#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <exception>

using namespace std;

class Rectangle : public Shape {
   private:
        float width;
        float height;

   public:
        Rectangle(string, string, float, float);
        float area() const;
};