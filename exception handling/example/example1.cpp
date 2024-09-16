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
    try
    {
        if (gallon == 0)
            throw 0;

        miles_per_gallon = static_cast<double>(miles) / gallon;

        cout << "Results: " << miles_per_gallon << endl;
    }
    catch (int &ex)
    {
        cout << "Error: Sory cant devide by:  " << ex << endl;
    }
    cout << "bye \n";
    return 0;
}