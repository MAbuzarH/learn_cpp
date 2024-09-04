#include<iostream>

using namespace std;

class Deep{
	private:
		int *data;
	public:
		// constructure
	Deep(int d);
	   //getter
	int get_data(){ return *data;};
	  //setter
	void set_data(int d){
		*data = d;
	}  
	    //copy constructre
	Deep(const Deep &source);
	   //distructure
	~Deep();       
		
};
// constrcture
Deep::Deep(int d){
	cout<<"constructure is called: "<<endl;
	data = new int;
	*data = d;
}
// copy constr
Deep::Deep(const Deep &source):Deep{*source.data} {

}
//distructure:
Deep::~Deep(){
	delete data;
	cout<<"distructure is cleaning data: \n";
}
//display;
void display(Deep d){
	cout<<"data: "<<d.get_data()<<endl;
}

int main(){
	Deep d1(100);
	cout<<"displyaing d1: \n";
	display(d1);
	Deep d2 = d1;
	cout<<"displyaing d2: \n";
	display(d2);
	d2.set_data(1000);
	cout<<"displyaing d1 after changing the vale of d2: \n";
	display(d1);
	cout<<"displyaing d2 after changing the vale of d2: \n";
	display(d2);
	return 0;
	
}
