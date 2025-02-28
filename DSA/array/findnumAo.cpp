#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int> arr{1,1,2,2,3,4,4,5,5};
int Xor = 0;

for(int i =0; i < arr.size(); i++){
    Xor = Xor^arr[i];
}
cout<<"element"<<Xor<<endl;
    return 0;
}
