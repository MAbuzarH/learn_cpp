#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Declare the global variables for using in the arrays
const int MAX_USERS = 100;
const int MAX_RECORDS = 100;
const int MAX_DRUGS = 100;
const int MAX_CUSTOMERS = 100;
const int MAX_SALES = 100;

//Structure function for the user data
struct User
{
    string username;
    string password;
};
//Structure function for the patient data
struct PatientRecord
{
    string name;
    string disease;
    string medicine;
    string suggestedMedicine;
    double price;
};
//Structure function for the drug data
struct Drug
{
    string name;
    int quantity;
    double price;
};
//Structure function for the customer data
struct Customer
{
    string name;
    string address;
    string phoneNumber;
};
//Structure function for the sales data
struct Sale
{
    string customerName;
    string item;
    int quantity;
    double totalPrice;
};

// Function prototypes
void header ();
int mainMenu (bool isLoggedIn);
void signup (User users[] , int &userCount);
bool login (User users[] , int userCount);
void saveUserData (const User users[], int userCount);
void loadUserData (User users[] , int &userCount);
void savePatientRecords (const PatientRecord patientRecords[] , int recordCount);
void loadPatientRecords (PatientRecord patientRecords[] , int &recordCount);
void saveInventory (const Drug inventory[] , int drugCount);
void loadInventory (Drug inventory[], int &drugCount);
void saveCustomers (const Customer customers[], int customerCount);
void loadCustomers (Customer customers[], int &customerCount);

//Drug searchInventory(string drugName);
Drug searchInventory(string drugName, Drug inventory[], int drugCount);
//bool deleteInventory(string drugName);
bool deleteInventory(string drugName, Drug inventory[], int &drugCount);
//bool updateInventory(string drugName, int newPrice);
bool updateInventory(string drugName, int newQuantity, double newPrice, Drug inventory[], int drugCount);

void saveSales (const Sale sales[], int saleCount);
void loadSales (Sale sales[], int &saleCount);
void addPatientRecord (PatientRecord patientRecords[], int &recordCount);
void displayPatientRecords (const PatientRecord patientRecords[], int recordCount);
void manageCustomers (Customer customers[], int &customerCount);
void processSales (Sale sales[], int &saleCount);
void generateReport (const Sale sales[], int saleCount);

void displayDrug(Drug d);

void displayInventory (const Drug inventory[], int drugCount);
void displayCustomers (const Customer customers[], int customerCount);
void displaySalesSlip (const Sale &saless);

int main()
{
    // Declare arrays by the usage of struct to store data upto 100
    User users [MAX_USERS];
    PatientRecord patientRecords [MAX_RECORDS];
    Drug inventory [MAX_DRUGS];
    Customer customers [MAX_CUSTOMERS];
    Sale sales [MAX_SALES];

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
    int opt ;

    // Display program header
    header();

    // Main program loop
    while (true)
    {
        if (!isLoggedIn)
        {
            cout<<"check "<<endl;
            // If not logged in, display login / signup options
            opt = mainMenu(isLoggedIn);

            switch (opt)
            {
            case 1:
                signup(users, userCount);
                break;
            case 2:
                if (login(users, userCount))
                {
                    isLoggedIn = true;
                }
                else
                {
                    cout << "Login failed. Please try again. "<<endl;
                }
                break;
            case 3:
                // Exit program
                cout << "Exiting program." << endl;

                //functions called to save the data  after exiting the program
                saveUserData (users, userCount);
                savePatientRecords (patientRecords, recordCount);
                saveInventory (inventory, drugCount);
                saveCustomers (customers, customerCount);
                saveSales (sales, saleCount);
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
            }
        }
        else
        {
            cout<<"check else"<<endl;
            // If loggedIn is true, display main menu options
            int Opt;
            Opt = mainMenu(isLoggedIn);
            switch(Opt)
            {
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
            case 7:
                  {
                    string drugName;
                    cout << "Enter the name of the drug to search: ";
                    cin >> drugName;
                    Drug foundDrug = searchInventory(drugName, inventory, drugCount);
                    if (foundDrug.name != "") {
                        cout << "Drug found in inventory:" << endl;
                        displayDrug(foundDrug);
                    } else {
                        cout << "Drug not found in inventory." << endl;
                    }
                    break;
                  }
            case 8:
                  {
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
            case 9:
                  {
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
                cout << "Logging out "<<endl;
                isLoggedIn = false;
                break;
            case 12:
                // Exit program
                cout << "Exiting program. "<<endl;
                saveUserData(users, userCount);
                savePatientRecords(patientRecords, recordCount);
                saveInventory(inventory, drugCount);
                saveCustomers(customers, customerCount);
                saveSales(sales, saleCount);
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
            }
            cout<<"check out"<<endl;
        }
    }

    return 0;
}

void header()
{

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

int mainMenu(bool isLoggedIn)
{
    int choice ;
    cout << "-------------------------------------------------" << endl;
    cout << "----------------- Main Menu ---------------------" << endl;
    if (!isLoggedIn)
    {
        cout << "1- Signup "<<endl;
        cout << "2- Login "<<endl;
        cout << "3- Exit program "<<endl;
    }
    else
    {
        cout << "1- Add Patient Record "<<endl;
        cout << "2- Display Patient Records "<<endl;
        cout << "3- Manage Customers "<<endl;
        cout << "4- Process Sales "<<endl;
        cout << "5- Generate Report "<<endl;
        cout << "6- Display Inventory "<<endl;
        cout << "7- Search Inventory "<<endl;
        cout << "8- Delete Inventory "<<endl;
        cout << "9- Update Inventory "<<endl;
        cout << "10- Display Customers "<<endl;
        cout << "11- Logout "<<endl;
        cout << "12- Exit program "<<endl;
    }
    cout << "----------------------------------------------- "<<endl;
    cout << "Choose option from the menu = ";
    cin >> choice;

    return choice;
}

void signup(User users[] , int & userCount)
{
    system("cls");

    if (userCount >= MAX_USERS)
    {
        cout << "User limit reached. Can not add more users. " << endl;
        return;
    }

    //Declare the newUser variable name of the type User
    User newUser;
    cout << "Enter username: ";
    cin >> newUser.username;
    cout << "Enter password: ";
    cin >> newUser.password;

    //Store the details of the newUser in the struct of users
    users[userCount++] = newUser;
    cout << "Signup successful! " << endl;
}

bool login(User users[], int userCount)
{
    string username;
    string password;
    cout << "Enter the username: ";
    cin >> username;
    cout << "Enter the password: ";
    cin >> password;

    for (int i = 0; i < userCount; i++)
    {
        if (users[i].username == username && users[i].password == password)
        {
            cout << "Login successful! " << endl;
            return true;
        }
    }
     cout << " !Invalid.Try Again " << endl;
       return false;
}

void saveUserData(const User users[], int userCount)
{
    ofstream outFile;
    outFile.open("users.txt");

    if (!outFile)
    {
        cout << "Error opening file for writing: " << endl;
        return;
    }

    for (int i = 0; i < userCount; ++i)
    {
        outFile << users[i].username << "  " << users[i].password << endl;
    }

    outFile.close();
}

void loadUserData(User users[], int &userCount)
{
    ifstream inFile;
    inFile.open("users.txt");

    if (!inFile)
    {
        cout << "Error for opening file for reading: " << endl;
        return;
    }

    userCount = 0;
    while (inFile >> users[userCount].username >> users[userCount].password)
    {
        userCount++;
    }

    inFile.close();
}

void savePatientRecords(const PatientRecord patientRecords[], int recordCount)
{
    ofstream outFile;
    outFile.open("patient_records.txt");

    if (!outFile)
    {
        cout << "Error in opening the file for writing: " << endl;
        return;
    }

    for (int i = 0; i <  recordCount; ++i)
    {
        outFile << patientRecords[i].name << "  " << patientRecords[i].disease << "  "
                << patientRecords[i].medicine << "   " << patientRecords[i].price << endl;
    }

    outFile.close();
}

void loadPatientRecords(PatientRecord patientRecords[], int &recordCount)
{
    ifstream inFile;
    inFile.open("patient_records.txt");

    if (!inFile)
    {
        cout << "Error in opening file for reading: " << endl;
        return;
    }

    recordCount = 0;
    while (inFile >> patientRecords[recordCount].name >> patientRecords[recordCount].disease
           >> patientRecords[recordCount].medicine >> patientRecords[recordCount].price)
    {
        recordCount++;
    }

    inFile.close();
}

void saveInventory(const Drug inventory[], int drugCount)
{
    ofstream outFile;
    outFile.open("inventory.txt");

    if (!outFile)
    {
        cout << "Error opening file for writing: " << endl;
        return;
    }

    for (int i = 0; i < drugCount; ++i)
    {
        outFile << inventory[i].name << "  " << inventory[i].quantity << "  "
                << inventory[i].price << endl;
    }

    outFile.close();
}

void loadInventory(Drug inventory[], int &drugCount)
{
    ifstream inFile;
    inFile.open("inventory.txt");

    if (!inFile)
    {
        cout << "Error opening file for reading: " << endl;
        return;
    }

    drugCount = 0;
    while (inFile >> inventory[drugCount].name >> inventory[drugCount].quantity >> inventory[drugCount].price)
    {
        drugCount++;
    }

    inFile.close();
}

void saveCustomers(const Customer customers[], int customerCount)
{
    ofstream outFile;
    outFile.open("customers.txt");

    if (!outFile)
    {
        cout << "Error opening file for writing: " << endl;
        return;
    }

    for (int i = 0; i < customerCount; ++i)
    {
        outFile << customers[i].name << "  " << customers[i].address << "  "
                << customers[i].phoneNumber << endl;
    }

    outFile.close();
}

void loadCustomers(Customer customers[], int &customerCount)
{
    ifstream inFile;
    inFile.open("customers.txt");

    if (!inFile)
    {
        cout << "Error opening file for reading: " << endl;
        return;
    }

    customerCount = 0;
    while (inFile >> customers[customerCount].name >> customers[customerCount].address >> customers[customerCount].phoneNumber)
    {
        customerCount++;
    }

    inFile.close();
}

void saveSales(const Sale sales[], int saleCount)
{
    ofstream outFile;
    outFile.open("sales.txt");

    if (!outFile)
    {
        cout << "Error opening file for writing: " << endl;
        return;
    }

    for (int i = 0; i < saleCount; ++i)
    {
        outFile << sales[i].customerName << "  " << sales[i].item << " "
                << sales[i].quantity << "  " << sales[i].totalPrice << endl;
    }

    outFile.close();
}

void loadSales(Sale sales[], int &saleCount)
{
    ifstream inFile;
    inFile.open("sales.txt");

    if (!inFile)
    {
        cout << "Error opening file for reading: " << endl;
        return;
    }

    saleCount = 0;
    while (inFile >> sales[saleCount].customerName >> sales[saleCount].item >> sales[saleCount].quantity >> sales[saleCount].totalPrice)
    {
        saleCount++;
    }

    inFile.close();
}

void addPatientRecord(PatientRecord patientRecords[], int &recordCount)
{
    if (recordCount >= MAX_RECORDS)
    {
        cout << "Record limit reached. Cannot add more records.\n";
        return;
    }

    PatientRecord newRecord;

    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, newRecord.name);
    cout << "Enter disease: ";
    cin >> newRecord.disease;
    cout << "Enter prescribed medicine: ";
    cin >> newRecord.medicine;
    cout << "Enter price: ";
    cin >> newRecord.price;

    patientRecords[recordCount++] = newRecord;
    cout << "Patient record added successfully! " << endl;
}

void displayPatientRecords(const PatientRecord patientRecords[], int recordCount)
{
    if (recordCount == 0)
    {
        cout << "No patient records available.\n";
    }

    cout << "Patient Records: " << endl;
    cout << "----------------------------------------- " << endl;
    for (int i = 0; i < recordCount; ++i)
    {
        cout << "Name: " << patientRecords[i].name << endl;
        cout << "Disease: " << patientRecords[i].disease << endl;
        cout << "Medicine: " << patientRecords[i].medicine << endl;
        cout << "Price: " << patientRecords[i].price << endl;
        cout << "------------------------------------------ " << endl;
    }
}

void manageCustomers(Customer customers[], int &customerCount)
{
    if (customerCount >= MAX_CUSTOMERS)
    {
        cout << "Customer limit reached. Cannot add more customers. " << endl;
        return;
    }

    Customer newCustomer;
    cout << "Enter customer name:  ";
    cin.ignore();
    getline(cin, newCustomer.name);
    cout << "Enter address:  ";
    getline(cin, newCustomer.address);
    cout << "Enter phone number:  ";
    cin >> newCustomer.phoneNumber;

    customers[customerCount++] = newCustomer;
    cout << "Customer added successfully!  " << endl;
}

void processSales(Sale sales[], int &saleCount)
{
    if (saleCount >= MAX_SALES)
    {
        cout << "Sales limit reached. You Cannot add more sales.\n";
        return;
    }

    Sale newSale;
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, newSale.customerName);
    cout << "Enter item name: ";
    cin >> newSale.item;
    cout << "Enter quantity: ";
    cin >> newSale.quantity;
    cout << "Enter total price: ";
    cin >> newSale.totalPrice;

    sales[saleCount++] = newSale;
    cout << "Sale processed successfully! " << endl;
}

void generateReport(const Sale sales[], int saleCount)
{
    if (saleCount == 0)
    {
        cout << "No sales data available.\n";
        return;
    }

    cout << "Sales Report:\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < saleCount; ++i)
    {
        cout << "Customer Name: " << sales[i].customerName << "\n";
        cout << "Item: " << sales[i].item << "\n";
        cout << "Quantity: " << sales[i].quantity << "\n";
        cout << "Total Price: " << sales[i].totalPrice << "\n";
        cout << "-----------------------------------------\n";
    }
}

void displayInventory(const Drug inventory[], int drugCount)
{
    if (drugCount == 0)
    {
        cout << "No inventory data available.\n";
        return;
    }

    cout << "Inventory:\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < drugCount; ++i)
    {
        cout << "Name: " << inventory[i].name << "\n";
        cout << "Quantity: " << inventory[i].quantity << "\n";
        cout << "Price: " << inventory[i].price << "\n";
        cout << "-----------------------------------------\n";
    }
}

void displayCustomers(const Customer customers[], int customerCount)
{
    if (customerCount == 0)
    {
        cout << "No customer data available.\n";
        return;
    }

    cout << "Customers:\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < customerCount; ++i)
    {
        cout << "Name: " << customers[i].name << "\n";
        cout << "Address: " << customers[i].address << "\n";
        cout << "Phone Number: " << customers[i].phoneNumber << "\n";
        cout << "-----------------------------------------\n";
    }
}

void displaySalesSlip(const Sale &sale)
{
    cout << "Sales Slip:\n";
    cout << "-----------------------------------------"<<endl;
    cout << "Customer Name: " << sale.customerName <<endl;
    cout << "Item: " << sale.item <<endl;
    cout << "Quantity: " << sale.quantity  <<endl;
    cout << "Total Price: " << sale.totalPrice <<endl;
    cout << "Total Price of the items " <<(sale.totalPrice * sale.quantity)<<endl;
    cout << "-----------------------------------------"<<endl;
}
Drug searchInventory(string drugName, Drug inventory[], int drugCount)
{
    for (int i = 0; i < drugCount; ++i)
    {
        if (inventory[i].name == drugName)
        {
            return inventory[i];
        }
    }
    // If not found, return an empty Drug object
    return Drug();
}

//bool deleteInventory(string drugName, Drug inventory[], int &drugCount)
//{
//    for (int i = 0; i < drugCount; ++i)
//    {
//        if (inventory[i].name == drugName)
//        {
//            // Shift elements to overwrite the deleted drug
//            for (int j = i; j < drugCount - 1; ++j)
//            {
//                inventory[j] = inventory[j + 1];
//            }
//            drugCount--;
//            return true;
//        }
//    }
//    return false; // Not found
//}

//bool updateInventory (string drugName, int newQuantity, double newPrice, Drug inventory[], int drugCount)
//{
//    for (int i = 0; i < drugCount; ++i)
//    {
//        if (inventory[i].name == drugName)
//        {
//            inventory[i].quantity = newQuantity;
//            inventory[i].price = newPrice;
//            return true;
//        }
//    }
//    return false; // not found
//}
