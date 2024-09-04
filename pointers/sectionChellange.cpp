#include<iostream>

using namespace std;

int *apply_all(int *arr1,size_t size1,int *arr2,size_t size2){
	
	size_t new_Size =  size1 * size2;
	int k = 0;
	int *new_arr =NULL; 
	new_arr =new int[new_Size];
	                  
	for(int i = 0; i < size2; i++){
	            
		for(int j=0; j< size1; j++ ){   
		new_arr[k] = arr2[i] *  arr1[j];
		k++;
//		cout<< arr2[i] *  arr1[j] <<" ";
//      cout<<i <<" "<< j <<" : ";

		}
//		cout<<endl;
		
	}
	
	return new_arr;
}
void disply(int *arr, size_t size){
	for(int i =0; i < size; i++ ){
		cout<<arr[i] <<" ";
	}
	cout<<endl;
}

int main(){
	int *new_arr = NULL; 
	int arr1 [] ={1,2,3,4,5,6};
	int arr2 [] ={10,20,30};
	
	
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    
    size_t new_Size =  size1 * size2;
    
    new_arr = apply_all(arr1,size1,arr2,size2);
    
    cout<<"array 1: ";
    disply(arr1,size1); 
    cout<<"array 2: ";
    disply(arr2,size2); 
	disply(new_arr,new_Size);  
//	cout <<size1<<" " <<size2;
	delete [] new_arr;
	return 0;
}
