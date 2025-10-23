// 
#include <iostream>
using namespace std;
int main()
{

  int rows = 5;
  int cols = 9;
  for (int i = 1; i <= rows; i++)
  {
    for (int j = 1; j <= cols; j++)
    {
      if(j == ((cols/2)+i)){
         cout<<"*";
      }else{
        cout<<" ";
      }
    
      
    }
    cout << endl;
  }

  return 0;
}