#include"Movies.h"
#include<iostream>
using namespace std;

	// add new movies;
	bool Movies::add_movie(string name,string rating,int watched){
	
	 for (size_t i = 0; i < movies.size(); i++) {
        if (movies[i].get_name() == name) { 
//            cout << "Movie already exists: " << name << endl;
            return false;  
        }
    }
        movies.push_back(Movie(name, rating, watched));  // Add new movie to the collection
        return true;	
	}
	
	// increment in watch time;
	bool Movies::increment_watched(string name){
		 for (size_t i = 0; i < movies.size(); i++) {
          if (movies[i].get_name() != name) { 
//           cout <<"This movie is not exist in List:"<<endl;
           return false;
		  }
		  else{
		  	movies[i].set_watched(movies[i].get_watched() + 1);
		  	return true;
		  }
     	}
	}
	
	//display list of movies
	void Movies::display(){
			if(movies.size() == 0){
			cout<<"---- No Data to show ---- \n";
		    }
			cout<<"=================\n";    
		for(size_t i = 0; i < movies.size(); i++){
	
		movies[i].display();
//		cout<< "Name: "<<movies[i].get_name()<<endl;
//		cout<< "Rating: "<<movies[i].get_rating()<<endl;
//		cout<< "Watched: "<<movies[i].get_watched()<<endl;     
	
		}
			cout<<"=================\n";	
	}
