#include <iostream>
#include<string>
//constant pointer to constant
//in this case
//the data pointed by the pointer is constant and cannot change
//the pointer itself cannot change and constant.
using namespace std;

int main()
{
int highscore = 100;
int lowscore = 89;

const int *const score_ptr = &highscore;
cout<< score_ptr <<endl;
//*score_ptr = 77; error
//score_ptr = &lowscore; // error

cout<< score_ptr <<endl;
return 0;
}
