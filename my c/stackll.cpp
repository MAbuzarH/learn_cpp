#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		//constructure
		Node(int d){
			this->data = d;
			this->next = NULL;
		}
		
};
class Stack{
	Node* head;
	int capisty;
	int currsize;
	public:
	Stack(int c){
		capisty = c;
		currsize = 0;
		head= NULL;

	}
	bool isEmpty(){
		return head = NULL;
	}
	bool isFull(){
		return this -> currsize == this->capisty;
	}
	void push(int data){
		if(this -> currsize == this->capisty){
			cout<<"overflow: \n";
			return;
		}
	 Node* new_node = new Node(data);
	 new_node->next = this->head;
	 this->head = new_node;	
	}
	int pop(){
		if(this->head == NULL){
			cout<<"underflow: \n";
			return INT_MIN;
		}
		Node* new_head = this->head->next;
		this->head->next = NULL;
		Node* toBeRemoved = this->head;
		int result = toBeRemoved->data;
		delete toBeRemoved;
		this->head = new_head;
	}
	int size(){
		return this->currsize;
	}
	int getTop(){
			if(this->head == NULL){
			cout<<"underflow: \n";
			return INT_MIN;
		}
		return this->head->data;
	}
};

int main(){
	Stack st(5);
	cout<<	st.isEmpty();
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.pop();

	cout<<st.getTop()<<": ";
	return 0;
}
