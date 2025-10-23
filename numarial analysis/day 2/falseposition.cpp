#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x * x - 4 * x - 9;
}

void falsePosition(double (*fun)(double), double a, double b, double tol, int max_iter) {
    if (fun(a) * fun(b) >= 0) {
        cout << "Invalid interval: no sign change." << endl;
        return;
    }

    double c; // root approximation
    for (int i = 1; i <= max_iter; i++) {
        // Calculate intersection point (Regula Falsi formula)
        c = (a * fun(b) - b * fun(a)) / (fun(b) - fun(a));
        double fc = fun(c);

        cout << "Iteration " << i
             << ": a = " << a << ", b = " << b
             << ", c = " << c << ", f(c) = " << fc << endl;

        // Check convergence
        if (fabs(fc) < tol) {
            cout << "Root found: " << c << " after " << i << " iterations." << endl;
            return;
        }

        // Update interval
        if (fun(a) * fc < 0)
            b = c;
        else
            a = c;
    }

    cout << "Approximate root after " << max_iter << " iterations: " << c << endl;
}

int main() {
    falsePosition(f, 2, 3, 0.00001, 100);
    return 0;
}


// #include <iostream>
// #include <cmath>

// using namespace std;

// double f(double x)
// {
//   return x * x * x - 4 * x - 9;
// }

// void falsePosition(double (*fun)(double), double a, double b, double tol, int max_iter)
// {
//   if (fun(a) * fun(b) >= 0)
//   {
//     cout << "Invalid interval: no sign change." << endl;
//     return;
//   }
//   double c; // root approximation
//   for (int i = 1; i <= max_iter; i++)
//   {
//     // Calculate intersection point (Regula Falsi formula)
//     c = (a * fun(b) - b * fun(a)) / (fun(b) - fun(a));
//     double fc = fun(c);

//     cout << "Iteration " << i << ": a = " << a << ", b = " << b << ", c = " << c << ", f(c) = " << fc << endl;

//     if (fabs(fun(c)) < tol)
//     {
//       cout << "Root found: " << c << " after " << i << " iterations." << endl;
//       return;
//     }

//     if (fun(a) * fc < 0)
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
//   falsePosition(f, 2, 3, 0.00001, 100);
//   return 0;
// }