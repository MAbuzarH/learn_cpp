#include<iostream>
#include<string>
#include<vector>
using namespace std;

//int *largest_int (int *a,int *b){
//	if(*a > *b){
//		return a;
//	}
//	else
//	return b;
//}

int *creat_array(size_t size,int init_value = 0){
	int *new_storage = NULL;
	new_storage = new int[size];
	for(int i=0; i<size; i++){
		*(new_storage + i) = init_value;
 
	}
	return new_storage;
}

//void display(size_t size,const int *const arr){
//	for(int i =0; i<size; i++){
//		cout<<arr[i]<< " ";
//	}
//	cout<<endl;
//}


void display(size_t size,int *arr){
	for(int i =0; i<size; i++){
		cout<<arr[i]<< " ";
	}
	cout<<endl;
}


int main(){
	
	
//int a =1000;
//int b =200;
//
//int *large = largest_int(&a,&b);
//cout<<"big one: "<< *large<<endl;
 
 size_t size;
 int initalize_value;
 int *arr = NULL;
 cout<<"how big you want array : \n";
 cin>>size;
  cout<<"with which you want to initilaze : \n";
 cin>>initalize_value;
 arr= creat_array(size,initalize_value);
	display(size,arr);
	delete [] arr;
	return 0;
}
