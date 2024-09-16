#include <iostream>
#include <string>

using namespace std;

double calculate_mpg(int miles, int gallons)
{
    if (gallons == 0)
        throw 0;
    if (miles < 0 || gallons < 0)
        throw string{"Nagitive value error"};
    return static_cast<double>(miles) / gallons;
}

int main()
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};
    cout << "Enter miles: ";
    cin >> miles;
    cout << "Enter gallons: ";
    cin >> gallons;

    try
    {
        miles_per_gallon = calculate_mpg(miles, gallons);
        cout << "Results: " << miles_per_gallon;
    }
    catch (int &ex)
    {
        cout << "Error: Try to divid by " << ex << endl;
    }
    catch (string &ex)
    {
        cout << ex << endl;
    }

    cout << " \n Bye 😀 \n";

    return 0;
}