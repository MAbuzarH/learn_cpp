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
class grandChild:public Child {
    public:
  grandChild(){
    cout<<"in grand Child"<<endl;
} 
};
int main(){
grandChild c1;
    return 0;
}