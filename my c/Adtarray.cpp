#include<iostream>
using namespace std;
struct Array{
	int *arr;
	int cap;//capisty
	int size;
};

void createArray(int size,int capisty,Array *arr){
	arr->cap = capisty;
	arr->size = size;
	arr->arr = new int [size];
}

void printArray(Array *arr){
	for(int i=0; i<= arr->size; i++){
		cout<<arr->arr[i]<<" ";
	}
	cout<<endl;
}

void setValues(Array *arr){
	int x;
	for(int i =0; i<= arr->size; i++){
		cout<<"enter value to set on index "<< i <<": ";
		cin>>x;
		arr->arr[i]= x;
	}
}

int main(int argc, char const *argv[]){
 Array arr;
 int capisty,size;
 cout<<"enter capisty and size \n";
 cin>>capisty>>size	;
 createArray(size,capisty,&arr);
 setValues(&arr);
 printArray(&arr);
 return 0;
}
