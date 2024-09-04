#include <iostream>
#include <string>
using namespace std;

class Task {
private:
    string description;

public:
    Task(string desc) : description(desc) {}

    string getDescription() {
        return description;
    }

    void setDescription(string desc) {
        description = desc;
    }
};

class Node {
private:
    Task* task;
    Node* next;

public:
    Node(Task* t) : task(t), next(NULL) {}

    ~Node() {
        delete task;
    }

    Task* getTask() {
        return task;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* n) {
        next = n;
    }
};

class List {
private:
    Node* head;

public:
    List() : head(NULL) {}

    ~List() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->getNext();
            delete current;
            current = next;
        }
    }

    void addTask(string desc) {
        Task* newTask = new Task(desc);
        Node* newNode = new Node(newTask);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->getNext() != NULL) {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
    }

    void displayTasks() {
        Node* current = head;
        int count = 0;
        while (current != NULL) {
        cout <<"-" << current->getTask()->getDescription() << endl;
            current = current->getNext();
        }
//        cout << "Total Tasks: " << count << endl;
    }

    void removeTask(string desc) {
        Node* current = head;
        Node* prev = NULL;

        while (current != NULL) {
            if (current->getTask()->getDescription() == desc) {
                if (prev == NULL) {
                    head = current->getNext();
                } else {
                    prev->setNext(current->getNext());
                }
                delete current;
                break;
            }
            prev = current;
            current = current->getNext();
        }
    }
};

int main() {
    List taskList;
cout<<"==============(Bc220401629)===================="<<endl;
    taskList.addTask("Task 1");
    taskList.addTask("Task 2");
    taskList.addTask("Task 3");
    taskList.addTask("Task 4");
    taskList.addTask("Task 5");

   
    taskList.displayTasks();
 cout << "Total Task entered: 5" << endl;
    taskList.removeTask("Task 3");
   cout << "Task \"Task 3\" removed" << endl;
    taskList.removeTask("Task 5");
cout << "Task \"Task 5\" removed" << endl;
  
    cout<<"==============(Bc220401629)===================="<<endl;
    taskList.displayTasks();
cout << "Total Task entered: 3" << endl;
    return 0;
}

