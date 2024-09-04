#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    long phn; // Change the data type to long for phone number

public:
    Person(string n, int a, long p) {
        name = n;
        age = a;
        phn = p;
    }
 int getage(){
 	return age;
 }
    void print() {
        cout << "name = " << name << endl;
        cout << "age = " << age << endl;
        cout << "phn = " << phn << endl;
    }
};

class Adult : public Person {
public:
    // Constructor for Adult class, calling the base class constructor
    Adult(string n, int a, long p) : Person(n, a, p) {}

    void setAge() {
        // Use the age member inherited from the base class
        if (age >= 18) {
            cout << "Adult" << endl;
//            Person::print(); // Corrected syntax to call the print method
        } else {
            cout << "Child" << endl;
        }
    }
};

int main() {
    Adult a1("Ali", 22, 202020);
    a1.print();
//    a1.setAge(); // Check if Adult or Child
    return 0;
}

