#include <iostream>
#include <algorithm>

using namespace std;

class DivisorCalculator {
public:
  DivisorCalculator() {
    cout << "DivisorCalculator is created." << endl;
    cout << "UserInterface is created." << endl;
    cout << "This program is designed to exhibit the positive divisors of positive integers supplied by you. The program will repeatedly prompt you to enter a positive integer. Each time you enter a positive integer, the program will print all the divisors of your integer in a column and in descending order." << endl;
  }

  void calculateAndPrintDivisors(int number) {
    if (number <= 0) {
      cout << number << " is not a positive integer." << endl;
      cout << "Please enter a positive integer." << endl;
      return;
    }

    cout << "Divisors of " << number << " in descending order:" << endl;

    // Use an array to store divisors
    const int maxSize = 100; 
    int divisors[maxSize];
    int divisorCount = 0;

    // Find divisors
    for (int i = 1; i <= number; i++) {
      if (number % i == 0) {
        divisors[divisorCount++] = i;
      }
    }

    // Sort divisors in descending order
    sort(divisors, divisors + divisorCount, greater<int>());

    // Print divisors
    for (int i = 0; i < divisorCount; i++) {
      cout << divisors[i] << endl;
    }
  }
};

class UserInterface {
private:
  int calculatorCounter = 0;
public:
  UserInterface(DivisorCalculator& calculator) {
    char continueInput;

    while (true) {
      if (calculatorCounter > 0) {
        cout << endl << "Do you want to calculate divisors for a number (Y/N)? ";
        cin >> continueInput;
      } else {
        continueInput = 'y'; // Automatically start with 'y' for the first calculation
      }

      if (continueInput == 'y' || continueInput == 'Y') {
        cout << endl << "Please enter a positive integer to calculate its divisors: ";
        int number;
        cin >> number;
        calculator.calculateAndPrintDivisors(number);
        calculatorCounter++;
      } else if (continueInput == 'n' || continueInput == 'N') {
        break; // Break out of the loop if the input is 'N' or 'n'
      } else {
        cout << "Please respond with Y (or y) for yes and N (or n) for no" << endl;
       
      }
    }
  }


};

int main() {
  DivisorCalculator calculator;
  UserInterface ui(calculator);

  return 0;
}

