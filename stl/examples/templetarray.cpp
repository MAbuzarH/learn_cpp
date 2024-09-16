#include <iostream>
#include <vector>

template <typename T, int N>
class Array
{
    int size{N}; // it is only to show
    T valuse[N];

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr)
    {
        os << "[";
        for (const auto &i : arr.valuse)
        {
            os << i << " ";
        }
        os << "] \n";
        return os;
    }

public:
    Array() = default;
    Array(T init_value)
    {
        fill(init_value);
    }
    void fill(T val)
    {
        for (auto &item : valuse)
        {
            item = val;
        }
    }
    int get_size() const
    {
        return size;
    }
    // over loading [] opetrator
    T &operator[](int index)
    {
        return valuse[index];
    }
};

int main()
{

    Array<int, 5> num;
    std::cout << "The size of num is " << num.get_size() << std::endl;
    // std::cout << num << std::endl;

    num.fill(0);
    std::cout << num << std::endl;

    num.fill(1000);
    std::cout << num << std::endl;

    num[0] = 200;
    num[1] = 6000;
    std::cout << num << std::endl;

    Array<std::string, 10> strings{"hello"};
    std::cout << strings  << std::endl;
    return 0;
}