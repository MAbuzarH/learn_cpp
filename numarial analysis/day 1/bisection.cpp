// #include <iostream>
// #include<cmath>
// using namespace std;

// // tol upto 3 decimal place tolerance
// // max_iter loop end


// // Bisection Method

  
//   if ((func(a) * func(b)) > 0)
//   {
//     printf("Invalid interval: no sign change \n");
//     return;
//   }
//   for (int i = 0; i <= max_iter; i++)
//   {
//     c = (a + b) / 2.0;

//     cout << "Iteration " << i << ": a=" << a << ", b=" << b 
//     << ", c=" << c << ", f(c)=" << func(c) << endl;

//     if (func(c) == 0 || fabs(b - a) / 2 < tol)
//     {
//       printf("root found: %d \n", c);
//       return;
//     }

//     if ((func(a) * func(c)) < 0)
//     {
//       b = c;
//     }
//     else
//     {
//       a = c;
//     }
//   }

//   cout << "Approximate root after " << max_iter << " iterations: " << c << endl;
// }
// int main()
// {
//   bisection(f, 2, 3, 0.0001, 100);
//   return 0;
// }

#include <iostream>
#include <cmath> // for fabs() finding absolute value
using namespace std;

// Function for which we want to find the root
double f(double x)
{
    return x * x * x - 4 * x - 9;
}

// Bisection Method
void bisection(double (*func)(double), double a, double b, double tol, int max_iter)
{
    double c;

    // Step 1: Check if the interval is valid
    if ((func(a) * func(b)) > 0)
    {
        cout << "Invalid interval: no sign change." << endl;
        return;
    }

    // Step 2: Iteration
    for (int i = 1; i <= max_iter; i++)
    {
        c = (a + b) / 2.0;

        // Display current iteration
        cout << "Iteration " << i << ": a=" << a << ", b=" << b << ", c=" << c << ", f(c)=" << func(c) << endl;

        // Step 3: Check for root or tolerance
        if (func(c) == 0 || fabs(b - a) / 2 < tol)
        {
            cout << "Root found: " << c << endl;
            return;
        }

        // Step 4: Update interval
        if ((func(a) * func(c)) < 0)
            b = c;
        else
            a = c;
    }

    cout << "Approximate root after " << max_iter << " iterations: " << c << endl;
}

// Main Function
int main()
{
    bisection(f, 2, 3, 0.0001, 100);
    return 0;
}
