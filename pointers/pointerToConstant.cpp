#include <iostream>
#include<string>
//pointer to constant
//in this case
//the data pointed by the pointer is constant and cannot change
//the pointer itself can change and point else were.
using namespace std;

int main()
{
int highscore = 100;
int lowscore = 89;

const int *score_ptr = &highscore;
cout<< score_ptr <<endl;
//score_ptr = 77; //error
score_ptr = &lowscore;

cout<< score_ptr <<endl;
return 0;
}
