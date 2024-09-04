#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // int a =10;
    // int *i;
    // // i=&a;
    // cout<<"*i"<<*i<<endl;
    // cout<<"i"<<i<<endl;
    // cout<<"&i"<<&i<<endl;
    // cout<<"size i"<<sizeof(i)<<endl;
    //     int a[3] ={1,2,3};
    //     int b{5};
    //    cout<<*a+1<<" "<<b<<endl;
    // int scoure = 100;
    // int *scoure_ptr = &scoure;
    // // cout<<*scoure_ptr <<endl;
    // int b = 200;
    // *scoure_ptr = b;
    // cout<<scoure<<endl;
    vector<string> stooge{"hi", "bye", "shi"};
    vector<string> *stooge_ptr = nullptr;
    stooge_ptr = &stooge;
    cout << "first stooge : " << (*stooge_ptr).at(0) << endl;
    for(auto stooge : *stooge_ptr){
      cout << stooge<<endl;
    }
    return 0;
}