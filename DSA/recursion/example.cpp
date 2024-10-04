#include <bits/stdc++.h>
using namespace std;
int counter = 0;
// void fun()
// {
//     if (counter == 4)
//     {
//      return;
//     }
//     cout<<counter;
//     counter++;
//     fun();
// }
void printNos(int i, int N)
{
    // Your code here

    if (i > N)
    {
        return;
    }

    cout << i << " ";

    printNos(i + 1,N);
}

int main()
{
    printNos(1, 10);
    //   fun();
    return 0;
}