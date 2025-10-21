 // Q10_AbstractShape.cpp
#include <iostream>
#include <memory>   // for smart pointers
#include <cmath>    // for M_PI
using namespace std;

// Abstract base class: Shape
class Shape {
public:
    // Pure virtual function — makes Shape an abstract class
    virtual double area() const = 0;

    // Optional virtual destructor for safe polymorphic deletion
    virtual ~Shape() = default;
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor using initializer list
    Circle(double r) : radius(r) {
        if (r < 0.0) radius = 0.0; // simple guard
    }

    // Override pure virtual function
    double area() const override {
        return M_PI * radius * radius;
    }
};

// Derived class: Square
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {
        if (s < 0.0) side = 0.0;
    }

    double area() const override {
        return side * side;
    }
};

int main() {
    // Can't instantiate Shape directly: Shape s; // would be compile error

    // Use polymorphism: store derived objects as pointers to Shape
    unique_ptr<Shape> c = make_unique<Circle>(2.5);
    unique_ptr<Shape> sq = make_unique<Square>(3.0);

    cout << "Circle area: " << c->area() << '\n';
    cout << "Square area: " << sq->area() << '\n';

    // We can treat shapes uniformly:
    Shape* shapes[2] = { c.get(), sq.get() };
    for (Shape* s : shapes) {
        cout << "Area (polymorphic call): " << s->area() << '\n';
    }

    return 0;
}
