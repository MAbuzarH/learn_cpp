#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs)
    {
        os << rhs.Name << " : " << rhs.Age << std::endl;
        return os;
    }
    std::string Name;
    int Age;

public:
    // Person() = default;
    Person(std::string name = "unknone", int age = 0) : Name(name), Age(age) {};

    bool operator==(const Person &rhs)
    {
        return Name == rhs.Name && Age == rhs.Age;
    }
    bool operator<(const Person &rhs)
    {
        return (this->Age < rhs.Age);
    }
};

template <typename T>
void display(std::list<T> &list)
{
    std::cout << "\n [";
    for (auto &l : list)
    {
        std::cout << l << " ";
    }
    std::cout << "]\n";
}

void test1()
{
    std::cout << "Test 1====================\n";

    std::list<int> l1{1, 2, 3, 4, 5};
    display(l1);

    std::list<std::string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

    std::list<int> l3;
    l3 = {1, 2, 3, 4, 5};
    display(l3);

    std::list<int> l4(10, 100);
    display(l4);
}

void test2()
{
    std::cout << "Test 2====================\n";

    std::list<int> l1{1, 2, 3, 4, 5, 6, 7};
    display(l1);

    std::cout << "Size: " << l1.size() << std::endl;
    std::cout << "Front: " << l1.front() << std::endl;
    std::cout << "Back: " << l1.back() << std::endl;

    l1.clear();
    display(l1);

    std::cout << "Size: " << l1.size() << std::endl;
}

void test3()
{
    std::cout << "Test 2====================\n";

    std::list<int> l1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l1);

    l1.resize(5);
    display(l1);

    l1.resize(10);
    display(l1);

    std::list<Person> p1;
    p1.resize(10);
    display(p1);
}

void test4()
{
    std::cout << "Test 4====================\n";

    std::list<int> l1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l1);
    auto it = std::find(l1.begin(), l1.end(), 5);
    if (it != l1.end())
    {
        l1.insert(it, 100);
    }
    display(l1);

    std::list<int> l2{1000, 2000, 3000};
    l1.insert(it, l2.begin(), l2.end());
    display(l1);

    std::advance(it, -4);
    std::cout << *it << std::endl;

    l1.erase(it);
    display(l1);
}

// void test5()
// {
//     std::cout << "Test 5====================\n";

//     std::list<Person> stoogy{
//         {"ali", 20},
//         {"asam", 70},
//         {"qasam", 80}};

//     display(stoogy);

//     std::string name;
//     int age;

//     std::cout << " \n Enter Name: ";
//     std::getline(std::cin, name);
//     std::cout << " \n Enter age: ";
//     std::cin >> age;

//     stoogy.emplace_back(name, age);
//     display(stoogy);

//     auto it = std::find(stoogy.begin(), stoogy.end(), Person("Ali", 20));
//     if (it != stoogy.end())
//     {
//         stoogy.emplace_back(it, "jaber", 70);
//     }
//     display(stoogy);
// }

void test5()
{
    std::cout << "Test 5====================\n";

    std::list<Person> stoogy{
        {"ali", 20},
        {"asam", 70},
        {"qasam", 80}};

    display(stoogy);

    std::string name;
    int age;

    std::cout << " \n Enter Name: ";
    std::getline(std::cin, name);
    std::cout << " \n Enter age: ";
    std::cin >> age;
    std::cin.ignore(); // To prevent any newline issues

    stoogy.emplace_back(name, age);
    display(stoogy);

    // Corrected: Case-sensitive comparison and use of emplace instead of emplace_back
    auto it = std::find(stoogy.begin(), stoogy.end(), Person("ali", 20));
    if (it != stoogy.end())
    {
        stoogy.emplace(it, "jaber", 70);
    }
    display(stoogy);
}

void test6()
{
    std::cout << "Test 5====================\n";

    std::list<Person> stoogy{
        {"ali", 20},
        {"Msam", 70},
        {"qasam", 80},
        {"basam", 60}};

    display(stoogy);
    stoogy.sort();
    display(stoogy);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}