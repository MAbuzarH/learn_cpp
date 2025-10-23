#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
    return x * x * x - 4 * x - 9; // f(x) = x³ - 4x - 9
}

double fdx(double x)
{
    return 3 * x * x - 4;  // f'(x) = 3x² - 4
}

void newtonRaphson(double (*fun)(double), double (*fund)(double), double x0, double tol, int max_iter)
{
    for (int i = 1; i <= max_iter; i++)
    {
        double fx = fun(x0);
        double dfx = fund(x0);

        if (fabs(dfx) < 1e-9)
        {
            cout << "Error: derivative too small at iteration " << i << endl;
            return;
        }

        double x1 = x0 - fx / dfx; // Newton-Raphson formula

        cout << "Iteration " << i << ": x = " << x0
             << ", f(x) = " << fx
             << ", next x = " << x1 << endl;

        if (fabs(x1 - x0) < tol)//If two consecutive guesses are very close, we assume we’ve reached the root. eg tol =0.0001 so x0 - x1 = 0.0001 
        {
            cout << "\nRoot found: " << x1 << " after " << i << " iterations." << endl;
            return;
        }

        x0 = x1;  // prepare for next iteration
    }

    cout << "\nApproximate root after " << max_iter << " iterations: " << x0 << endl;
}

int main()
{
    newtonRaphson(f, fdx, 2, 0.0001, 100);
    return 0;
}


// #include <iostream>
// #include <cmath>

// using namespace std;

// double f(double x)
// {
//   return x * x * x - 4 * x - 9;
// }
// double fdx(double x)
// {
//   return 3 * x * x - 4;
// }

// void newtonRaphson(double (*fun)(double), double (*fund)(double), double x0, double tol, int max_iter)
// {
//   for (int i = 1; i <= max_iter; i++)
//   {
//     double fx = fun(x0);
//     double dfx = fund(x0); // derivative  function
//     if (fabs(dfx) < 1e-9)  // 1e-9 is very small value
//     {
//       cout << "Error: derivative too small, division by zero risk.\n";
//     }
//     double x1 = x0 - fx / dfx;

//     cout << "Iteration " << i << ": x = " << x0 << ", f(x) = " << fx << ", next x = " << x1 << endl;
//     if (fabs(x1 - x0) < tol)
//     {
//       cout << "\nRoot found: " << x1 << " after " << i << " iterations." << endl;
//       return;
//     }
//     // prepare for next itreation
//     x0 = x1;
//     cout << "Iteration " << i << ": x = " << x0 << ", f(x) = " << fx << endl;
//   }
// }
// int main()
// {
//   newtonRaphson(f, fdx, 2, 0.0001, 100);

//   return 0;
// }