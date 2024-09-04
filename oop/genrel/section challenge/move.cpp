#include "move.h"
#include <iostream>
#include <string>

using namespace std;

void Move::set_move_rating(string r) {
    rating = r;            
}

void Move::set_move_name(string n) {
    name = n;        
}

void Move::add_move_watched(int watched) {        
    move_watched = watched;
}

// Constructor implementation
Move::Move(string n, string r, int w)  {
	name =n;
	rating = r;
	move_watched= w;
}

// Copy constructor implementation
Move::Move(const Move &source) : Move(source.name, source.rating, source.move_watched) {        
}

// Destructor implementation
Move::~Move() {
}

// Display method implementation
void Move::display() const {
    cout << name << "," << rating << "," << move_watched << endl;  // Added semicolon at the end
}
//	void Move::increment_watched(){
//	 ++move_watched;
//	};
