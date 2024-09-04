#include<iostream>
#include<stdio.h>
using namespace std;
int power(int num,int power){
	int ans = 1;
	for (int i = 1; i<=power; i++){
		ans *= num; 
	}
	return ans;
}
// circal area

int circleArea(int rad){
	int rad2= pawer(rad,rad)
}
int main(){
	int numm;
	int pw;
	int outp;
	cout<<"Enter number"<<endl;
	cin>>numm;
	cout<<"Enter power"<<endl;
	cin>>pw;
	outp= power(numm,pw);
	cout<<"out put"<<outp<<endl;
	 return 0;
}
