#ifndef MOVIES_H
#define MOVIES_H
#include<iostream>
#include<vector>
#include<string>
#include"Movie.h"
//#include"Movie.cpp"

using namespace std;

class Movies{
	private:
		vector<Movie> movies;
	public:
	
	// add new movies
	bool add_movie(string name,string rating,int watched);
	
	// increment in watch time
	bool increment_watched(string name);
	
	//display list of movies
	void display();
	
};

#endif		
