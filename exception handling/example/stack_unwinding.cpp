// function unbinding
#include <iostream>
#include <string>

using namespace std;

void fun_a();
void fun_b();
void fun_c();

void fun_a()
{
    cout << "starting fun a" << endl;
    try
    {
        fun_b();
    }
    catch (int &exp)
    {
        cout << "error: caught in a" << endl;
    }
    cout << "end fun a" << endl;
}

void fun_b()
{
    cout << "starting fun b" << endl;
    fun_c();
    cout << "end fun b" << endl;
}

void fun_c()
{
    cout << "starting fun c" << endl;
    throw 100;
    cout << "end fun c" << endl;
}

int main()
{
    cout << "Stat main" << endl;
    try
    {
        fun_a();
    }
    catch (int &ex)
    {
        cerr << "Error: Catched \n";
    }

    cout << "End main" << endl;

    return 0;
}