#include <iostream>
using namespace std;

class Employee {
public:
    int employeeID;
    string name;

    Employee(int id, string n) : employeeID(id), name(n) {}
};

class Node {
public:
    Employee employee;
    Node* left;
    Node* right;

    Node(Employee emp) : employee(emp), left(NULL), right(NULL) {}
};

class BST {
private:
    Node* root;

    Node* insertEmployeeHelper(Node* node, Employee emp) {
        if (node == NULL) {
            return new Node(emp);
        }
        if (emp.employeeID < node->employee.employeeID) {
            node->left = insertEmployeeHelper(node->left, emp);
        } else if (emp.employeeID > node->employee.employeeID) {
            node->right = insertEmployeeHelper(node->right, emp);
        }
        return node;
    }

    Node* removeEmployeeNode(Node* node, int empID) {
        if (node == NULL) {
            return NULL;
        }
        if (empID < node->employee.employeeID) {
            node->left = removeEmployeeNode(node->left, empID);
        } else if (empID > node->employee.employeeID) {
            node->right = removeEmployeeNode(node->right, empID);
        } else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            } else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->employee = temp->employee;
                node->right = removeEmployeeNode(node->right, temp->employee.employeeID);
            }
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    void printBSTInOrder(Node* node) const {
        if (node != NULL) {
            printBSTInOrder(node->left);
            cout << "Employee ID: " << node->employee.employeeID << ", Name: " << node->employee.name << endl;
            printBSTInOrder(node->right);
        }
    }

    Node* searchEmployee(Node* node, int empID) const {
        if (node == NULL || node->employee.employeeID == empID) {
            return node;
        }
        if (empID < node->employee.employeeID) {
            return searchEmployee(node->left, empID);
        }
        return searchEmployee(node->right, empID);
    }

public:
    BST() : root(NULL) {}

    void insertEmployee(int id, string name) {
        Employee emp(id, name);
        root = insertEmployeeHelper(root, emp);
    }

    void removeEmployee(int empID) {
        root = removeEmployeeNode(root, empID);
    }

    void printBST() const {
        printBSTInOrder(root);
    }

    bool searchEmployee(int empID) const {
        return searchEmployee(root, empID) != NULL;
    }
};

int main() {
    BST bst;

    // Add employees
    bst.insertEmployee(1, "Ali");
    bst.insertEmployee(2, "Bakar");
    bst.insertEmployee(3, "Abuzar");

    cout << "Employees in the system:" << endl;
    bst.printBST();

    // Remove an employee
    cout << "\nRemoving employee with ID 2 (Bakar)." << endl;
    bst.removeEmployee(2);

    cout << "\nEmployees in the system after removal:" << endl;
    bst.printBST();

    // Search for an employee
    int searchID = 1;
    cout << "\nSearching for employee with ID " << searchID << ": ";
    if (bst.searchEmployee(searchID)) {
        cout << "Found." << endl;
    } else {
        cout << "Not found." << endl;
    }

    
    cout << "\n My VUID: Bc220401629" << endl;

    return 0;
}

