//copy constructre
#include <iostream>
#include <string>
//constructure initialazition list
using namespace std;

class Player{
	private:
		string name;
		int health;
		int xp;
	public:
		Player(string n ="none",int h = 0, int x = 0);
		string get_name(){return name;}
		int get_health(){return health;}
	    int get_xp(){return xp;}
		//copy constructre
		Player(const Player &source);
		//distructre
		~Player(){
			cout<<"distructre called for: "<<name<<endl;
		}
		};
		// constructre
	  Player::Player(string n,int h,int x):name{n},health{h},xp{x}{
  	  cout<<"overlodad constructure with 3 arguments :-- \n";
	   }
	   //copy consstrcture
	   Player::Player(const Player &source)
	   //:name{source.name},health{source.health},xp{source.xp}
       {
       	//we can also do delegating constructure
       	Player(source.name,source.health,source.xp);
	    cout<<"copy constructure make a copy of: "<<source.name<<endl;
	   }
	   void display(Player p){
	   	cout<<"name: "<<p.get_name()<<endl;
	   	cout<<"health: "<<p.get_health()<<endl;
	   	cout<<"xp: "<<p.get_xp()<<endl;
	   }		
int main(){
Player p1("ali",100,3);
Player p2 = p1;

//display(p1);
//p1.display();
//Player p2("ali",100,3);
//Player p4 = p2;
//p2.display();
//Player p3("qasam");
//p3.display();

return 0;	
}
