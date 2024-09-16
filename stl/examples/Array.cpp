#include <iostream>
#include <vector>
template <typename T, int SIZE>
class Array
{
private:
    int size{SIZE};
    T Values[SIZE]; // values is an array of size elements

    friend std::ostream &operator<<(std::ostream &os, const Array<T, SIZE> &arr)
    {
        os << "[ ";
        for (const auto &value : arr.Values)
        {
            os << value << " ";
        }
        os << "] \n";
        return os;
    }

public:
    // default constructor
    Array() = default;
    // parameterised constructor
    Array(T value)
    {
        fill(value);
    }

    void fill(T value)
    {
        for (auto &val : Values)
        {
            val = value;
        }
    }

    int get_length() const { return size; }

    int &operator[](int index)
    {
        return Values[index];
    }
};
int main()
{

    Array<std::string, 5> arr{"hi"};

    std::cout << arr.get_length() << std::endl;
    std::cout << arr << std::endl;

    return 0;
}