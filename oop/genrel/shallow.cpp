#include <iostream>
#include <string>
using namespace std;
class Shallow{
	private:
		int *data;
		
	public:
    int get_data(){
    	return *data;
	}
	void set_data (int d){
		*data = d;
	}	
	//constrcture	
	Shallow(int d);
	//copy constructor
	Shallow(const Shallow &source);

	//distrcyter
	~Shallow();	
};
Shallow::Shallow(int d){
	data = new int;
	*data = d;
}
Shallow::~Shallow(){
	delete data;
	cout<<"distrcture freing data"<<endl;
}
Shallow::Shallow(const Shallow &source):data{source.data} {
	cout<< "copy constrctor - shallow \n";
}
	void disply(Shallow obj){
		cout<<"data"<<obj.get_data()<<endl;
	}
int main(){
	Shallow obj1(100);
//	obj1.Shallow(100);
	disply(obj1);
	Shallow obj2 = obj1;
	obj2.set_data(1000);
	return 0;
}
