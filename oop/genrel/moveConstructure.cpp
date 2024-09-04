
#include<iostream>
using namespace std;
class Move{
	private:
		int *data;
	public:
		//getter
	int get_data(){
		return *data;
	}
	   //setter
	void set_data(int d){
		*data = d;
	} 
	  // constrcture
	Move(int d);
	//copy constructure
	Move(const Move &source);
	//move constructre
	Move(Move && source);
	//distrcucture
	~Move();    	
};
// constrcture
Move::Move(int d){
		
	data = new int;
	*data = d;
	cout<<"constructure is called for: "<<(*data)<<endl;
}
//copy constructure
Move::Move(const Move &source):Move(*source.data){
		cout<<"copy constructure is called for: "<<(*source.data)<<endl;
};
//move constructre
Move::Move(Move &&source) noexcept : data(source.data) {
    cout << "Move constructor called for: " << *source.data << endl;
    source.data = NULL;
}
//distructure
Move::~Move(){
  if (data != NULL) {
        cout << "Destructor is called for: " << *data << endl;
    } else {
        cout << "Destructor is called for nullptr" << endl;
    }
    delete data;
}
void display(Move d){
	cout<<"Data: "<<d.get_data()<<endl;
}
int main(){
	Move m1(100);
	display(m1);
	Move m2 = m1;
	display(m2);
	m2.set_data(1000);
	
	return 0;
}
