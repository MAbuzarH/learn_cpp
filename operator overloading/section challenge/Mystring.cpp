#include <iostream>
#include "Mystring.h"
#include <cstring>

using namespace std;

Mystring::Mystring() : str{nullptr}
{ // consrcture with no param;
    str = new char[1];
    str[0] = '\0';
}

// default constrctor
Mystring::Mystring(const char *s) : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
        str = new char[strlen(s) + 1];
    strcpy(str, s);
}

// copy constructor
Mystring::Mystring(const Mystring &source)
{
    cout << "copy constrctor " << endl;
    if (source.str == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
        str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

// move constructor
Mystring::Mystring(Mystring &&source) noexcept
{
    cout << "move constrctor " << endl;
    this->str = source.str;
    source.str = nullptr;
}

int Mystring::get_length() const
{
    size_t len = strlen(str);
    return len;
}

void Mystring::display() const
{
    cout << str << " : " << get_length() << endl;
}

void Mystring::set_str(const char *s)
{
    delete[] str;
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

const char *Mystring::get_str() const
{
    return str;
}

// opreator overloading

// copy assignment operator
Mystring &Mystring::operator=(const Mystring &rhs)
{
    cout << " copy assignment operator called" << endl;
    if (this == &rhs)
        return *this;                    // check wether it is self defined
    delete[] this->str;                  // delete memory where it was pointing to
    str = new char[strlen(rhs.str) + 1]; // grant the size

    strcpy(str, rhs.str);

    return *this;
}

// move assignment operator
Mystring &Mystring::operator=(Mystring &&rhs)
{
    cout << " move assignment operator called" << endl;
    if (this == &rhs)
        return *this; // check wether it is self defined
    delete[] this->str;
    this->str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

Mystring::~Mystring()
{
    delete[] this->str;
}

// friend functions and operators overloads

// stream inserstion operator
ostream &operator<<(ostream &os, const Mystring &obj)
{
    if (obj.str != nullptr)
    {
        os << obj.str;
    }

    return os;
}

// stream exserstion operator
istream &operator>>(istream &in, Mystring &obj)
{
    char *buff = new char[1000];
    in >> buff;
    delete[] obj.str;
    obj.str = new char[strlen(buff) + 1];
    strcpy(obj.str, buff);
    return in;
}

// opreator- overload to convert string to lower case
Mystring Mystring::operator-() const
{
    char *buff = new char[strlen(str) + 1];
    strcpy(buff, str);
    for (int i = 0; i < strlen(str); i++)
    {
        buff[i] = tolower(buff[i]);
    }
    Mystring result{buff};
    delete[] buff;
    return result;
}

// operator+ overload  to concatinate
Mystring Mystring::operator+(const Mystring &obj) const
{
    size_t len = strlen(obj.str) + strlen(str) + 1;
    char *buff = new char[len];
    strcpy(buff, str);
    strcat(buff, obj.str);
    Mystring temp(buff);
    delete[] buff;
    return temp;
}

bool Mystring::operator==(const Mystring &rhs) const
{
    return (strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring &rhs) const
{
    return (strcmp(str, rhs.str) != 0);
}

bool Mystring::operator>(const Mystring &rhs) const
{
    return (strcmp(str, rhs.str) > 0);
}

bool Mystring::operator<(const Mystring &rhs) const
{
    return (strcmp(str, rhs.str) < 0);
}

Mystring &Mystring::operator++() // pree increment
{

    for (size_t i = 0; i < strlen(str); i++)
    {
        str[i] = toupper(str[i]);
    }
    return *this;
}

Mystring Mystring::operator++(int)
{
    Mystring temp{*this};

    operator++();

    return temp;
}

Mystring Mystring::operator*(int n) const
{
    if (n <= 0)
    {
        return Mystring("");
    }

    size_t len = strlen(str) * n + 1;
    char *buff = new char[len];
    buff[0] = '\0';

    for (int i = 0; i < n; i++)
    {
        strcat(buff, str);
    }
    Mystring temp(buff);
    delete[] buff;
    return temp;

    // optimal solution if we overlodaad + operator;
    // Mystring temp;
    // for (int i = 0; i < n; i++)
    // {
    //     temp = temp + *this;
    // }
    // return temp;
}

// Mystring Mystring::operator*(int n) const
// {
//     if (n <= 0)
//     {
//         return Mystring(""); // Return an empty string if n is 0 or negative
//     }

//     size_t len = strlen(str) * n + 1; // Calculate the length needed
//     char *buff = new char[len];       // Allocate memory for the new string

//     buff[0] = '\0'; // Initialize the buffer as an empty string

//     for (int i = 0; i < n; i++)
//     {
//         strcat(buff, str); // Concatenate the string n times
//     }

//     Mystring temp(buff); // Create a new Mystring object with the repeated string
//     delete[] buff;       // Free the temporary buffer memory
//     return temp;         // Return the new Mystring object
// }

Mystring &Mystring::operator+=(const Mystring &obj)
{
    /* this is my solution
     size_t len = strlen(obj.str) + strlen(str) + 1;
     char *buff = new char[len];

     strcpy(buff, str);
     strcat(buff, obj.str);

     delete[] str;
     str = buff;
     delete[] buff;
     return *this;
     */
    // optimize solution
    *this = *this + obj.str; // this is used when we overlodad + opreator
    return *this;
}