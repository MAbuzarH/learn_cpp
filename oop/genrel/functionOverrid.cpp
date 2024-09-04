#include <iostream>

using namespace std;

class Paret{
    public:
    virtual void print(){
        cout<<"in parent class"<<endl;
    }
      void show(){
        cout<<"in parent class"<<endl;
    }
};
class Childe:public Paret{
    public:
    void print(){
        cout<<"in childe class"<<endl;
    }
      void show(){
        cout<<"in childe class"<<endl;
    }
};

int main(){
  Paret *p;
  Childe c;
    p= &c;
   p->print();
   p->show();
    return 0;
}