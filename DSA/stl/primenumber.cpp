#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 11;
    int count = 0;

    // divided by 0 error if we start loop from 0
    //  brotforce approch
    //  for (int i = 1; i <= num; i++)
    //  {
    //      if (num % i == 0)
    //      {
    //          count++;
    //      }
    //  }

    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
        if (i != num / i)
        {
            count++;
        }
    }

    if (count == 2)
    {
        cout << "prime number" << endl;
    }
    else
    {
        cout << "not prime" << endl;
    }
    return 0;
}