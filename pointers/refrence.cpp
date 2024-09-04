#include<iostream>
#include<string>
#include<vector>
using namespace std;

void display(int &array, int size){
for(int i = 0; i < size; i++){
	cout<<*(&array+i)<<" ";
}
	
}

int main(){
//	int num = 100;
//	int &ref = num;
//	cout<<num<<endl;
//	cout<<ref<<endl;
//num=200;
//	cout<<num<<endl;
//	cout<<ref<<endl;
//ref =99; 
//		cout<<num<<endl;
//	cout<<ref<<endl;

//vector<string> s ;
//s.push_back("ali");
//s.push_back("ama");
//s.push_back("ani");
// vector<string>  &rs = s;
//for(int i = 0; i<=2; i++){
//	rs[i]="funny";
//}
//for(int i = 0; i<=2; i++){
//   cout<<rs[i]<<endl;
//}

int arr [] = {1 ,2, 3, 4, -1};
int size = sizeof(arr) / sizeof(arr[0]);  
display(arr[0],size);

    return 0;
}
