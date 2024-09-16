#include <iostream>
using namespace std;

int main()
{

    int miles;
    int gallon;
    double miles_per_gallon;
    cout << "Enter Miles: ";
    cin >> miles;
    cout << "Enter Gallons: ";
    cin >> gallon;
    // miles_per_gallon = miles / gallon;
    if (gallon != 0)
    {
        miles_per_gallon = static_cast<double>(miles) / gallon;

        cout << "Results: " << miles_per_gallon << endl;
    }
    else
    {
        cerr << "sory cant devide 0 \n";
    }

    cout << "bye \n";
    return 0;
}