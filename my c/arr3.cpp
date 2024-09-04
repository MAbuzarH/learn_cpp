#include<iostream>
using namespace std;
int main(){
	int rows = 3;
	int col  = 3;
  int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
//	for(int i = 0 ; i <= rows; i++ ){
//		for(int j=0; j <= col; j++){
//			arr[i][j] = j;
//		}
//		
//	}
int temp;
cout<<"orignal array \n";
		for(int k = 0 ; k < rows; k++ ){
		for(int l=0;  l< col; l++){
		cout<<arr[k][l];
		}
		cout<<endl;
	}
		for(int k = 0 ; k < rows; k++ ){
		for(int l=k;  l< col; l++){
		temp = arr[k][l];
//		cout<<temp<<endl;
		 arr[k][l] =  arr[l][k];
		  arr[l][k] = temp;
//		  	cout<<arr[k][l];
		}
		cout<<endl;
	}
	cout<<" array after swip\n";
		for(int k = 0 ; k < rows; k++ ){
		for(int l=0;  l< col; l++){
		cout<<arr[k][l];
		}
		cout<<endl;
	}
	return 0;
}
