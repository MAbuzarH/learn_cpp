

//checq if 2 arrays intersect or not;
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
//function to calculate length of linklist
	int calcLength(Node* head){
		Node* temp =head;
		int length = 0;
		while(temp != NULL){
		length++;
		temp=temp->next;	
		}
		return length;
	}
// move head of bigger ll
Node* moveHeadByk(Node* head,int k){
	Node* temp = head;
	while(k--){
		temp = temp->next;
	}
	return temp;
}
//get intersectio node
Node* getIntersectionNode(Node* head1,Node* head2){
	Node* ptr1;
	 Node* ptr2;
//calculate the length of linklist
	int l1 = calcLength(head1);
	int l2 = calcLength(head2);
//find diffrence k of both and move longer one's head for k position
if(l1>l2){
int k = l1 - l2;
ptr1 = moveHeadByk(head1,k);
ptr2 = head2;

}else{
int k = l2 - l1;
ptr1= head1;
ptr2=  moveHeadByk(head2,k);
		
}
//compair ptr 1 and 2 node
while(ptr1){
	if(ptr1 == ptr2){
		
		return ptr1;
	}
	ptr1=ptr1->next;
	ptr2=ptr2->next;
}
return NULL;
}


int main(){
	LinkList l1,l2;
	l1.addAtTail(1),l1.addAtTail(2),l1.addAtTail(3),l1.addAtTail(4),l1.addAtTail(5);
	l2.addAtTail(6),l2.addAtTail(7);
	l2.head->next->next = l1.head->next->next->next;
	l1.disply();
	//1->2->3->4->5->null;
	l2.disply();
	//6->7->4->5->null;
 Node* result = getIntersectionNode(l1.head,l2.head);
 if(result){
 	cout<<"intersect on: "<<result->data<<endl;
 }else{
 	cout<<"-1"<<endl;
 }
	return 0;
}
