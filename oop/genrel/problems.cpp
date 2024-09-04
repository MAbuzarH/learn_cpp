#include <iostream>
#include<string>
#include<vector>
using namespace std;
//movie class
class Movie{
	private:
	string name;
    string rating;
    int move_watched;
    public:
    
	
    //	 //getters
	string get_move_name() const  {return name;}
	string get_move_rating() const {return rating;}
	int get_move_watched() const {return move_watched;}
	
	
	
	 // Constructor
    Movie(string n, string r, int w) {
	name =n;
	rating = r;
	move_watched= w;
    }

    // Copy Constructor
    Movie(const Movie &source): Movie(source.name, source.rating, source.move_watched) {        
   }

    // Display method implementation
    void display() const {
    cout << name << "," << rating << "," << move_watched << endl;  // Added semicolon at the end
    }
    //ster
    void set_move_rating(string r) {
    rating = r;            
}

void set_move_name(string n) {
    name = n;        
}

void add_move_watched(int watched) {        
    move_watched = watched;
}

    // Destructor
    ~Movie(){
	}
};

//movies class
class Movies{
	private:
		vector<Movie> movies;
	public:
	//add move
	bool add_move(string name,string rating,int watched){
	 for (size_t i = 0; i < movies.size(); i++) {
        if (movies[i].get_move_name() == name) { 
//            cout << "Movie already exists: " << name << endl;
            return false;  
        }
    }
        movies.push_back(Movie(name, rating, watched));  // Add new movie to the collection
        return true;
	}
	
	//incerment watched
	bool increment_watchedM(string name){
		for(size_t i = 0; i < movies.size(); i++ ){
			if(movies[i].get_move_name() == name){
			  movies[i].add_move_watched(movies[i].get_move_watched() + 1) ;
				return true;
			}
		}
		return false;
	}
	
	void display() const {
//		if(movies.size()){
//			cout<<"no item to show:"<<endl;
//		}
	for(size_t i = 0; i < movies.size(); i++ ){
		cout<<"==================== \n";
//			cout<< movies[i]<<endl;
		cout<< movies[i].get_move_name() <<endl;
		cout<<movies[i].get_move_rating() <<endl;
		cout<<movies[i].get_move_watched() <<endl;
			cout<<"==================== \n";
	}
	}	
};

void incerement_watched(Movies &movies,string name);
void add_movies(Movies &movies,string name,string rating, int watched);

///incerement_watched
void incerement_watched(Movies &movies,string name){
	if(movies.increment_watchedM(name)){
		cout<< name << " :watched increment "<<endl;
	}else{
		cout<<name <<" :not found "<<endl;
	}
}

void add_movies(Movies &movies,string name,string rating, int watched){
   	if(movies.add_move(name,rating,watched)){
		cout<<name << "added "<<endl;
	}else{
		cout<<name <<" :Already exixt"<<endl;
	}	
}

int main(){
 Movies my_movies;
    add_movies(my_movies, "Inception", "PG-13", 5);
    add_movies(my_movies, "The Matrix", "R", 7);
    add_movies(my_movies, "Inception", "PG-13", 5); // Trying to add a duplicate

    my_movies.display();

    incerement_watched(my_movies, "Inception");
    my_movies.display();
	return 0;
}
