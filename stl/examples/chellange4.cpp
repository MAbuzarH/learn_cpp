#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cctype>
#include <iomanip>

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

bool is_palindrome(const std::string &str)
{
    std::queue<char> queue;
    std::stack<char> sta;
    for (auto &s : str)
    {
        /* my logic
        if (!(isspace(s)) && !(ispunct(s)))
        {
            char a = toupper(s);
            deq.push_back(a);
        }
        */
        if (isalpha(s))
        {
            queue.push(toupper(s));
        }
    }

    /* my logic
    auto it = deq.begin();

    while (it != deq.end())
    {
        if ((deq.front() == deq.back()) && deq.size() == 1)
        {
            return true;
        }
        else if (deq.front() == deq.back())
        {
            deq.pop_back();
            deq.pop_front();
        };
        if (deq.size() == 0 || deq.size() == 1)
        {
            return true;
        }
        it++;
    }

    return false;
    */
    while (queue.size() > 1)
    {
        auto c1 = queue.front();
        auto c2 = sta.top();
        queue.pop();
        sta.pop();
        if (c1 != c2)
            return false;
    }

    return true;
}

main()
{
    std::vector<std::string> vector{"a", "aba", "abc", "A teota is a , teota", "b", "abcd ea"};
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto &v : vector)
    {
        std::cout << std::setw(8) << std::left << is_palindrome(v) << v << std::endl;
    }
    std::cout << std::endl;

    return 0;
}