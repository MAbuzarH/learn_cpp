#include <iostream>
#include <queue>
#include <vector>
#include <list>

template <typename T>
void display(std::queue<T> s)
{
    std::cout << "[";
    while (!s.empty())
    {
        T element = s.front();
        s.pop();
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::queue<int> s;

    for (int i : {1, 2, 3, 4, 5})
    {
        s.push(i);
    }
    display(s);

    std::cout << "Front: : " << s.front() << std::endl;
    std::cout << "Back: : " << s.back() << std::endl;

    s.push(100);
    display(s);

    s.pop();
    s.pop();
    display(s);

    while (!s.empty())
        s.pop();
    display(s);

    std::cout << "size: " << s.size() << std::endl;

    s.push(10);
    s.push(100);
    s.push(1000);

    display(s);
    std::cout << "Front: : " << s.front() << std::endl;
    std::cout << "Back: : " << s.back() << std::endl;

    s.front() = 5;
    s.back() = 1000;
    display(s);

    std::cout << "Front: : " << s.front() << std::endl;
    std::cout << "Back: : " << s.back() << std::endl;
    std::cout << s.front() + 1;
    return 0;
}