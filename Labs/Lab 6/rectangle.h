#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Rectangle : public Shape {
   private:
        float width;
        float height;

   public:
        Rectangle(string, string, float, float);
        float get_width();
        float get_height();
        float area() const;
        bool operator> (const Rectangle &);
        bool operator< (const Rectangle &);
};