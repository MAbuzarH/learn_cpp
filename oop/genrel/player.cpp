//const correctness
#include<iostream>
using namespace std;
class Player{
	private:
		string name;
		int health;
		int xp;
	public:
		//getter
	string get_name() const{
		return name;
	}
	int get_health() const{
		return health;
	}
	int get_xp() const{
		return xp;
	}
	   //setter
	void set_name(string n){
		name = n;
	}
	void set_health(int h){
    	health = h;
	}
	void set_xp(int x){
	 xp = x;
	}   
	   //counstructre
	Player(string s="none",int h=0,int x=0):name{s},health{h},xp{x}{
	}
	  // copy cons
	Player(const Player &source);
	// distrcture
	~Player(){
	}     	
};
Player::Player(const Player &source){
	name=source.name;
	health=source.health ;
	xp=source.xp ;
}
void player_display(const Player &p){
	cout<<"name: "<<p.get_name()<<endl;
	cout<<"health: "<<p.get_health()<<endl;
	cout<<"xp: "<<p.get_xp()<<endl;
}
int main(){
	const Player p1("ali",100,50);
    Player p2("asam",110,40);
	player_display(p1);
	
	return 0;
}
