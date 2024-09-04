#include <iostream>
using namespace std;
class Parent{
public:
int x;
private:
int y;
protected:
int z;


};
class Child:public Parent {
    // x is public, 
    //y is not accessible
    //z is protected
};
class Child2: private Parent{
    // x is private, 
    //y is not accessible
    //z is private
};
class Child3: protected Parent{
    // x is protected, 
    //y is not accessible
    //z is protected
};

int main(){

    return 0;
}