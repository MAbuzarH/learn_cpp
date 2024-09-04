#include<iostream>
using namespace std;
int reversedNumber(int number){
	int output = 0;
	while(number != 0 ){
	int remender = number % 10;
	output = output*10 + remender;
	number /= 10;	
	}
	return 	output;
}
int main(){
	
	int newn = 1234;
	int number =reversedNumber(newn);
	
	cout<<" out put "<<number;
	return 0;
}



