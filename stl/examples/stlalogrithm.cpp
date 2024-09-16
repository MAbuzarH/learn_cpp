#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <cctype>

class Person
{
private:
    std::string Name;
    int Age;

public:
    Person() = default;
    Person(std::string name, int age) : Name(name), Age(age) {}

    bool operator<(const Person &rhs) const
    {
        return this->Age < rhs.Age;
    }
    bool operator==(const Person &rhs) const
    {
        return (this->Age == rhs.Age);
    }
};

// finde test
void find_test()
{
    std::vector<int> vec{1, 2, 3, 4};

    // make an itereator
    std::vector<int>::iterator itr = std::find(std::begin(vec), std::end(vec), 3);

    if (itr != vec.end())
    {
        std::cout << "Number founded in  " << *itr << "\n";
    }
    else
    {
        std::cout << "Number not founded  \n";
    }
    // do the same thing for user defined classes
    std::list<Person> p1 = {{"Ali", 20}, {"alam Ali", 25}, {"qasam Ali", 29}};

    std::list<Person>::iterator itr1 = std::find(std::begin(p1), std::end(p1), Person{"Ali", 20});
    if (itr1 != std::end(p1))
    {
        std::cout << "Number founded in  " << "\n";
    }
    else
    {
        std::cout << "Number not founded  \n";
    }
}

void count_test()
{
    std::vector<int> vec{1, 2, 3, 4, 2, 5, 6, 7, 2};
    int num = std::count(std::begin(vec), std::end(vec), 2);
    std::cout << "Number founded in  " << num << " Times \n";
}

void count_if_test()
{
    // finding even number from vector
    std::vector<int> vec{1, 2, 3, 4, 8, 5, 6, 7, 10};
    int num = std::count_if(std::begin(vec), std::end(vec), [](int x)
                            { return x % 2 == 0; });
    std::cout << "Even Number founded in  " << num << " Times \n";
    int num2 = std::count_if(std::begin(vec), std::end(vec), [](int x)
                             { return x % 2 != 0; });
    std::cout << "odd Number founded in  " << num2 << " Times \n";

    // write a code that tels that in vac<> >=5
    int num3 = std::count_if(std::begin(vec), std::end(vec), [](int x)
                             { return x >= 2; });
    std::cout << "Number founded   " << num3 << " >=2 \n";
}

void replace_test()
{
    std::vector<int> vec{1, 2, 3, 1, 4, 8, 5, 1, 6, 7, 10, 1};

    std::cout << "[";
    for (auto &ve : vec)
    {
        std::cout << ve << " ";
    }
    std::cout << "]\n";

    std::replace(vec.begin(), vec.end(), 1, 100);

    std::cout << "[";
    for (auto &ve : vec)
    {
        std::cout << ve << " ";
    }
    std::cout << "]\n";
}

void all_of_test()
{
    std::vector<int> vec{1, 2, 3, 1, 4, 8, 5, 1, 6, 7, 10, 1, 20};

    if (std::all_of(vec.begin(), vec.end(), [](int x)
                    { return x < 10; }))
    {
        std::cout << "All numbers are greater than 10" << std::endl;
    }
    else
    {
        std::cout << " no All numbers are not greater than 10" << std::endl;
    }
    if (std::all_of(vec.begin(), vec.end(), [](int x)
                    { return x < 21; }))
    {
        std::cout << "All numbers are greater than 21" << std::endl;
    }
    else
    {
        std::cout << " no All numbers are not greater than 10" << std::endl;
    }
}

void trnsform_string_test()
{
    std::string s1{"The string is this"};
    std::cout << "string before \n";
    std::cout << s1;
    std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    std::cout << "string after \n";
    std::cout << s1;
}

int main()
{
    // find_test();
    // count_test();
    // count_if_test();
    // all_of_test();
    // replace_test();
    trnsform_string_test();
    return 0;
}