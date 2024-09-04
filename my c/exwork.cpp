
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Declare the global variables for using in the arrays
const int MAX_USERS = 100;
const int MAX_RECORDS = 100;
const int MAX_DRUGS = 100;
const int MAX_CUSTOMERS = 100;
const int MAX_SALES = 100;

// Structure function for the user data
struct User {
    string username;
    string password;
};

// Structure function for the patient data
struct PatientRecord {
    string name;
    string disease;
    string medicine;
    string suggestedMedicine;
    double price;
};

// Structure function for the drug data
struct Drug {
    string name;
    int quantity;
    double price;
};

// Structure function for the customer data
struct Customer {
    string name;
    string address;
    string phoneNumber;
};

// Structure function for the sales data
struct Sale {
    string customerName;
    string item;
    int quantity;
    double totalPrice;
};

// Function prototypes
void header();
int mainMenu(bool isLoggedIn);
void signup(User users[], int &userCount);
bool login(User users[], int userCount);
void saveUserData(const User users[], int userCount);
void loadUserData(User users[], int &userCount);
void savePatientRecords(const PatientRecord patientRecords[], int recordCount);
void loadPatientRecords(PatientRecord patientRecords[], int &recordCount);
void saveInventory(const Drug inventory[], int drugCount);
void loadInventory(Drug inventory[], int &drugCount);
void saveCustomers(const Customer customers[], int customerCount);
void loadCustomers(Customer customers[], int &customerCount);
Drug searchInventory(string drugName, Drug inventory[], int drugCount);
bool deleteInventory(string drugName, Drug inventory[], int &drugCount);
bool updateInventory(string drugName, int newQuantity, double newPrice, Drug inventory[], int drugCount);
void saveSales(const Sale sales[], int saleCount);
void loadSales(Sale sales[], int &saleCount);
void addPatientRecord(PatientRecord patientRecords[], int &recordCount);
void displayPatientRecords(const PatientRecord patientRecords[], int recordCount);
void manageCustomers(Customer customers[], int &customerCount);
void processSales(Sale sales[], int &saleCount);
void generateReport(const Sale sales[], int saleCount);
void displayDrug(Drug d);
void displayInventory(const Drug inventory[], int drugCount);
void displayCustomers(const Customer customers[], int customerCount);
void displaySalesSlip(const Sale &sale);

int main() {
    // Declare arrays by the usage of struct to store data up to 100
    User users[MAX_USERS];
    PatientRecord patientRecords[MAX_RECORDS];
    Drug inventory[MAX_DRUGS];
    Customer customers[MAX_CUSTOMERS];
    Sale sales[MAX_SALES];

    int userCount = 0;
    int recordCount = 0;
    int drugCount = 0;
    int customerCount = 0;
    int saleCount = 0;

    loadUserData(users, userCount);
    loadPatientRecords(patientRecords, recordCount);
    loadInventory(inventory, drugCount);
    loadCustomers(customers, customerCount);
    loadSales(sales, saleCount);

    bool isLoggedIn = false;
    int opt;

    // Display program header
    header();

    // Main program loop
    while (true) {
        if (!isLoggedIn) {
            // If not logged in, display login / signup options
            opt = mainMenu(isLoggedIn);

            switch (opt) {
                case 1:
                    signup(users, userCount);
                    break;
                case 2:
                    if (login(users, userCount)) {
                        isLoggedIn = true;
                    } else {
                        cout << "Login failed. Please try again." << endl;
                    }
                    break;
                case 3:
                    // Exit program
                    cout << "Exiting program." << endl;

                    // Functions called to save the data after exiting the program
                    saveUserData(users, userCount);
                    savePatientRecords(patientRecords, recordCount);
                    saveInventory(inventory, drugCount);
                    saveCustomers(customers, customerCount);
                    saveSales(sales, saleCount);
                    return 0;
                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        } else {
            // If loggedIn is true, display main menu options
            int Opt = mainMenu(isLoggedIn);
            switch (Opt) {
                case 1:
                    addPatientRecord(patientRecords, recordCount);
                    break;
                case 2:
                    displayPatientRecords(patientRecords, recordCount);
                    break;
                case 3:
                    manageCustomers(customers, customerCount);
                    break;
                case 4:
                    processSales(sales, saleCount);
                    break;
                case 5:
                    generateReport(sales, saleCount);
                    break;
                case 6:
                    displayInventory(inventory, drugCount);
                    break;
                case 7: {
                    string drugName;
                    cout << "Enter the name of the drug to search: ";
                    cin >> drugName;
                    Drug foundDrug = searchInventory(drugName, inventory, drugCount);
                    if (!foundDrug.name.empty()) {
                        cout << "Drug found in inventory:" << endl;
                        displayDrug(foundDrug);
                    } else {
                        cout << "Drug not found in inventory." << endl;
                    }
                    break;
                }
                case 8: {
                    string drugName;
                    cout << "Enter the name of the drug to delete: ";
                    cin >> drugName;
                    if (deleteInventory(drugName, inventory, drugCount)) {
                        cout << "Drug deleted from inventory." << endl;
                    } else {
                        cout << "Drug not found in inventory." << endl;
                    }
                    break;
                }
                case 9: {
                    string drugName;
                    int newQuantity;
                    double newPrice;
                    cout << "Enter the name of the drug to update: ";
                    cin >> drugName;
                    cout << "Enter the new quantity: ";
                    cin >> newQuantity;
                    cout << "Enter the new price: ";
                    cin >> newPrice;
                    if (updateInventory(drugName, newQuantity, newPrice, inventory, drugCount)) {
                        cout << "Inventory updated successfully." << endl;
                    } else {
                        cout << "Drug not found in inventory." << endl;
                    }
                    break;
                }
                case 10:
                    displayCustomers(customers, customerCount);
                    break;
                case 11:
                    cout << "Logging out " << endl;
                    isLoggedIn = false;
                    break;
                case 12:
                    // Exit program
                    cout << "Exiting program. " << endl;
                    saveUserData(users, userCount);
                    savePatientRecords(patientRecords, recordCount);
                    saveInventory(inventory, drugCount);
                    saveCustomers(customers, customerCount);
                    saveSales(sales, saleCount);
                    return 0;
                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        }
    }

    return 0;
}

void header() {
    cout << "         **********             " << endl;
    cout << "****************" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "*          Welcome To HASEEB Pharmacy          *" << endl;
    cout << "*                                              *" << endl;
    cout << "*                                              *" << endl;
    cout << "****************" << endl;
    cout << "         **********             " << endl;
}

int mainMenu(bool isLoggedIn) {
    int choice;
    cout << "-------------------------------------------------" << endl;
    cout << "----------------- Main Menu ---------------------" << endl;
    if (!isLoggedIn) {
        cout << "1- Signup " << endl;
        cout << "2- Login " << endl;
        cout << "3- Exit program " << endl;
    } else {
        cout << "1- Add Patient Record " << endl;
        cout << "2- Display Patient Records " << endl;
        cout << "3- Manage Customers " << endl;
        cout << "4- Process Sales " << endl;
        cout << "5- Generate Report " << endl;
        cout << "6- Display Inventory " << endl;
        cout << "7- Search Inventory " << endl;
        cout << "8- Delete Inventory " << endl;
        cout << "9- Update Inventory " << endl;
        cout << "10- Display Customers " << endl;
        cout << "11- Logout " << endl;
        cout << "12- Exit program " << endl;
    }
    cout << "----------------------------------------------- " << endl;
    cout << "Choose option from the menu = ";
    cin >> choice;

    return choice;
}

void signup(User users[], int &userCount) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    if (userCount >= MAX_USERS) {
        cout << "User limit reached. Cannot add more users." << endl;
        return;
    }

    cout << "-----------------------------------------------" << endl;
    cout << "                  Signup                        " << endl;
    cout << "-----------------------------------------------" << endl;
    User newUser;
    cout << "Enter Username: ";
    cin >> newUser.username;
    cout << "Enter Password: ";
    cin >> newUser.password;

    users[userCount] = newUser;
    userCount++;

    saveUserData(users, userCount);

    cout << "Signup successful!" << endl;
}

bool login(User users[], int userCount) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    cout << "-----------------------------------------------" << endl;
    cout << "                   Login                        " << endl;
    cout << "-----------------------------------------------" << endl;
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    for (int i = 0; i < userCount; i++) {
        if (users[i].username == username && users[i].password == password) {
            cout << "Login successful!" << endl;
            return true;
        }
    }
    cout << "Login failed. Invalid username or password." << endl;
    return false;
}

void saveUserData(const User users[], int userCount) {
    ofstream file("users.txt");
    if (!file) {
        cout << "Error opening users file for writing." << endl;
        return;
    }

    for (int i = 0; i < userCount; i++) {
        file << users[i].username << " " << users[i].password << endl;
    }

    file.close();
}

void loadUserData(User users[], int &userCount) {
    ifstream file("users.txt");
    if (!file) {
        cout << "Error opening users file for reading." << endl;
        return;
    }

    userCount = 0;
    while (file >> users[userCount].username >> users[userCount].password) {
        userCount++;
    }

    file.close();
}

void savePatientRecords(const PatientRecord patientRecords[], int recordCount) {
    ofstream file("patient_records.txt");
    if (!file) {
        cout << "Error opening patient records file for writing." << endl;
        return;
    }

    for (int i = 0; i < recordCount; i++) {
        file << patientRecords[i].name << " "
             << patientRecords[i].disease << " "
             << patientRecords[i].medicine << " "
             << patientRecords[i].suggestedMedicine << " "
             << patientRecords[i].price << endl;
    }

    file.close();
}

void loadPatientRecords(PatientRecord patientRecords[], int &recordCount) {
    ifstream file("patient_records.txt");
    if (!file) {
        cout << "Error opening patient records file for reading." << endl;
        return;
    }

    recordCount = 0;
    while (file >> patientRecords[recordCount].name
                >> patientRecords[recordCount].disease
                >> patientRecords[recordCount].medicine
                >> patientRecords[recordCount].suggestedMedicine
                >> patientRecords[recordCount].price) {
        recordCount++;
    }

    file.close();
}

void saveInventory(const Drug inventory[], int drugCount) {
    ofstream file("inventory.txt");
    if (!file) {
        cout << "Error opening inventory file for writing." << endl;
        return;
    }

    for (int i = 0; i < drugCount; i++) {
        file << inventory[i].name << " "
             << inventory[i].quantity << " "
             << inventory[i].price << endl;
    }

    file.close();
}

void loadInventory(Drug inventory[], int &drugCount) {
    ifstream file("inventory.txt");
    if (!file) {
        cout << "Error opening inventory file for reading." << endl;
        return;
    }

    drugCount = 0;
    while (file >> inventory[drugCount].name
                >> inventory[drugCount].quantity
                >> inventory[drugCount].price) {
        drugCount++;
    }

    file.close();
}

void saveCustomers(const Customer customers[], int customerCount) {
    ofstream file("customers.txt");
    if (!file) {
        cout << "Error opening customers file for writing." << endl;
        return;
    }

    for (int i = 0; i < customerCount; i++) {
        file << customers[i].name << " "
             << customers[i].address << " "
             << customers[i].phoneNumber << endl;
    }

    file.close();
}

void loadCustomers(Customer customers[], int &customerCount) {
    ifstream file("customers.txt");
    if (!file) {
        cout << "Error opening customers file for reading." << endl;
        return;
    }

    customerCount = 0;
    while (file >> customers[customerCount].name
                >> customers[customerCount].address
                >> customers[customerCount].phoneNumber) {
        customerCount++;
    }

    file.close();
}

Drug searchInventory(string drugName, Drug inventory[], int drugCount) {
    for (int i = 0; i < drugCount; i++) {
        if (inventory[i].name == drugName) {
            return inventory[i];
        }
    }
    Drug emptyDrug = {"", 0, 0.0};
    return emptyDrug;
}

bool deleteInventory(string drugName, Drug inventory[], int &drugCount) {
    for (int i = 0; i < drugCount; i++) {
        if (inventory[i].name == drugName) {
            for (int j = i; j < drugCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            drugCount--;
            saveInventory(inventory, drugCount);
            return true;
        }
    }
    return false;
}

bool updateInventory(string drugName, int newQuantity, double newPrice, Drug inventory[], int drugCount) {
    for (int i = 0; i < drugCount; i++) {
        if (inventory[i].name == drugName) {
            inventory[i].quantity = newQuantity;
            inventory[i].price = newPrice;
            saveInventory(inventory, drugCount);
            return true;
        }
    }
    return false;
}

void saveSales(const Sale sales[], int saleCount) {
    ofstream file("sales.txt");
    if (!file) {
        cout << "Error opening sales file for writing." << endl;
        return;
    }

    for (int i = 0; i < saleCount; i++) {
        file << sales[i].customerName << " "
             << sales[i].item << " "
             << sales[i].quantity << " "
             << sales[i].totalPrice << endl;
    }

    file.close();
}

void loadSales(Sale sales[], int &saleCount) {
    ifstream file("sales.txt");
    if (!file) {
        cout << "Error opening sales file for reading." << endl;
        return;
    }

    saleCount = 0;
    while (file >> sales[saleCount].customerName
                >> sales[saleCount].item
                >> sales[saleCount].quantity
                >> sales[saleCount].totalPrice) {
        saleCount++;
    }

    file.close();
}

void addPatientRecord(PatientRecord patientRecords[], int &recordCount) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    if (recordCount >= MAX_RECORDS) {
        cout << "Patient record limit reached. Cannot add more records." << endl;
        return;
    }

    cout << "-----------------------------------------------" << endl;
    cout << "              Add Patient Record                " << endl;
    cout << "-----------------------------------------------" << endl;
    PatientRecord newRecord;
    cout << "Enter Patient Name: ";
    cin >> newRecord.name;
    cout << "Enter Disease: ";
    cin >> newRecord.disease;
    cout << "Enter Medicine: ";
    cin >> newRecord.medicine;
    cout << "Enter Suggested Medicine: ";
    cin >> newRecord.suggestedMedicine;
    cout << "Enter Price: ";
    cin >> newRecord.price;

    patientRecords[recordCount] = newRecord;
    recordCount++;

    savePatientRecords(patientRecords, recordCount);

    cout << "Patient record added successfully!" << endl;
}

void displayPatientRecords(const PatientRecord patientRecords[], int recordCount) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    cout << "-----------------------------------------------" << endl;
    cout << "             Display Patient Records            " << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < recordCount; i++) {
        cout << "Patient Name: " << patientRecords[i].name << endl;
        cout << "Disease: " << patientRecords[i].disease << endl;
        cout << "Medicine: " << patientRecords[i].medicine << endl;
        cout << "Suggested Medicine: " << patientRecords[i].suggestedMedicine << endl;
        cout << "Price: " << patientRecords[i].price << endl;
        cout << "-----------------------------------------------" << endl;
    }
}
void addCustomer(Customer customers[], int &customerCount) {
    if (customerCount >= MAX_CUSTOMERS) {
        cout << "Customer limit reached. Cannot add more customers." << endl;
        return;
    }

    cout << "-----------------------------------------------" << endl;
    cout << "                Add Customer                    " << endl;
    cout << "-----------------------------------------------" << endl;
    Customer newCustomer;
    cout << "Enter Customer Name: ";
    cin >> newCustomer.name;
    cout << "Enter Address: ";
    cin >> newCustomer.address;
    cout << "Enter Phone Number: ";
    cin >> newCustomer.phoneNumber;

    customers[customerCount] = newCustomer;
    customerCount++;

    saveCustomers(customers, customerCount);

    cout << "Customer added successfully!" << endl;
}
void manageCustomers(Customer customers[], int &customerCount) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    int choice;
    cout << "-----------------------------------------------" << endl;
    cout << "              Manage Customers                  " << endl;
    cout << "-----------------------------------------------" << endl;
    cout <<"1. Add Customer" << endl;
    cout << "2. Display Customers" << endl;
    cout << "3. Delete Customer" << endl;
    cout << "4. Search Customer" << endl;
    cout << "5. Update Customer" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addCustomer(customers, customerCount);
            break;
        case 2:
            displayCustomers(customers, customerCount);
            break;
        case 3:
            deleteCustomer(customers, &customerCount);
            break;
        case 4:
            searchCustomer(customers, customerCount);
            break;
        case 5:
            updateCustomer(customers, customerCount);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}



void displayCustomers(const Customer customers[], int customerCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "               Display Customers                " << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < customerCount; i++) {
        cout << "Customer Name: " << customers[i].name << endl;
        cout << "Address: " << customers[i].address << endl;
        cout << "Phone Number: " << customers[i].phoneNumber << endl;
        cout << "-----------------------------------------------" << endl;
    }
}

void deleteCustomer(Customer customers[], int &customerCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "                Delete Customer                 " << endl;
    cout << "-----------------------------------------------" << endl;
    string customerName;
    cout << "Enter Customer Name to delete: ";
    cin >> customerName;

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].name == customerName) {
            for (int j = i; j < customerCount - 1; j++) {
                customers[j] = customers[j + 1];
            }
            customerCount--;
            saveCustomers(customers, customerCount);
            cout << "Customer deleted successfully!" << endl;
            return;
        }
    }
    cout << "Customer not found." << endl;
}

void searchCustomer(const Customer customers[], int customerCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "                Search Customer                 " << endl;
    cout << "-----------------------------------------------" << endl;
    string customerName;
    cout << "Enter Customer Name to search: ";
    cin >> customerName;

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].name == customerName) {
            cout << "Customer Name: " << customers[i].name << endl;
            cout << "Address: " << customers[i].address << endl;
            cout << "Phone Number: " << customers[i].phoneNumber << endl;
            cout << "-----------------------------------------------" << endl;
            return;
        }
    }
    cout << "Customer not found." << endl;
}

void updateCustomer(Customer customers[], int customerCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "               Update Customer                  " << endl;
    cout << "-----------------------------------------------" << endl;
    string customerName;
    cout << "Enter Customer Name to update: ";
    cin >> customerName;

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].name == customerName) {
            cout << "Enter New Address: ";
            cin >> customers[i].address;
            cout << "Enter New Phone Number: ";
            cin >> customers[i].phoneNumber;
            saveCustomers(customers, customerCount);
            cout << "Customer updated successfully!" << endl;
            return;
        }
    }
    cout << "Customer not found." << endl;
}

void manageInventory(Drug inventory[], int &drugCount) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    int choice;
    cout << "-----------------------------------------------" << endl;
    cout << "               Manage Inventory                 " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "1. Add Drug" << endl;
    cout << "2. Display Inventory" << endl;
    cout << "3. Delete Drug" << endl;
    cout << "4. Search Drug" << endl;
    cout << "5. Update Drug" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            addDrug(inventory, drugCount);
            break;
        case 2:
            displayInventory(inventory, drugCount);
            break;
        case 3:
            deleteDrug(inventory, drugCount);
            break;
        case 4:
            searchDrug(inventory, drugCount);
            break;
        case 5:
            updateDrug(inventory, drugCount);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void addDrug(Drug inventory[], int &drugCount) {
    if (drugCount >= MAX_DRUGS) {
        cout << "Inventory limit reached. Cannot add more drugs." << endl;
        return;
    }

    cout << "-----------------------------------------------" << endl;
    cout << "                  Add Drug                      " << endl;
    cout << "-----------------------------------------------" << endl;
    Drug newDrug;
    cout << "Enter Drug Name: ";
    cin >> newDrug.name;
    cout << "Enter Quantity: ";
    cin >> newDrug.quantity;
    cout << "Enter Price: ";
    cin >> newDrug.price;

    inventory[drugCount] = newDrug;
    drugCount++;

    saveInventory(inventory, drugCount);

    cout << "Drug added successfully!" << endl;
}

void displayInventory(const Drug inventory[], int drugCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "               Display Inventory                " << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < drugCount; i++) {
        cout << "Drug Name: " << inventory[i].name << endl;
        cout << "Quantity: " << inventory[i].quantity << endl;
        cout << "Price: " << inventory[i].price << endl;
        cout << "-----------------------------------------------" << endl;
    }
}

void deleteDrug(Drug inventory[], int &drugCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "                 Delete Drug                    " << endl;
    cout << "-----------------------------------------------" << endl;
    string drugName;
    cout << "Enter Drug Name to delete: ";
    cin >> drugName;

    if (deleteInventory(drugName, inventory, drugCount)) {
        cout << "Drug deleted successfully!" << endl;
    } else {
        cout << "Drug not found." << endl;
    }
}

void searchDrug(const Drug inventory[], int drugCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "                 Search Drug                    " << endl;
    cout << "-----------------------------------------------" << endl;
    string drugName;
    cout << "Enter Drug Name to search: ";
    cin >> drugName;

    Drug foundDrug = searchInventory(drugName, inventory, drugCount);
    if (foundDrug.name != "") {
        cout << "Drug Name: " << foundDrug.name << endl;
        cout << "Quantity: " << foundDrug.quantity << endl;
        cout << "Price: " << foundDrug.price << endl;
        cout << "-----------------------------------------------" << endl;
    } else {
        cout << "Drug not found." << endl;
    }
}

void updateDrug(Drug inventory[], int drugCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "                 Update Drug                    " << endl;
    cout << "-----------------------------------------------" << endl;
    string drugName;
    cout << "Enter Drug Name to update: ";
    cin >> drugName;

    int newQuantity;
    double newPrice;
    cout << "Enter New Quantity: ";
    cin >> newQuantity;
    cout << "Enter New Price: ";
    cin >> newPrice;

    if (updateInventory(drugName, newQuantity, newPrice, inventory, drugCount)) {
        cout << "Drug updated successfully!" << endl;
    } else {
        cout << "Drug not found." << endl;
    }
}

void generateReport(const Drug inventory[], int drugCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "               Inventory Report                 " << endl;
    cout << "-----------------------------------------------" << endl;
    ofstream file("inventory_report.txt");
    if (!file) {
        cout << "Error opening inventory report file for writing." << endl;
        return;
    }

    for (int i = 0; i < drugCount; i++) {
        file << "Drug Name:" << inventory[i].name << endl;
        file << "Quantity: " << inventory[i].quantity << endl;
        file << "Price: " << inventory[i].price << endl;
        file << "-----------------------------------------------" << endl;
    }

    file.close();

    cout << "Inventory report generated successfully!" << endl;
}

void salesMenu(Drug inventory[], int &drugCount, Sale sales[], int &saleCount) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    int choice;
    cout << "-----------------------------------------------" << endl;
    cout << "                  Sales Menu                    " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "1. Make a Sale" << endl;
    cout << "2. Display Sales" << endl;
    cout << "3. Delete Sale" << endl;
    cout << "4. Search Sale" << endl;
    cout << "5. Update Sale" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            makeSale(inventory, drugCount, sales, saleCount);
            break;
        case 2:
            displaySales(sales, saleCount);
            break;
        case 3:
            deleteSale(sales, saleCount);
            break;
        case 4:
            searchSale(sales, saleCount);
            break;
        case 5:
            updateSale(sales, saleCount);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void makeSale(Drug inventory[], int &drugCount, Sale sales[], int &saleCount) {
    if (saleCount >= MAX_SALES) {
        cout << "Sales limit reached. Cannot add more sales." << endl;
        return;
    }

    cout << "-----------------------------------------------" << endl;
    cout << "                 Make a Sale                    " << endl;
    cout << "-----------------------------------------------" << endl;
    Sale newSale;
    cout << "Enter Customer Name: ";
    cin >> newSale.customerName;
    cout << "Enter Item: ";
    cin >> newSale.item;
    cout << "Enter Quantity: ";
    cin >> newSale.quantity;

    Drug foundDrug = searchInventory(newSale.item, inventory, drugCount);
    if (foundDrug.name != "" && foundDrug.quantity >= newSale.quantity) {
        newSale.totalPrice = newSale.quantity * foundDrug.price;
        foundDrug.quantity -= newSale.quantity;

        updateInventory(foundDrug.name, foundDrug.quantity, foundDrug.price, inventory, drugCount);

        sales[saleCount] = newSale;
        saleCount++;

        saveSales(sales, saleCount);

        cout << "Sale made successfully!" << endl;
    } else {
        cout << "Drug not found or insufficient quantity." << endl;
    }
}

void displaySales(const Sale sales[], int saleCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "                 Display Sales                  " << endl;
    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < saleCount; i++) {
        cout << "Customer Name: " << sales[i].customerName << endl;
        cout << "Item: " << sales[i].item << endl;
        cout << "Quantity: " << sales[i].quantity << endl;
        cout << "Total Price: " << sales[i].totalPrice << endl;
        cout << "-----------------------------------------------" << endl;
    }
}

void deleteSale(Sale sales[], int &saleCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "                  Delete Sale                   " << endl;
    cout << "-----------------------------------------------" << endl;
    string customerName;
    cout << "Enter Customer Name to delete sale: ";
    cin >> customerName;

    for (int i = 0; i < saleCount; i++) {
        if (sales[i].customerName == customerName) {
            for (int j = i; j < saleCount - 1; j++) {
                sales[j] = sales[j + 1];
            }
            saleCount--;
            saveSales(sales, saleCount);
            cout << "Sale deleted successfully!" << endl;
            return;
        }
    }
    cout << "Sale not found." << endl;
}

void searchSale(const Sale sales[], int saleCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "                  Search Sale                   " << endl;
    cout << "-----------------------------------------------" << endl;
    string customerName;
    cout << "Enter Customer Name to search sale: ";
    cin >> customerName;

    for (int i = 0; i < saleCount; i++) {
        if (sales[i].customerName == customerName) {
            cout << "Customer Name: " << sales[i].customerName << endl;
            cout << "Item: " << sales[i].item << endl;
            cout << "Quantity: " << sales[i].quantity << endl;
            cout << "Total Price: " << sales[i].totalPrice << endl;
            cout << "-----------------------------------------------" << endl;
            return;
        }
    }
    cout << "Sale not found." << endl;
}

void updateSale(Sale sales[], int saleCount) {
    cout << "-----------------------------------------------" << endl;
    cout << "                 Update Sale                    " << endl;
    cout << "-----------------------------------------------" << endl;
    string customerName;
    cout << "Enter Customer Name to update sale: ";
    cin >> customerName;

    for (int i = 0; i < saleCount; i++) {
        if (sales[i].customerName == customerName) {
            cout << "Enter New Item: ";
            cin >> sales[i].item;
            cout << "Enter New Quantity: ";
            cin >> sales[i].quantity;
            cout << "Enter New Total Price: ";
            cin >> sales[i].totalPrice;
            saveSales(sales, saleCount);
            cout << "Sale updated successfully!" << endl;
            return;
        }
    }
    cout << "Sale not found." << endl;
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;

    PatientRecord patientRecords[MAX_RECORDS];
    int recordCount = 0;

    Drug inventory[MAX_DRUGS];
    int drugCount = 0;

    Customer customers[MAX_CUSTOMERS];
    int customerCount = 0;

    Sale sales[MAX_SALES];
    int saleCount = 0;

    loadUserData(users, userCount);
    loadPatientRecords(patientRecords, recordCount);
    loadInventory(inventory, drugCount);
    loadCustomers(customers, customerCount);
    loadSales(sales, saleCount);

    int choice;
    do {
        cout << "-----------------------------------------------" << endl;
        cout << "             Medical Store Management           " << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "1. Signup" << endl;
        cout << "2. Login" << endl;
        cout << "3. Add Patient Record" << endl;
        cout << "4. Display Patient Records" << endl;
        cout << "5. Manage Customers" << endl;
        cout << "6. Manage Inventory" << endl;
        cout << "7. Generate Inventory Report" << endl;
        cout << "8. Sales Menu" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                signup(users, userCount);
                break;
            case 2:
                if (login(users, userCount)) {
                    cout << "Login successful!" << endl;
                } else {
                    cout << "Login failed!" << endl;
                }
                break;
            case 3:
                addPatientRecord(patientRecords, recordCount);
                break;
            case 4:
                displayPatientRecords(patientRecords, recordCount);
                break;
            case 5:
                manageCustomers(customers, customerCount);
                break;
            case 6:
                manageInventory(inventory, drugCount);
                break;
            case 7:
                generateReport(inventory, drugCount);
                break;
            case 8:
                salesMenu(inventory, drugCount, sales, saleCount);
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
