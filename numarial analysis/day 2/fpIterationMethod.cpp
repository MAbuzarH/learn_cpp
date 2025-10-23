#include <iostream>
#include <cmath>


using namespace std;


double g(double x)
{
  // The expression is: (9 + 4x)^(1/3)
  double base = 9.0 + 4.0 * x;
  double exponent = 1.0 / 3.0;

  // Use pow(base, exponent) to calculate the result
  return pow(base, exponent);

  //return pow(9.0 + 4.0 * x, 1.0 / 3.0);

}

void fixedPointItreationMethod(double (*fun)(double), double x0, double tol, int max_iter)
{
  for (int i = 1; i <= max_iter; i++)
  {
    double x1 = fun(x0);
    double diff = fabs(x1 - x0);
    cout << "Iter " << i << ": x0 = " << x0 << "\t x1 = " << x1 << "\t diff = " << diff << endl;

    if (diff < tol)
    {
      cout << "\nConverged after " << i << " iterations. Root ≈ " << x1 << endl;
      return;
    }
    else
    {
      x0 = x1;
    }
  }
  cout << "\nDid not converge in " << max_iter << " iterations. Approximate root ≈ " << x0 << endl;
}
int main()
{
  fixedPointItreationMethod(g,2,0.0001,100);
}