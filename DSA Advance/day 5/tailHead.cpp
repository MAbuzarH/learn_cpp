#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void fun(int n){
    if(n>0){
    printf("n = %d\n",n);
    fun(n-1);
    }
}
int main(){
int x = 7;
fun(x);
    return 0;
}