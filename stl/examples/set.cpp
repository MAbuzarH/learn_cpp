#include <string>
#include <vector>
#include <set>
#include <iostream>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);

    std::string Name;
    int Age;

public:
    // Person() = default;
    Person(std::string name = "unknone", int age = 0) : Name(name), Age(age) {};

    bool operator==(const Person &rhs) const
    {
        return (Name == rhs.Name && Age == rhs.Age);
    }
    bool operator<(const Person &rhs) const
    {
        return (this->Age < rhs.Age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
    os << rhs.Name << " : " << rhs.Age << std::endl;
    return os;
}

template <typename T>
void display(std::set<T> &set)
{
    std::cout << "\n [";
    for (auto &s : set)
    {
        std::cout << s << " ";
    }
    std::cout << "]\n";
}

void test1()
{
    std::cout << "Test 1==================\n";

    std::set<int> set1{1, 2, 3, 4, 5};
    display(set1);

    set1 = {1, 2, 2, 4, 4, 3, 3, 5, 5, 5, 6, 9, 9, 9, 8};
    display(set1);

    set1.insert(0);
    set1.insert(10);
    display(set1);

    if (set1.count(10))
    {
        std::cout << "10 is in the set" << std::endl;
    }
    else
    {
        std::cout << "10 is not in the set" << std::endl;
    }

    std::set<int>::iterator it = set1.find(5);
    if (it != set1.end())
    {
        std::cout << "Founded" << std::endl;
    }

    set1.clear();
    display(set1);
}

void test2()
{
    std::cout << "Test 2==================\n";

    std::set<Person> Stoogy{{"John", 2},
                            {"con", 5},
                            {"sone", 3}};
    display(Stoogy);

    Stoogy.emplace("jams", 50);
    display(Stoogy);

    Stoogy.emplace("raseli", 50);
    display(Stoogy);

    auto it = Stoogy.find(Person("jams", 50));

    if (it != Stoogy.end())
    {
        Stoogy.erase(it);
    }
}

void test3()
{
    std::cout << "Test 3==================\n";
    std::set<std::string> s{"A", "B", "C", "D", "E"};
    display(s);

    auto result = s.insert("F");
    display(s);

    std::cout << std::boolalpha;
    std::cout << "first: " << *(result.first) << std::endl;
    std::cout << "second: " << result.second << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
