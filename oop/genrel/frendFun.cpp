#include<iostream>
using namespace std;

class A{
    int x;
    public:
    A(int b){
        x = b;
    }
   friend void print(A &obj);
};

void print(A &obj){
    cout<<obj.x<<endl; 
}

int main(){
    A a(6);
    print(a);
    return 0;
}