#ifndef MOVIE_H
#define MOVIE_H
#include<iostream>
#include<string>
using namespace std;
class Movie{
	private:
		string name;
		string rating;
		int watched;
	public:
		
	//getter
	string get_name() const{return name;}	
	string get_rating() const{return rating;}
	int get_watched() const{return watched;}
	
	//setter
	void set_name(string n) ;	
	void set_rating(string r);
	void set_watched(int w);

	
	
	//constrcture
	Movie(string n,string r,int w);
	
	//copy constrcture
	Movie(const Movie &source);
	
	//display
	void display();
	
	//distrctur
	~Movie();
		
};
#endif
