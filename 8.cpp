// Q8_Polymorphism.cpp
#include <iostream>
using namespace std;

class Base {
public:
    // Overloaded functions (compile-time polymorphism)
    void display() const { cout << "Display with no args\n"; }
    void display(int x) const { cout << "Display with int: " << x << '\n'; }

    // Virtual function for run-time polymorphism
    virtual void speak() const { cout << "Base speaks\n"; }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    // Overriding speak() for runtime polymorphism
    void speak() const override { cout << "Derived speaks\n"; }
};

int main() {
    Base b;
    b.display();
    b.display(42);   // compile-time resolution of overloads

    Base *p = new Derived();
    p->speak();      // run-time resolved to Derived::speak() due to virtual
    delete p;

    return 0;
}
