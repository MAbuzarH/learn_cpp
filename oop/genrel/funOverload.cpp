#include <iostream>
using namespace std;

class Sum{
    public:
    void add(int a,int b){
        cout<<"sum is a+b="<<a+b<<endl;
    }
     void add(int a,int b,int c){
        cout<<"sum is a+b+c="<<a+b+c<<endl;
    }
};

int main(){

   Sum s1;
   s1.add(2,3);
   s1.add(2,3,5);

    return 0;
}