#include<iostream>

using namespace std;

int main(){
	// l values and there refrence
	int a = 10;
	cout<<"orignal: "<<a<<endl;
	int &l_refrence = a; // l value refrence
	l_refrence= 20; // now a changed;
	cout<<"after changing by l value refrence: "<<a<<endl;
//	&l_refrence = 20; //error // l value required as left oprend
    // r values and refrence
//    int && r_refrence = 200;
//    cout<<"r_refrence: "<<r_refrence<<endl;
	return 0;
}
