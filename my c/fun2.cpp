#include<iostream>
#include<stdio.h>
using namespace std;
#include <iostream>
using namespace std;
void swip(int *a, int *b){
int bs;
bs= *a;
*a = *b;
*b = bs;

}
int main() {
int a= 5;
int b=10;
swip(&a,&b);
cout<<" a is"<<a<<endl;
cout<<" b is"<<b<<endl;
}

