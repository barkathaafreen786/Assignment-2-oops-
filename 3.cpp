// Q3_ShapeRectangle.cpp
#include <iostream>
using namespace std;

class Shape {
public:
    // Virtual functions allow derived classes to override behavior
    virtual double area() const { return 0.0; }
    virtual double perimeter() const { return 0.0; }
    virtual ~Shape() = default; // virtual destructor
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override { return width * height; }
    double perimeter() const override { return 2 * (width + height); }
};

int main() {
    Rectangle r(4.0, 5.0);
    cout << "Rectangle area: " << r.area() << '\n';
    cout << "Rectangle perimeter: " << r.perimeter() << '\n';

    // polymorphism demo
    Shape *s = new Rectangle(2.5, 3.5);
    cout << "Polymorphic area: " << s->area() << '\n';
    delete s;
    return 0;
}
