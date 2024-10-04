#include <bits/stdc++.h>

using namespace std;

int main()
{

    int number = 15;
    int sumOfDevisors = 0;
    // for (int i = 1; i <= number; i++)
    // {

    // for (int j = 1; j <= sqrt(i) ; j++)
    // {
    //     // sumOfDevisors += ((i * number) / number);
    //     sumOfDevisors += ((j * i) / i);
    //     cout << sumOfDevisors;
    //     // if (i % j == 0)
    //     // {
    //     //     // cout << "Devisor are " << i << " " << j;
    //     //     sumOfDevisors += j;
    //     // }
    //     // cout << endl;
    // }
    // cout << endl;
    for (int d = 1; d <= number; d++)
    {
        // For each divisor d, add it to the sum for all multiples of d
        sumOfDevisors += d * (number / d);
    }
    // }
    cout << sumOfDevisors << endl;
    return 0;
}