#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>

void display(std::array<int, 5> &arr)
{
    std::cout << "[";
    for (const auto &i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << " ] \n";
}

void test1()
{
    std::cout << "Test 1======================= \n";
    std::array<int, 5> arr1{1, 2, 3, 4, 5};
    std::array<int, 5> arr2;

    display(arr1);
    display(arr2);

    arr2 = {10, 20, 30, 40, 50};

    display(arr1);
    display(arr2);

    std::cout << "The front of arr2 " << arr2.front() << std::endl;
    std::cout << "The front of arr2 " << arr2.back() << std::endl;

    arr1[0] = 1000;
    arr1.at(2) = 2000;

    display(arr1);
    display(arr2);
}

void test2()
{
    std::cout << "Test 2======================= \n";
    std::array<int, 5> arr1{1, 2, 3, 4, 5};
    std::array<int, 5> arr2;

    arr2.fill(1);
    display(arr1);
    display(arr2);

    arr1.swap(arr2);

    display(arr1);
    display(arr2);
}

void test3()
{
    std::cout << "Test 3 ============== \n";
    std::array<int, 5> arr{1, 2, 3, 4, 5};

    int *ptr = arr.data();

    std::cout << ptr << std::endl;
    *ptr = 1000;
    display(arr);
}

void test4()
{
    std::cout << "Test 4 ============== \n";
    std::array<int, 5> arr{1, 3, 4, 2, 5};
    std::sort(arr.begin(), arr.end());

    display(arr);
}

void test5()
{
    std::cout << "Test 5 ============== \n";
    std::array<int, 5> arr{1, 2, 3, 4, 5};
    std::array<int, 5>::iterator max_num = std::max_element(arr.begin(), arr.end());
    std::array<int, 5>::iterator min_num = std::min_element(arr.begin(), arr.end());

    display(arr);
    std::cout << "The max number " << *max_num << " and the min number " << *min_num << std::endl;
}

void test6()
{
    std::cout << "Test 7 =============" << std::endl;
    std::array<int, 5> arr{1, 2, 3, 3, 4};

    std::array<int, 5>::iterator it = std::adjacent_find(arr.begin(), arr.end());
    if (it == arr.end())
    {
        std::cout << "No adjacent found" << std::endl;
    }
    else
    {
        std::cout << "adjacent found" << *it << " times " << std::endl;
    }
}

void test7()
{
    std::cout << "Test 7 =============" << std::endl;
    std::array<int, 5> arr{1, 2, 3, 3, 4};

    int sum = std::accumulate(arr.begin(), arr.end(), 0);
    std::cout << " the sum is " << sum << std::endl;
}

void test8()
{
    std::cout << "Test 8 =============" << std::endl;
    std::array<int, 10> arr{1, 2, 3, 3, 4, 5, 6, 3, 3};
    int num = std::count(arr.begin(), arr.end(), 3);

    std::cout << "was found " << num << " times " << std::endl;
}

void test9()
{
    std::cout << "Test 9 =============" << std::endl;
    std::array<int, 10> arr{1, 2, 30, 40, 50, 60, 200, 203, 10};
    int num = std::count_if(arr.begin(), arr.end(), [](int x)
                            { return x > 10 && x < 200; });

    std::cout << "was found " << num << " times " << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    return 0;
}