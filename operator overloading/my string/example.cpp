#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class A{
	private:
	string my_string;
    int number;
	public:
	  A(){
	  }	
	  A(string s,int num):my_string{s},number{num}{
	  }
	  string get_string(){ return my_string;
	  }	
	  int get_num(){ return number;
	  }	
	  void set_string (string s){
	  	my_string = s;
	  }
	  void set_num (int n){
		number = n;
	  }
	  void display(){
	  	cout<<my_string <<endl;
	  }
	  A operator+(const A &rhs){
	  	A temp;
	  	temp.my_string = my_string + rhs.my_string;
		temp.number = number + rhs.number;
	  	return temp;
	  }
	
};
int main(){
	A s1("hi,",10);
	A s2("Ali",20);
	A s3 = s1 + s2;
	s1.display();
	s3.display();	
	return 0;
}
