#include<iostream>
using namespace std;
void reverce(char name[], int size)
{
//	for(int i=0; i<size; i++)
	name[size] = "fgh";
}
main(){
	char name[5];
	reverce(name,5);
//	cout<<"enter yur name \n";
//	cin>>name;
//		cout<< "name is \n";
	for(int i = 0; i < 5; i++){
	
		cout<< name[i];
	}
//		cout<< "\n reverce name is \n";
//		for(int j = 10; j < 0; j--){
//	
//		cout<< name[j];

//	}
	return 0;
} 
