#include <iostream>
using namespace std;

// using refrence
//  void Increment(int& value){
//      value++;
//  }
//  using pointer
void Increment(int *value)
{
    (*value)++;
}
int main()
{
    int a = 8;

    // int &ref = a;
    // ref = 20;
    // cout << a;
    // Increment(a);
    // cout<<"a = "<<a<<endl;
    Increment(&a);
    cout << "a = " << a << endl;
}