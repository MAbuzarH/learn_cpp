#include <iostream>
#include <map>
#include <set>

// #include<algorithm>

void display(const std::map<std::string, std::set<int>> &m)
{
    std::cout << " [";
    for (const auto &ele : m)
    {

        std::cout << ele.first << ": [";
        for (const auto &sec_ele : ele.second)
        {
            std::cout << sec_ele << " ";
        }
        std::cout << "] ";
    }
    std::cout << "] \n";
}

template <typename T1, typename T2>
void display(const std::map<T1, T2> &m)
{
    std::cout << "[";
    for (const auto &ele : m)
    {
        std::cout << ele.first << ":" << ele.second << " ";
    }
    std::cout << "]" << std::endl;
}

void test1()
{
    // maps
    std::cout << "Test 1===============\n";
    std::map<std::string, int> m{
        {"larry", 3},
        {"curly", 2},
        {"Moe", 1},

    };

    display(m);

    m.insert(std::make_pair("neno", 4));
    display(m);

    m.insert(std::pair<std::string, int>("joe", 4));
    display(m);

    m["frank"] = 18;
    display(m);
    m["frank"] += 10;
    display(m);

    m.erase("frank");

    std::cout << "count for frank " << m.count("frank") << std::endl;
    std::cout << "count for frank " << m.count("joe") << std::endl;

    auto it = m.find("joe");

    if (it != m.end())
    {
        std::cout << "Founded " << std::endl;
    }

    m.clear();
    display(m);
}

void test2()
{
    // maps
    std::cout << "Test 2===============\n";
    std::map<std::string, std::set<int>> grades{
        {"larry", {10, 20}},
        {"curly", {20, 45, 90}},
        {"Moe", {20, 50, 90}},

    };
    display(grades);
    grades["larry"].insert(45);

    std::map<std::string, std::set<int>>::iterator it = grades.find("curly");

    if (it != grades.end())
    {
        it->second.insert(100);
    }
    display(grades);
}

int main()
{
    test1();
    test2();
    return 0;
}
