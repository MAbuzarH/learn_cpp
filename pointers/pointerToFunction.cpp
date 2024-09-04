#include<iostream>
#include<string>
#include<vector>
using namespace std;

//void dobule(int *ptr){
//	*ptr = *ptr * 2;
//}

// // // swap varable // //
//void swap (int *a, int *b){
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}

// /// // display // //
void display (vector<string> *v){
	
	for (int i = 0; i<2; i++){
		cout<< (*v).at(i) << endl;
	}
}

void display (int *arr, int sentinel){
	
	
	while (*arr != sentinel){
		cout<< *arr++<< endl;
	}
}
int main(){
//	int a = 10;
//	int *int_ptr = NULL;
//	
//	cout<<" a before double "<<a<<endl;
//	dobule(&a);
//	cout<<" a after double "<<a<<endl;
//	cout<<"---------------------\n";
//	int_ptr = &a;
//	dobule(int_ptr);
//	cout<<" a after double  by pointer "<<a<<endl;
	// swap function option
//	int a = 10;
//	int b = 20;
//	cout<< "value of a "<< a << "value of b "<<b << " now"<<endl;
//	swap(&a,&b);
//	cout<< "value of a "<< a << "value of b "<<b << " now"<<endl;

    // // // vector creation
//    vector <string> v;
//     v.push_back("ali");
//    v.push_back("asam");
//    v.push_back("jam");
//    display(&v);
    int arr []={10,20,30,100,-1};
    display(arr,-1);
	return 0;
}
