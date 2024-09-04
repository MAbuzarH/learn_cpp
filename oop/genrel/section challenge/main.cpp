#include<iostream>
#include<string>
#include"move.h"
#include"move.cpp"
#include"Moves.h"
#include"moves.cpp"

void incrment_watched(Moves &movies,string name);
void add_movies(Moves &movies,string name,string rating, int watched);

void incrment_watched(Moves &movies,string name){
	if(movies.incrment_watched(name)){
		cout<<name << "watched increment "<<endl;
	}else{
		cout<<name <<"not found"<<endl;
	}
}

void add_movies(Moves &movies,string name,string rating, int watched){
   	if(movies.add_move(name,rating,watched)){
		cout<<name << "added "<<endl;
	}else{
		cout<<name <<"Already exixt:"<<endl;
	}	
}

int main(){
	
	Moves my_movies;
	Move m1("aja","g1",2);
	
	return 0;
	
}
