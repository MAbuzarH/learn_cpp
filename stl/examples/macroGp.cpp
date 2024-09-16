#include <iostream>

using namespace std;

// we use this
#define Max(a, b) (a > b ? a : b)
#define Square(a) (a * a)

int main()
{

    // what is a mocro?
    // preprosessor dirrective
    // not type define
    // eg #define PI 3.1415
    // we can use them by this example
    // int a {100};
    // int b {200};
    // double c {20.20};
    // double d {20.90};
    cout << Max(10, 30) << endl;
    cout << Max(10.10, 10.90) << endl;
    cout << Square(5);
    int result = 100 / Square(5); // this may not give correct result
    cout << result << endl;
    return 0;
}