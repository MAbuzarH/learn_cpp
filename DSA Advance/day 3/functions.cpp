#include<iostream>
using namespace std;
int sum(int a,int b){//prototype or signature of a function
//here a and b are formal parameters
//defenation of a function 
int c = a+b;
return c;
}
int main(){
int a =10;
int b =20;
int c =sum(a,b ); // here a and b are actual parameters;

    return 0;
}