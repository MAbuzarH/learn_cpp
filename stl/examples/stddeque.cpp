#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

template <typename T>
void display(const std::deque<T> &d)
{
    std::cout << "[";
    for (const auto &element : d)
    {
        std::cout << element << " ";
    }
    std::cout << "]\n";
}

void test1()
{
    std::cout << "\n Test 1 =============== \n";
    std::deque<int> deq1{
        1,
        2,
        3,
        4,
    };
    display(deq1);

    deq1 = {10, 20, 20, 40, 50};
    display(deq1);

    std::deque<int> deq2(10, 100);
    display(deq2);

    deq1[0] = 10;
    deq2.at(0) = 900;

    display(deq1);
    display(deq2);
}

void test2()
{
    std::cout << "\n Test 2 =============== \n";
    std::deque<int> deq1{
        0,
        0,
        0,

    };
    display(deq1);
    deq1.push_back(2);
    deq1.push_front(1);
    display(deq1);

    std::cout << "Front: " << deq1.front() << std::endl;
    std::cout << "back: " << deq1.back() << std::endl;
    std::cout << "Size: " << deq1.size() << std::endl;

    deq1.pop_back();
    deq1.pop_front();
    display(deq1);
}

void test3()
{
    std::cout << "\n Test 3 =============== \n";
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> deq1;

    for (auto v : vec)
    {
        if (v % 2 == 0)
        {
            deq1.push_back(v);
        }
        else
        {
            deq1.push_front(v);
        }
    }
    display(deq1);
}

void test4()
{
    std::cout << "\n Test 4 =============== \n";
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> deq1;
    std::cout << "\n push back \n";
    for (auto v : vec)
    {
        deq1.push_back(v);
    }

    display(deq1);
    deq1.clear();
    std::cout << "\n push front \n";
    for (auto v : vec)
    {
        deq1.push_front(v);
    }
    display(deq1);
}

void test5()
{
    std::cout << "\n Test 5 =============== \n";
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> deq1;
    std::cout << "\n push back \n";
    std::copy(vec.begin(), vec.end(), std::back_inserter(deq1));

    display(deq1);
    deq1.clear();
    std::cout << "\n push front \n";
    std::copy(vec.begin(), vec.end(), std::front_inserter(deq1));
    display(deq1);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}