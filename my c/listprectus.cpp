#include<iostream>
#include<stdlib.h>
#include <string>
using namespace std;

class Node{
	private:
		int data;
		Node *nextNode;
	public:
		int get(){
			return data;
		}
		void set(int data){
			this-> data = data;
		}
		Node * getNext(){
			return nextNode;
		}
		void setNext(Node *nextNode){
			this-> nextNode = nextNode;
		}
};

class List{
	private:
		int size;
		Node *head;
		Node *current,*lastCurrentNode;
	public:
		//writing a constructor of list
		List(){
			head = new Node();
			head->setNext(NULL);
			current = NULL;
			size = 0;
		}
		//add new element in list 
	void add(int addObject){
		Node * newNode = new Node();
		
		newNode->set(addObject);
		if(current != NULL){
			newNode->setNext(current->getNext()); 
			current->setNext(newNode);
			lastCurrentNode = current;
			current = newNode;
		}else{
			newNode->setNext(NULL);
			head->setNext(newNode);
			lastCurrentNode = head;
			current= newNode;
		}
		size++;		
		
	}
	//adding at head
	void addAtHead(int addAtStart){
		
	}
		//get list
		int getList(){
			if(current != NULL)
			return current -> get();	
				
		}
		//get the info of next node
		bool next(){
		if(current == NULL)
		return false;
		lastCurrentNode = current;
		current = current -> getNext();
		if(current == NULL || size == 0)
		return false;
		else
		return true;
	}
		//start the program:
		void start(){
			lastCurrentNode = head;
			current = head;
		}
		//remove element from list
		void remove(){
			if(current != NULL || current != head){
				//this is the 3 step process'
				//first step
				lastCurrentNode->setNext(current->getNext());
				//2nc step
				delete current;
				//3rd step
				current = lastCurrentNode->getNext();
				size--;
			}
		}
		int length(){
			return size;
		}
};


int main(){
//	int input;
//	cout<<"add number to add at the start of list"<<endl;
//	cin>>input;
	
	List l1;
	
//	l1.add(input);
//l1.addAtHead(2),l1.addAtHead(4),l1.addAtHead(6);
	for(int i = 0; i <= 50; i++){
		if(i%2==0){
		l1.addAtHead(i);		
		}
	    else{
	    	continue;
		}
	}


l1.start();
	while(l1.next()){
		cout<<"List is "<< l1.getList()<<endl;
	}
	return 0;
}
