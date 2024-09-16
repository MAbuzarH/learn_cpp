#include <iostream>
#include <vector>

template <typename T>
class Items
{
private:
    std::string Name;
    T Value;

public:
    Items(std::string name, T value) : Name(name), Value(value)
    {
    }
    std::string getName() const { return Name; }
    T getvalue() const { return Value; }
};

template <typename T1, typename T2>
struct myPair
{
    T1 first;
    T2 second;
};
int main()
{

    Items<int> item1{"frank", 100};
    std::cout << item1.getName() << " " << item1.getvalue() << std::endl;

    Items<std::string> item2{"frank", "Boos"};
    std::cout << item2.getName() << " " << item2.getvalue() << std::endl;

    Items<Items<std::string>> item3{"jorg", {"c++", "professoe"}};
    std::cout << item3.getName() << " " << item3.getvalue().getName() << " " << item3.getvalue().getvalue() << std::endl;

    std::vector<Items<double>> items;
    items.push_back(Items<double>{"Ali", 20.10});
    items.push_back(Items<double>{"jon", 25.20});
    items.push_back(Items<double>{"jak", 30.30});

    for (auto &item : items)
    {
        std::cout << item.getName() << " " << item.getvalue() << std::endl;
    }

    myPair<std::string, int> p1{"qasam", 200};
    myPair<int, double> p2{209, 30.30};

    std::cout << p1.first << " " << p1.second << std::endl;
    std::cout << p2.first << " " << p2.second << std::endl;
    return 0;
}