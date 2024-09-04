//code to checqe if 2 linkedlist are equal or not
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


bool checkEqualLinkList(Node* head1,Node* head2){
	Node* ptr1 = head1;
	Node* ptr2 = head2;
	
	while(ptr1 != NULL && ptr2 != NULL){
		if(ptr1->data != ptr2->data){
			return false;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return (ptr1 == NULL && ptr2 == NULL);
}

int main(){
	LinkList li,li2;
	li.addAtTail(2),li.addAtTail(3),li.addAtTail(4);
	li2.addAtTail(2),li2.addAtTail(3),li2.addAtTail(99);
	bool a = checkEqualLinkList(li.head,li2.head);
	cout<<"bool: "<<a<<endl;
	li.disply();
	return 0;
}
