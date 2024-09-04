#include <stdio.h>  
int main(){
	//print 2 1 4 3 6 5 .... n
	int input;

	int i;
	printf("Enter a number");
	scanf("%i",&input);
	if(input%2!=0)
     input+=1;
	for(i=1; i<=input; i++){
		if(i%2==0){
//		result=i-1;
		printf("%i",i-1);	
		}
		else{
//		result=i+1;
		printf("%i",i+1);	
		}
	}


	return 0;
}
