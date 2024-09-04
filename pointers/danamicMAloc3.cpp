#include <iostream>
#include<string>

using namespace std;

int main()
{
//size_t size{0};
//int *temp_ptr = NULL;
//cout<< "how many int you want \n";
//cin>>size;
// temp_ptr =new int[size];
// cout<<temp_ptr;
// delete [] temp_ptr;
//// // // comparing the pointers
//
//string s1="Ali";
//string s2="Ali";
//string *ptr_1= &s1 ;
//string *ptr_2= &s2 ;
//string *ptr_3= &s1 ;
//
//cout<<(ptr_1 == ptr_2)<<endl; //false
//cout<<(ptr_1 == ptr_3)<<endl; //true
//
//cout<<(*ptr_1 == *ptr_2)<<endl; //false
//cout<<(*ptr_1 == *ptr_3)<<endl; //true
//-------------------------------//--//--//
int score []={11,12,13,14,-1};
int *score_ptr = score;

while(*score_ptr != -1){
	cout<<*score_ptr<<endl;
	score_ptr++;
}

return 0;
}
