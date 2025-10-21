// Q6_FriendFunction.cpp
#include <iostream>
#include <string>
using namespace std;

class Sports; // forward

class Student {
private:
    string name;
    int marks; // academic marks

public:
    Student(const string &n, int m) : name(n), marks(m) {}

    // declare friend function to access private members
    friend void displayCombined(const Student &s, const Sports &sp);
};

class Sports {
private:
    int score; // sports score
public:
    Sports(int sc) : score(sc) {}
    friend void displayCombined(const Student &s, const Sports &sp);
};

// friend function definition
void displayCombined(const Student &s, const Sports &sp) {
    cout << "Student: " << s.name << '\n';
    cout << "Marks: " << s.marks << ", Sports Score: " << sp.score << '\n';
    cout << "Combined (marks + score): " << (s.marks + sp.score) << '\n';
}

int main() {
    Student st("Tina", 85);
    Sports sp(12);
    displayCombined(st, sp);
    return 0;
}
