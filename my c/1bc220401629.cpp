#include <iostream>
#include <string>

using namespace std;

class ShoppingList {
private:
    string Items[100];
    int ItemCount;

public:
    ShoppingList() : ItemCount(0) {}

    void addItem(string item) {
        if (ItemCount < 100) {
            Items[ItemCount++] = item;
            cout << item << " added to the shopping list." << endl;
        } else {
            cout << "Shopping list is full. Cannot add more items." << endl;
        }
    }

    void removeItem(string item) {
        for (int i = 0; i < ItemCount; ++i) {
            if (Items[i] == item) {
                for (int j = i; j < ItemCount - 1; ++j) {
                    Items[j] = Items[j + 1];
                }
                ItemCount--;
                cout << item << " removed from the shopping list." << endl;
                return;
            }
        }
        cout << "Item not found in the shopping list." << endl;
    }

    void viewList() {
        cout << "Current items in the shopping list:" << endl;
        for (int i = 0; i < ItemCount; ++i) {
            cout << "- " << Items[i] << endl;
        }
    }

    void clearList() {
        ItemCount = 0;
        cout << "Shopping list cleared." << endl;
    }
};

int main() {
    ShoppingList myList;
    int choice;
    string item;

    do {
        cout << "\n Welcome to  theShopping List Manager\n";
        cout << "1. Add item\n";
        cout << "2. Remove item\n";
        cout << "3. View list\n";
        cout << "4. Clear list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to add: ";
                cin >> item;
                myList.addItem(item);
                break;
            case 2:
                cout << "Enter item to remove: ";
                cin >> item;
                myList.removeItem(item);
                break;
            case 3:
                myList.viewList();
                break;
            case 4:
                myList.clearList();
                break;
            case 5:
                cout << "Exiting The program. GoodBye\n";
                break;
            default:
                cout << "Invalid input. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}

