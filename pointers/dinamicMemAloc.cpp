#include <iostream>

using namespace std;

int main()
{

    int *arr_ptr = NULL;
    int size;
    cout<<"how long you want to print counting"<<endl;
    cin>>size;
    arr_ptr=new int[size];
      for(int i=0;i<size;i++){
      arr_ptr[i]= i+1;
    }
    for(int i=0;i<size;i++){
     cout<<arr_ptr[i]<<endl;
    }
    delete[] arr_ptr;
return 0;
}