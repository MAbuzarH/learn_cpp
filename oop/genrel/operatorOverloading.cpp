#include <iostream>
using namespace std;

class Complex
{
public:
    int real;
    int imag;
    Complex(int x, int y)  {
        real =x, imag = y;
    };
    Complex()  {
        real =0, imag = 0;
    };

    Complex operator+(Complex &c)
    {
        Complex ans;
        ans.real = real + c.real;
        ans.imag = imag + c.imag;
        return ans;
    }
    void display(){
        cout<<"real number: "<<real<<endl;
       cout <<" imag number: "<<imag<<endl;
    }
};

int main(){
Complex c1(1,3);
Complex c2(9,3);
Complex c3;
c3 = c1+c2;

c3.display();
return 0;
}