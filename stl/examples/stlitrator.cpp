#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <set>

int main()
{

    std::vector<int> vec{1, 2, 3, 4};
    std::vector<int>::iterator it1;

    it1 = vec.begin();
    std::cout << "printing vector using itratore" << std::endl;
    while (it1 != vec.end())
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }

    std::vector<int> vec2{1, 2, 3, 4};

    std::cout << "printing vector using reverce_itratore" << std::endl;
    for (auto it2 = vec2.rbegin(); it2 < vec2.rend(); it2++)
    {
        std::cout << *it2 << std::endl;
    }

    std::cout << "printing list using const_itratore" << std::endl;
    std::list<std::string> list1{"ali", "akam", "alam"};
    std::list<std::string>::const_iterator it3 = list1.cbegin();
    while (it3 != list1.cend())
    {
        std::cout << *it3 << std::endl;
        it3++;
    }

    std::cout << "printing map using const_itratore" << std::endl;
    std::map<std::string, std::string> map1{{"ali", "c++"}, {"asam", "PHP"}, {"noor", "java"}};
    auto it4 = map1.begin();
    while (it4 != map1.end())
    {
        std::cout << "{ " << it4->first << " " << it4->second << " }" << std::endl;
        it4++;
    }
    return 0;
}