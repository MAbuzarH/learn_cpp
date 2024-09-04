#include"Moves.h"
#include<iostream>
#include<string>
#include<vector>


//	Movies(){
//	};	
//	   //distrcture
//	~Movies (){
//		
//	};
	
	//add move
	bool Movies::add_move(string name,string rating,int watched){
		for(const auto &movie : movies){
			if(movies.name == name){
				cout<<" move already exested:"<<endl;
				 return false;
			}
			else{
			 movies.push_back(Move(name,rating,watched));
			 return true;	
			}
		}
	};
	
	//incerment watched
	bool Movies::increment_watched(string name){
		for(const auto &movie : movies){
			if(movies.name == name){
		     
			 ++movies.move_watched
			 return true;
			}
			else{
				 return false;	
		
		    }	
		}
	}
	
	void Movies::display() const{
		for(const auto &movie : movies){
			cout<<"==================== \n";
		cout<< movies.name <<endl;
		cout<<movies.rating <<endl;
		cout<<movies.move_watched <<endl;
			cout<<"==================== \n";
		}
	}
