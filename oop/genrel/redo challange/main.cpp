#include<iostream>
#include"Movie.h"
#include"Movie.cpp"
#include"Movies.h"
#include"Movies.cpp"
using namespace std;


//helper function 
void incerement_watched(Movies &movies,string name);
void add_movies(Movies &movies,string name,string rating, int watched);

//helper function defination of  add movie
void add_movies(Movies &movies,string name,string rating, int watched){
	if(movies.add_movie(name,rating,watched)){
		cout<<"Movie added: "<<name<<endl;
	}
	else{
		cout<<"Already added: "<<name<<endl;
	}
}


//helper function defination of  increas movie watched
void incerement_watched(Movies &movies,string name){
if(movies.increment_watched(name)){
	cout<<"Watched time increased of: "<< name<<endl;
}
else{
	cout <<"This movie is not exist in List:"<<endl;
}
}

int main(){
Movies my_movies;
  my_movies.display();
    add_movies(my_movies, "Inception", "PG-13", 5);
    add_movies(my_movies, "The Matrix", "R", 7);
    add_movies(my_movies, "Inception", "PG-13", 5); // Trying to add a duplicate

    my_movies.display();

    incerement_watched(my_movies, "Inception");
    my_movies.display();
	return 0;
}
