#include <iostream>
using namespace std;

class LowerTriagular
{
private:
    int *A;
    int n;

public:
    LowerTriagular(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    void set(int i, int j, int x)
    {
        if (i >= j)
        {
            A[i * (i - 1) / 2 + j - 1] = x;
        }
    }
    void get(int i, int j)
    {
        if (i >= j)
        {
            cout << A[i * (i - 1) / 2 + j - 1] << "\n";
        }
        else
            cout << "0 \n";
    }
    void dis()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; i <= n; j++)
            {
                if (i >= j)
                {
                    cout << A[i * (i - 1) / 2 + j - 1] << " ";
                }
                else
                    cout << "0";
            }
        }
    }
    ~LowerTriagular()
    {
        delete[] A;
    }
};
int main()
{

    return 0;
}