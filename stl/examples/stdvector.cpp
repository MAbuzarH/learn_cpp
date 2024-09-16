#include <iostream>
#include <algorithm>
#include <vector>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &per);
    std::string Name;
    int Age;

public:
    Person() = default;
    Person(std::string name, int age) : Name(name), Age(age) {}

    bool operator==(const Person &rhs)
    {
        return (this->Name == rhs.Name && this->Age == rhs.Age);
    }
    bool operator<(const Person &rhs)
    {
        return (this->Age < rhs.Age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &per)
{
    os << per.Name << " : " << per.Age;
    return os;
}

void display2(const std::vector<int> &vector)
{
    std::cout << "[";
    std::for_each(vector.begin(), vector.end(), [](int x)
                  { std::cout << x << " "; });
    std::cout << "]\n";
}

template <typename T>
void display(const std::vector<T> &vector)
{
    std::cout << "[";
    for (const auto &v : vector)
    {
        std::cout << v << " ";
    }
    std::cout << "]\n";
}

// test cases
void test()
{
    std::cout << "Test !=============== \n";
    std::vector<int> vect1{1, 2, 3, 4, 5};
    display2(vect1);

    std::vector<int> vect2(10, 100);
    display2(vect2);
}

void test2()
{
    std::cout << "Test 2 =============== \n";
    std::vector<int> vect1{1, 2, 3, 4, 5};
    display2(vect1);

    std::cout << "\n vec size " << vect1.size();
    std::cout << "\n max vec size " << vect1.max_size();
    std::cout << "\n vec capesty " << vect1.capacity();
    vect1.push_back(6);

    std::cout << "\n vec size " << vect1.size();
    std::cout << "\n max vec size " << vect1.max_size();
    std::cout << "\n vec capesty " << vect1.capacity();

    vect1.shrink_to_fit();
    display2(vect1);
    std::cout << "\n vec size " << vect1.size();
    std::cout << "\n max vec size " << vect1.max_size();
    std::cout << "\n vec capesty " << vect1.capacity();

    vect1.reserve(100);
    display2(vect1);
    std::cout << "\n vec size " << vect1.size();
    std::cout << "\n max vec size " << vect1.max_size();
    std::cout << "\n vec capesty " << vect1.capacity();
}

void test3()
{
    std::cout << "\n Test 3 =============== \n";
    std::vector<int> vect1{1, 2, 3, 4, 5};
    display2(vect1);

    vect1[0] = 200;
    vect1.at(3) = 1000;
    display2(vect1);
}

void test4()
{
    std::cout << "\n Test 4 =============== \n";
    std::vector<Person> stogy;
    display(stogy);

    Person p1{"ali", 20};
    stogy.push_back(p1);
    display(stogy);

    stogy.push_back(Person{"Qasam", 90});
    display(stogy);

    stogy.emplace_back("Gugli", 40);
    display(stogy);
}

void test5()
{
    std::cout << "\n Test 5 =============== \n";
    std::vector<Person> stogy{
        {"ali", 20},
        {"Qasam", 90},
        {"Gugli", 40}};
    display(stogy);

    std::cout << "\n Front " << stogy.front() << std::endl;
    std::cout << "\n Back  " << stogy.back() << std::endl;

    stogy.pop_back();
    display(stogy);
}

void test6()
{
    std::cout << "\n Test 6 =============== \n";
    std::vector<int> vec{1, 2, 3, 4};
    display(vec);

    vec.clear(); // remove all elements
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8};
    display(vec);

    vec.erase(std::begin(vec), std::begin(vec) + 2);
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int>::iterator it = vec.begin();
    display(vec);
    // erase all even numbers
    while (it != vec.end())
    {
        if (*it % 2 == 0)
        {
            vec.erase(it);
        }
        else
        {
            it++;
        }
    }
    display(vec);
}

void test7()
{
    std::cout << "\n Test 7 =============== \n";
    std::vector<int> vec{1, 2, 3, 4};
    std::vector<int> vec2{5, 6, 7, 8};

    display(vec);
    display(vec2);

    vec.swap(vec2);
    std::cout << "\n After swap \n";

    display(vec);
    display(vec2);
}

void test8()
{
    std::cout << "\n Test 8 =============== \n";
    std::vector<int> vec{1, 2, 5, 7, 8, 11, 3, 4};

    display2(vec);
    std::sort(vec.begin(), vec.end());
    display2(vec);
}

void test9()
{
    std::cout << "\n Test 9 =============== \n";
    std::vector<int> vec{1, 2, 3, 4};
    std::vector<int> vec2{10, 20};

    display2(vec);
    display2(vec2);

    std::copy(vec.begin(), vec.end(), std::back_inserter(vec2));

    display2(vec);
    display2(vec2);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    vec2 = {10, 20};

    display2(vec);
    display2(vec2);

    auto it = vec.begin();
    // while(it!=vec.end()){
    //     if()
    // }
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(vec2), [](int x)
                 { return (x % 2 == 0); });

    display2(vec);
    display2(vec2);
}

void test10()
{
    std::cout << "\n Test 10 =============== \n";
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20, 30, 40, 50};
    std::vector<int> vec3;

    std::transform(vec.begin(), vec.end(), vec2.begin(), std::back_inserter(vec3), [](int x, int y)
                   { return x * y; });

    display(vec3);
}

void test11()
{
    std::cout << "\n Test 11 =============== \n";
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec2{100, 200, 300, 400};

    display(vec);
    display(vec2);
    std::cout << std::endl;

    auto it = std::find(vec.begin(), vec.end(), 5);

    if (it != vec.end())
    {
        std::cout << "inseting..." << std::endl;
        vec.insert(it, vec2.begin(), vec2.end());
    }
    else
    {
        std::cout << "Sory not found" << std::endl;
    }
    display(vec);
}

int main()
{
    test();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    return 0;
}