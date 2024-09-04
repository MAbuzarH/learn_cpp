#include<iostream>

using namespace std;

class Node {
	public:
		int data;
		Node * next;
		Node(int val){
			data = val;
			next = NULL;
		}
};

void display(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}


void add(Node* &head,int val){
	Node* n = new Node(val);
	if(head == NULL){
		head = n;
	}else{
	Node* temp = head;
	while(temp->next != NULL){
		temp=temp->next; 
	}
	temp->next = n;
	}
}

void deleteAltrnat(Node* &head){
	Node* curr = head;
	while(curr->next != NULL  ){
		Node* toDelete = curr->next;
		
	
	curr->next = curr->next->next;
	
	delete toDelete;
    curr = curr->next;
	if (curr == NULL)
	break;	
	
	}

	

}

int main(){
	Node* head = NULL;

	add(head,1),add(head,2),add(head,3),add(head,4);
	  display(head);
	  cout<<"after update"<<endl;
	  deleteAltrnat(head);
	  display(head);
	return 0;
}
