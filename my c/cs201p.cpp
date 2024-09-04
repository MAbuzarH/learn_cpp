#include<iostream>
using namespace std;
int calculateGross(int sale){
	int amout = 700; // basic sealry
	float bounas = 0.09 * sale; //bounas
	bounas += amout;
	return bounas;  
}
int main(){
	int numItration = 3; // loop controle according to given data
	int salePrWeek; //total pay of on person in week
	int i; // loop controle
	float result = 0.0; // to store data coming from function
	float result1 = 0.0;
	float result2 = 0.0;
	float result3 = 0.0;
	float totalGrossSale = 0.0; // total gross sale this week
	int person1Sale = 5000;
	int person2Sale = 7000;
	int person3Sale = 9000;
	
	
	//by using loop
//	for (i=1; i<=numItration; i++){
//		cout<<"Enter Sale Of empoly  " << i <<endl;
//		cin>>salePrWeek;
//		result = calculateGross(salePrWeek) ;
//		cout <<"Sales Person "<< i << " gross earnings: " << result <<" PKR " << endl;
//		totalGrossSale += result;
//		 
//	} 


// by using given data of qustion

	result1 = calculateGross(person1Sale);
	result2 = calculateGross(person2Sale);
	result3 = calculateGross(person3Sale);
	cout <<"Sales Person "<< 1 << " gross earnings: " << result1  <<" PKR " << endl;
	cout <<"Sales Person "<< 2 << " gross earnings: " << result2  <<" PKR " << endl;
	cout <<"Sales Person "<< 3 << " gross earnings: " << result3  <<" PKR " << endl;
 	totalGrossSale =result1 + result2 + result3;
 
	cout<<"Total gross sale earning this week :" <<totalGrossSale <<" PKR ";
	return 0;
}
