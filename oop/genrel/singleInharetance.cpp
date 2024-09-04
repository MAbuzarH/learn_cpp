#include <iostream>
using namespace std;
class Parent{
public:
Parent(){
    cout<<"in parent"<<endl;
}
};
class Child:public Parent {
    public:
  Child(){
    cout<<"in Child"<<endl;
} 
};
int main(){
Child c1;
    return 0;
}