#include <iostream>
#include <string>
using namespace std;

// Function to convert string to unsigned integer
unsigned int convertToUnsignedInt(const std::string& barcode) {
   unsigned int number;
   for(int i=0; i<barcode.size(); i++){
   if(barcode[i]>='0' && barcode[i]<='9'){
   	number=number*10+barcode[i]-'0';
   }
   	else{
   		continue;
	   }	
	
   }
 
   return number;
}

// Function to perform division, multiplication, and bitwise AND operations
unsigned int performOperations(unsigned int num, unsigned int& divisionResult, unsigned int& multiplicationResult) {
    divisionResult = num / 2;
    multiplicationResult = num * 2;
    return multiplicationResult & divisionResult;
}

// Function to perform right shift bitwise operation
unsigned int performRightShift(unsigned int num) {
	 
    return num >> 1;
}

// Function to perform left shift bitwise operation
unsigned int performLeftShift(unsigned int num) {

    return num << 1;
   
}

int main() {
    std::string barcode = "1234567";
    cout<<"Orignal barcode: "<<barcode<<endl;
    unsigned int num = convertToUnsignedInt(barcode);
    cout<<"Numaric Part: "<<num<<endl;
    unsigned int divisionResult, multiplicationResult;

    unsigned int result = performOperations(num, divisionResult, multiplicationResult);
    cout << "Result of bit-wise AND operation: " << result << endl;

    unsigned int rightShiftResult = performRightShift(num);
    cout << "Result of right shift operation: " << rightShiftResult << endl;

    unsigned int leftShiftResult = performLeftShift(num);
    cout << "Result of left shift operation: " << leftShiftResult << endl;

    return 0;
}

