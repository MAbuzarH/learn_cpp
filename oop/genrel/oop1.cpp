#include<iostream>
#include<string>
//#pragma once
using namespace std;

class Bank{
	public:
	int blance;
	string name;
//	Bank(int bal,string n){
//		blance =bal;
//		name = n;
//	}
	void display(){
		cout<<"name: "<<name<<endl;
		cout<<"balannce: "<<blance<<endl;
		cout<<"-----------\n";
	}
};

int main(){
	
	Bank p1;
	p1.name="ali";
	p1.blance = 2000;
	p1.display();
	Bank *p2 = new Bank;
	p2->name="Abuzar";
	p2->blance = 20000;
	p2->display();
	
	return 0;
}
