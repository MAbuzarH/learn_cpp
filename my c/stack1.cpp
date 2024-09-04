#include<iostream>
#include <string>


using namespace std;

//#define n 100;
class Stack{
private:
    int maxSize;        // Maximum size of the stack
    int top;            // Index of the top element
    string* stackArray; // Pointer to the array holding the stack elements
public:
	// Constructor to initialize the stack
    Stack(int size) {
        maxSize = size;
        top = -1; // Stack is initially empty
        stackArray = new string[maxSize];
    }
    // Destructor to free allocated memory
    ~Stack() {
        delete[] stackArray;
    }
    // Push a string onto the stack
    void push(const string& item) {
        if (isFull()) {
            cerr << "Stack Overflow: Cannot push " << item << endl;
            return;
        }
        stackArray[++top] = item;
    }
     // Pop a string from the stack
    string pop() {
        if (isEmpty()) {
            cerr << "Stack Underflow: Cannot pop" << endl;
            return "";
        }
        return stackArray[top--];
    }
    // Peek at the top element without removing it
    string peek() const {
        if (isEmpty()) {
            cerr << "Stack is empty: Cannot peek" << endl;
            return "";
        }
        return stackArray[top];
    }
    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }
     // Check if the stack is full
    bool isFull() const {
        return top == maxSize - 1;
    }
	
};

int main(){
	 Stack stack(5); // Create a stack of size 5

    stack.push("Hello");
    stack.push("World");
    stack.push("!");

    cout << "Top element: " << stack.peek() << endl;

    cout << "Popping elements: ";
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
    cout << endl;

    return 0;
}
