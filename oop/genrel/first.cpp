#include <iostream>
using namespace std;
class Fruite{
public:
string name;
string color;
};
int main(){
    Fruite apple;
    apple.name = "Apple";
    apple.color = "red";

    Fruite *mango = new Fruite;
    mango->name="Mango";
    mango->color = "green";

    cout<<apple.name << " -- "<< apple.color << endl;
    cout<< mango->name<< " --"<< mango->color;
    return 0;
}