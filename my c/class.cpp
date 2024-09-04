#include <iostream>
#include <string>
#include <vector>

// Introduction to Objects and Classes
class Person {
protected:
    std::string name;

public:
    Person(const std::string& n) : name(n) {}

    // Getter
    std::string getName() const {
        return name;
    }
};

// Inheritance
class Student : public Person {
private:
    int studentId;

public:
    // Constructor with initialization list
    Student(const std::string& n, int id) : Person(n), studentId(id) {}

    // Destructor
    ~Student() {
        std::cout << "Student " << name << " with ID " << studentId << " is being destroyed.\n";
    }

    // Constant data member
    const int getStudentId() const {
        return studentId;
    }

    // Static variable
    static int totalStudents;

    // Setter for static variable
    static void setTotalStudents(int count) {
        totalStudents = count;
    }

    // Accessor function and "this" pointer
    void displayInfo() const {
        std::cout << "Student Name: " << this->name << ", ID: " << this->studentId << std::endl;
    }

    // Array of Objects
    static std::vector<Student> studentList;

    // Operator Overloading
    Student operator+(const Student& other) {
        return Student(this->name + "-" + other.name, this->studentId + other.studentId);
    }
};

// Initializing static variables
int Student::totalStudents = 0;
std::vector<Student> Student::studentList;

int main() {
    // Creating objects
    Student alice("Alice", 101);
    Student bob("Bob", 102);

    // Using getter
    std::cout << "Student Name: " << alice.getName() << std::endl;

    // Using constant data member and static variable
    std::cout << "Student ID: " << alice.getStudentId() << std::endl;
    std::cout << "Total Students: " << Student::totalStudents << std::endl;

    // Using accessor function and "this" pointer
    alice.displayInfo();

    // Using operator overloading
    Student combined = alice + bob;
    std::cout << "Combined Student: " << combined.getName() << ", ID: " << combined.getStudentId() << std::endl;

    // Array of Objects
    Student::studentList.push_back(alice);
    Student::studentList.push_back(bob);

    // Separation of Interface & Implementation
    for (const auto&  student : Student::studentList) {
        student.displayInfo();
    }

    return 0;
}

