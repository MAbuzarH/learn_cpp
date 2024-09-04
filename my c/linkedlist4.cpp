#include <iostream>

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

class LinkedList{
	public:
	Node* head;
	
	LinkedList(){
		head = NULL;
	}
	
	void addAtTail(int val){
		Node* newNode = new Node(val);
		if(head == NULL){
			head = newNode;
			return;
		}
		//agr head pr koi chez hy to humya us pori list k end tk jana hya
		Node * temp = head;
		while(temp->next != NULL){
		temp = temp->next;
		}
		temp->next = newNode;
	}
	void display(){
	 Node * temp = head;
	 while(temp != NULL){
	 	cout<<temp->data<<" -> ";
	 	temp=temp->next;
	 } 	
	 cout<<"NULL"<<endl;
	}
};
void deleteDuplicate(Node* &head){
	Node* curr_node = head;

	while(curr_node != NULL && curr_node->next != NULL){//current node != null


		while(curr_node->data == curr_node->next->data){
//			
			Node* temp = curr_node->next;
			curr_node->next = curr_node->next->next;

			delete temp;
			
		if(curr_node->next  == NULL )
		break;
		}

		curr_node = curr_node->next;
			
	}
}
//print linklist in revers order

void reversePrint(Node* head){
	if(head == NULL)
	return;
reversePrint(head->next);
	cout<<head->data<<"-> \n";
}
//Node* reverseLL(Node* &head){
//	Node* pre = NULL;
//	Node* curr = head;
//	while(curr != NULL){
//		Node* nextptr = curr->next;
//		curr->next = pre;
//		pre = curr;
//		curr = nextptr; 
//	}
//	Node* new_head = pre;
//	return new_head;
//}

Node * reversLLRecursion(Node* &head){
	//base case
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* new_head = reversLLRecursion(head->next);
	head->next->next = head;
	head->next =NULL;
	return new_head; 
}


Node* reversekthLL(Node* &head, int position) {
    Node* prev = NULL;
    Node* currptr = head;
    int count = 0;

    if (head == NULL || head->next == NULL || position <= 1) {
        return head;
    }

    while (currptr != NULL && count < position) {
        Node* nextptr = currptr->next;
        currptr->next = prev;
        prev = currptr;
        currptr = nextptr;
        count++;
    }

    if (currptr != NULL) {
        head->next = reversekthLL(currptr, position);
    }

    return prev;
}

int main(){
	LinkedList li;
//	for (int i = 1; i<= 10; i++){
//		li.addAtTail(i);
//	}
  	li.addAtTail(1),li.addAtTail(2),li.addAtTail(2),
	  li.addAtTail(3),li.addAtTail(3),li.addAtTail(3),
	  li.addAtTail(4);
	  //,li.addAtTail(5);
  	
	li.display();
cout<<"List after Operation"<<endl;
deleteDuplicate(li.head);
reversePrint(li.head);
li.display();
cout<<"List after reverceing"<<endl;
//li.head = reverseLL(li.head);
//li.head = reversLLRecursion(li.head);

li.head = reversekthLL(li.head,2);
li.display();

return 0;
}
