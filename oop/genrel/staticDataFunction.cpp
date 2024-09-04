#include<iostream>
#include<string>
using namespace std;

class Player{
	private:
		static int active_player;
		string name;
		int health;
		int xp;
	public:
		Player(string n,int h,int x):name{n},health{h},xp{x}{
		 ++active_player;
		}
		Player(const Player &source):Player(source.name,source.health,source.xp){
		}
		~Player(){
			--active_player;
		}
		static int get_active_player(){
			return active_player;
		}
		void set_name(string n);
		
};

int Player::active_player = 0;
void Player::set_name(string n){
	name = n;
}
void display(){
	cout<<"active Player: "<<Player::get_active_player()<<endl;
}
int main(){
//display();	
Player p1("ali",100,20);
//display();	
//{
//Player p2("asam",100,20);
//display();	
//}
//display();
//Player *enamy = new Player("jon",10,2);
//display();
p1.set_name("qasam");
return 0;
}
