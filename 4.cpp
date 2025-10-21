// Q4_Multilevel.cpp
#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;   // protected so derived classes can access
    int age;

public:
    Person(const string &n = "", int a = 0) : name(n), age(a) {}
    void displayPerson() const {
        cout << "Name: " << name << ", Age: " << age << '\n';
    }
};

// Derived from Person
class Employee : public Person {
protected:
    int empId;
    double salary;

public:
    Employee(const string &n, int a, int id, double sal)
        : Person(n, a), empId(id), salary(sal) {}

    void displayEmployee() const {
        displayPerson(); // reuse Person's method
        cout << "EmpID: " << empId << ", Salary: " << salary << '\n';
    }
};

// Derived from Employee (multilevel)
class Manager : public Employee {
private:
    string department;

public:
    Manager(const string &n, int a, int id, double sal, const string &dept)
        : Employee(n, a, id, sal), department(dept) {}

    void displayManager() const {
        displayEmployee(); // passes data up the chain
        cout << "Department: " << department << '\n';
    }
};

int main() {
    Manager m("Alice", 35, 101, 90000.0, "R&D");
    m.displayManager();
    return 0;
}
