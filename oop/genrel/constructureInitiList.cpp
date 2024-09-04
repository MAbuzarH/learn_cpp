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
//	   Player(){
//	   	name="none";
//		health=100;
//		xp= 3;
//	   }
	   //this is batter way and this is constructure initialazition list
//	   Player():name{"none"},health{100},xp{3}{
//	   }

//  // // delegating constructor 
//  //this is over loaded constructure with 3 arugment
//  Player(string n,int h,int x):name{n},health{h},xp{x}{
//  	cout<<"overlodad constructure with 3 arguments :-- \n";
//	   }
//  Player():Player{"none",0,0}{
//  		cout<<"constructure with 0 arguments :-- \n";
//       }
//  Player(string n):Player{n,0,0}{
//  		cout<<" constructure with 1 arguments :-- \n";
//       }
	 // // delegating constructor  end
	void display();
};
 Player::Player(string n,int h,int x):name{n},health{h},xp{x}{
  	cout<<"overlodad constructure with 3 arguments :-- \n";
	   }
	   void	Player:: display(){
		cout<<"name: "<<name<<endl;
		cout<<"health: "<<health<<endl;
		cout<<"xp: "<<xp<<endl;
		
	}  

int main(){
Player p1;
p1.display();
Player p2("ali",100,3);
p2.display();
Player p3("qasam");
p3.display();

return 0;	
}
