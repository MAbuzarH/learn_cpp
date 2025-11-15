#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
  return (x * x - 4);
}
void secantMethod(double (*fun)(double), double x0, double x1, double tol, int max_iter)
{
  double x2;
  for (int i = 1; i < max_iter; i++)
  {
    double f0 = fun(x0);
    double f1 = fun(x1);

    if (fabs(f1 - f0) < 1e-12)
    {
      cout << "Error: division by zero";
      return;
    }
    x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
    cout << "Iter " << i
         << ": x0 = " << x0
         << ", x1 = " << x1
         << ", x2 = " << x2
         << ", f(x2) = " << fun(x2) << endl;
    if (fabs(x2 - x1) < tol)
    {
      cout << "Root found at " << x2 << endl;
      return;
    }

    x0 = x1;
    x1 = x2;
  }
  cout << "Approximate root: " << x2 << endl;
}

int main()
{
  secantMethod(f, 1, 3, 0.0001, 100);
  return 0;
}
