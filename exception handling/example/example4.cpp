#include <iostream>

using namespace std;
class DivideByZeroException
{
};
class NegativeValueException
{
};

double calc_mpg(int miles, int gallon)
{
    if (gallon == 0)
        throw DivideByZeroException();
    if (miles < 0 || gallon < 0)
        throw NegativeValueException();
    return static_cast<double>(miles) / miles;
}
int main()
{
    int miles{};
    int gallon{};
    int miles_per_gallon{};

    cout << "Enter Miles: ";
    cin >> miles;
    cout << "Enter gallon: ";
    cin >> gallon;

    try
    {
        miles_per_gallon = calc_mpg(miles, gallon);
        cout << "Results: " << miles_per_gallon << endl;
    }
    catch (const DivideByZeroException &ex)
    {
        cout << "Error not divide by 0" << endl;
    }
    catch (const NegativeValueException &ex)
    {
        cout << "Error Negative value" << endl;
    }
    cout << " Bye " << endl;
    return 0;
}
