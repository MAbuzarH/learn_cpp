#include<iostream>
using namespace std;
	void getInput(int sal[][2],int numImp){
		for(int i = 0; i < numImp; i++){
			cout<<"Enter the Gros sal of Impoly: "<<i<<endl;
			cin >> sal[i][0];
		}
	}
	void calcSalery(int sal[][2] , int numImp){
		for(int i = 0; i < numImp; i++){
			//netsal = grosssal-tax;
			if(sal[i][0] <= 5000){
				sal[i][1]=sal[i][0];
			}
			else{
				if(sal[i][0] <= 10000){
				sal[i][1]=sal[i][0] - 0.05* sal[i][0];
			}
			else{
				if(sal[i][0] <= 20000){
				sal[i][1]=sal[i][0] - 0.1* sal[i][0];
			}
			else{
			sal[i][1]=sal[i][0] - 0.15* sal[i][0];	
			}	
			}
			}
		}
	}
	void unluckyImp(int sal[][2], int lucky[], int numImp){
		int netsal,grossal,i;
		for(i = 0; i<numImp; i++){
			grossal = sal[i][0];
			netsal = sal[i][1];
			for(int j =0; j< numImp; j++){
				if(grossal > sal[j][0] && netsal < sal[j][i]){
					lucky[i] = 1;
				}
			}
		}
	}
	void displayOp(int sal[][2], int lucky[], int numImp){
		for(int i = 0; i < numImp; i++){
			if(lucky[i] == 1){
				cout<<"Empoly number: "<<i+1 << " is unluckey, Gross sal: " << sal[i][0] <<" Net sal: "<<sal[i][1]<<endl;
			}
		}
	}
int main(){
const int arraysize = 100;
int sal[arraysize][2];
int lucky[arraysize]={0};
int numImp;
cout<<"enter the nuber of impolies \n"<<endl;
cin>>numImp;
getInput(sal,numImp);
calcSalery(sal,numImp);
unluckyImp(sal,lucky,numImp);
displayOp(sal,lucky,numImp);

	return 0;
}
