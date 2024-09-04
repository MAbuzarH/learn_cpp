
#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
private:
    std::string name;
    std::string rating;
    int move_watched;

public:
    // Constructor
    Move(std::string n, std::string r, int w);

    // Copy Constructor
    Move(const Move &source);

    // Destructor
    ~Move();

    // Member functions
    void set_move_name(std::string n);
    void set_move_rating(std::string r);
    void add_move_watched(int watched);
    void display() const;
    
    //	//getters
	std::string get_move_name() const{return name;}
	std::string get_move_rating() const{return rating;}
	int get_move_watched() const{return move_watched;}
};

#endif // MOVE_H

