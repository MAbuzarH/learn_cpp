//giving the head of ll remove the kth node at the end of the list
//and return its head
#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	
	Node(int val){
	     data = val;
		 next = NULL;
	}
};
class LinkList{
	public:
		Node* head;
		LinkList(){
			head = NULL;
		};
		void addAtTail(int val){
	     Node* newNode = new Node(val);
	    if(head == NULL){
	 	 head = newNode;
	 	 return;
	    }
	 	Node* temp = head;
	 	while(temp->next!= NULL){
	 		temp = temp->next;
		 }
		 temp->next = newNode;
}
			
		void disply(){
     	Node* temp = head;
    	while(temp != NULL){
		cout<<temp->data <<"->";
		temp= temp->next;
	    }
	    cout<<"NULL"<<endl;
}	
};
