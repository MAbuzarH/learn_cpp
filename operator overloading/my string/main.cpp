#include <iostream>
#include <vector>
#include "Mystring.h"
#include "Mystring.cpp"
using namespace std;

int main()
{
   Mystring a = "HELLO";
   Mystring b = "ali";
   Mystring c{"HELLO"};
   Mystring d;
   cout << "enter a string \n";
   cin >> d;
   // cout << "three string are : " << a << " " << b << " " << c << " " << d << endl;
   cout << d;
   // b = a;
   // b = "This is a test";
   // b.display();
   //  b = -a;
   // b.display();
   // if (a == b)
   // {
   //    cout << "hahah \n";
   // }
   // else
   // {
   //    // d = a + " " + b + " how are you?";
   //    // d.display();
   // }
   // Mystring a = "Hello"; // overloaded constructor
   // Mystring b;           // no-args contructor
   // b = a;                // copy assignment                                              // b.operator=(a)
   // b = "This is a test"; // b.operator=("This is a test");

   // Mystring empty;          // no-args constructor
   // Mystring larry("Larry"); // overloaded constructor
   // Mystring stooge = larry; // copy constructor
   // Mystring stooges;        // no-args constructor

   // empty = stooge; // copy assignment operator

   // empty.display();  // Larry : 5
   // larry.display();  // Larry : 5
   // stooge.display(); // Larry : 5
   // empty.display();  // Larry : 5

   // stooges = "Larry, Moe, and Curly";
   // stooges.display(); // Larry, Moe, and Curly : 21

   // vector<Mystring> stooges_vec;
   // stooges_vec.push_back("Larry");
   // stooges_vec.push_back("Moe");
   // stooges_vec.push_back("Curly");

   // cout << "=== Loop 1 ==================" << endl;
   // for (size_t i = 0; i < stooges_vec.size(); i++)
   //    stooges_vec[i].display(); // Larry
   //                              // Moe
   //                              // Curly
   // cout << "=== Loop 2 ==================" << endl;
   // for (size_t i = 0; i < stooges_vec.size(); i++)
   //    stooges_vec[i] = "Changed"; // copy assignment

   // cout << "=== Loop 3 ================" << endl;
   // for (size_t i = 0; i < stooges_vec.size(); i++)
   //    stooges_vec[i].display(); // Changed
   //                              // Changed

   //	Mystring empty;
   //	Mystring larry("Larry");
   //	Mystring soogy = larry;
   //	empty.display();
   //	larry.display();
   //	soogy.display();
   return 0;
}
