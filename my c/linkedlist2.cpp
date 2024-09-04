#include<iostream>

using namespace std;

class Node{
	public:
		int val;
		Node* next;

		Node(int data){
//			this->val = val;
            val = data;
			next = NULL;
		}
};
//insert at head
void insertAtHead(Node* &head,int val){
	Node* newNode = new Node(val);
	newNode->next = head;
	head = newNode;
	
}
//insrt at tail
void insertAtTail(Node* &head, int val) {
    Node* newNode = new Node(val); // Create a new node with the given value
    if (head == NULL) {
        head = newNode; // If the list is empty, set the new node as the head
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode; // Insert the new node at the tail of the list
    }
}
//insert at any position
void insertAtPosition(Node* &head, int val , int position){
	if(position ==0){
		insertAtHead(head,val);
		return;
	}
	Node* newNode = new Node(val);
	Node* temp = head;
	int current_pos = 0;
	while (current_pos != position-1){
		temp= temp->next;
		current_pos++;
	}
	newNode->next = temp->next;
	temp->next=newNode;
}
//update any node
void update(Node* &head, int val, int position){
	Node* temp = head;
		int current_pos = 0;
	while (current_pos != position){
		temp= temp->next;
		current_pos++;
	}
	temp->val = val;
}
//display my linked list
void display (Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<<temp->val<<"-> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
//delete a node from start
void deleteAtStart(Node* &head){
	Node* temp = head; //node to be deleted
	head = head->next;
	delete temp;
	
}
//delete a node from end 
void deleteAtend(Node* &head){
//	Node* temp = head;
    Node* second_last = head;
//    i will aplly loop until not got 2ndlast
while(second_last->next->next != NULL){
  second_last =	second_last->next;
}
    //now got second last;
    Node* temp = second_last->next;
    second_last->next = NULL;
    delete temp;
}

void deleteAtPosition(Node* &head, int position){
	if(position == 0){
		deleteAtStart(head);
		return;
	}
	int count = 0;
	Node* temp = head;
	
	while(count != position-1){
		temp = temp->next;
		count++;
	}
	Node* toDelete = temp->next;
    Node* prev = temp;
    temp->next = prev->next->next;
    delete toDelete;
}

int main(){
int input;
cout << "enter any position you want to remove"<<endl;
cin>>input;	
//	Node* n = new Node(4);
//	
//	cout<<n->val <<" :" <<n->next<<endl;
Node* head = NULL;
//insertAtHead(head,2);
//display(head);
//insertAtHead(head,1);
//display(head);
//insertAtHead(head,0);
//display(head);

insertAtTail(head,1);
//display(head);
insertAtTail(head,2);
insertAtTail(head,3);
insertAtTail(head,4);
insertAtTail(head,5);
insertAtPosition(head,55,2);
//update(head,22,2);
//display(head);
//deleteAtStart(head);
cout<<"list before removel"<<endl;
display(head);
//deleteAtend(head);
deleteAtPosition(head,input);
cout<<"list after removel"<<endl;
display(head);
	return 0;
}
