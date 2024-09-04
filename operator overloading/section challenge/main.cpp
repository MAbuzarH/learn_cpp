#include <iostream>
#include <cstring>
#include "Mystring.h"
#include "Mystring.cpp"

using namespace std;

int main()
{

    
    // 1. Test Default Constructor
    cout << "Testing Default Constructor:" << endl;
    Mystring str1;
    str1.display(); // Should print ": 0" because the string is empty

    // 2. Test Parameterized Constructor
    cout << "\nTesting Parameterized Constructor:" << endl;
    Mystring str2("Hello");
    str2.display(); // Should print "Hello: 5"

    // 3. Test Copy Constructor
    cout << "\nTesting Copy Constructor:" << endl;
    Mystring str3 = str2; // Copy constructor
    str3.display();       // Should print "Hello: 5"

    // 4. Test Move Constructor
    cout << "\nTesting Move Constructor:" << endl;
    Mystring str4 = Mystring("World"); // Move constructor
    str4.display();                    // Should print "World: 5"
    str4.display();                    // Print again to ensure str4 is intact

    // 5. Test Copy Assignment Operator
    cout << "\nTesting Copy Assignment Operator:" << endl;
    Mystring str5;
    str5 = str2;    // Copy assignment operator
    str5.display(); // Should print "Hello: 5"

    // 6. Test Move Assignment Operator
    cout << "\nTesting Move Assignment Operator:" << endl;
    Mystring str6;
    str6 = Mystring("Move"); // Move assignment operator
    str6.display();          // Should print "Move: 4"

    // 7. Test set_str Method
    cout << "\nTesting set_str Method:" << endl;
    str1.set_str("New String");
    str1.display(); // Should print "New String: 10"

    // 8. Test get_str Method
    cout << "\nTesting get_str Method:" << endl;
    const char *cstr = str2.get_str();
    cout << "str2 content: " << cstr << endl; // Should print "Hello"

    // 9. Test Destructor (implicitly called at the end of the scope)
    cout << "\nTesting Destructor (will be called automatically):" << endl;

    return 0; // Destructors will be called here for all objects
}