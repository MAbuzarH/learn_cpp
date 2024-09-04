//learning linked list 
#include<iostream>
#include<stdlib.h>

using namespace std;


class Node{
	private:
	   int object;
		Node *nextNode;
		Node *previousNode;
	public:
		int get(){
			return object;
		}
		void set(int object){
			this -> object = object;
		}
		Node * getNext(){
			return nextNode;
		}
		void setNext(Node *nextNode){
			this->nextNode = nextNode;
		}
	 	Node * getPrevios(){
			return previousNode;
		}
		void setPrevios(Node *previousNode){
			this->previousNode = previousNode;
		}
	
};
class List{
	private:
		int size;
		Node *headNode;
		Node *currentNode,*lastCurrentNode;
	public:
	List(){//constructer 
		headNode = new Node();
		headNode -> setNext(NULL);
		currentNode = NULL;
		size = 0;
	}
	void add(int addObject){
		Node * newNode = new Node();
		newNode->set(addObject);
		if(currentNode != NULL){
			newNode->setNext(currentNode->getNext()); //newNode ko set next node function call karna hya and 
			//ab setNext 1 argument lata hya jo pointer hya  phr ham nya currentNode k lya getNext ka method call kya 
			// jis nya getNext call kya jo humya nextNode return krya ga 
			currentNode->setNext(newNode);
			lastCurrentNode = currentNode;
			currentNode = newNode;
		}else{
			newNode->setNext(NULL);
			headNode->setNext(newNode);
			lastCurrentNode = headNode;
			currentNode= newNode;
		}
		size++;
	}
	int get(){
		if(currentNode != NULL)
			return currentNode ->get();
	}
	bool next(){
		if(currentNode == NULL)
		return false;
		lastCurrentNode = currentNode;
		currentNode = currentNode -> getNext();
		if(currentNode == NULL || size == 0)
		return false;
		else
		return true;
	}
	void start(){
		lastCurrentNode = headNode;
		currentNode = headNode;
		
	}
	void remove(){
		if(currentNode != NULL && currentNode != headNode){
			lastCurrentNode ->setNext(currentNode->getNext());//phlya
			// lastcurrentnode may currentNode sya aglya walya node ka addres save ho ga
			delete currentNode; //secondely
			//currentNode ko delete kya 	
			currentNode = lastCurrentNode ->getNext(); 
			size--;
		}
	}
	int length(){
		return size;
	}

};
int main(){
	List list;
	list.add(2);list.add(3);list.add(4);
	list.add(6);
	list.start();
	while(list.next()){
		cout <<"List elements are :"<<list.get()<<endl;
	}
}
