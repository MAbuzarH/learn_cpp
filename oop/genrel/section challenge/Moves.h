#ifndef MOVIES_H
#define MOVIES_H
#include<iostream>
#include<string>
#include<vector>
#include"move.h"
#include"move.cpp"
using namespace std;
class Movies{
	private:
	vector<Move> movies;
	public:
		//constrcture
//	Movies();	
	   //distrcture
//	~Movies ();
	
	//add move
	bool add_move(string name,string rating,int watched);
	
	//incerment watched
	bool increment_watched(string name);
	
	void display() const;
	 
};




#endif
