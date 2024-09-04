#include"Movie.h"
#include<iostream>
using namespace std;
//setter
	void Movie::set_name(string n){
		name = n;
	} 
	void Movie::set_rating(string r){
		rating = r;
	}
	void Movie::set_watched(int w){
		watched = w;
	}
	
	
   //constrcture
	Movie::Movie(string n,string r,int w):name{n},rating{r},watched{w}{
	}
	
	
	//copy constrcture
	Movie::Movie(const Movie &source):	Movie(source.name,source.rating,source.watched){
	}
	
	void Movie::display(){
		cout<<name<<" , "<<rating<<" , " <<watched<<endl;
	}
	
	//distrcture
	Movie::~Movie(){
	}
