#include <iostream>
#include <cstring>

#include "Mystring.h"

using namespace std;

// no argument constrcture
Mystring::Mystring() : str{NULL}
{
	str = new char[1];
	*str = '\0';
}

// overloaded constrcture
Mystring::Mystring(const char *s) : str{NULL}
{
	if (s == NULL)
	{
		str = new char[1];
		*str = '\0';
	}
	else
	{
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
}

// copy constrcture
Mystring::Mystring(const Mystring &source)
	: str{NULL}
{
	cout << "copy constr \n";
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
}

// move constructor
Mystring::Mystring(Mystring &&source)
{
	this->str = source.str;
	source.str = NULL;
	cout << "move constructor \n";
}

Mystring::~Mystring()
{
	delete[] str;
}

void Mystring::display() const
{
	cout << str << ":" << get_length() << endl;
}

int Mystring::get_length() const
{
	return strlen(str);
}

const char *Mystring::get_str() const
{
	return str;
}

/*
// non member function opreator overloading
bool operator==(const Mystring &lhs, const Mystring &rhs)
{
	return (strcmp(lhs.str, rhs.str) == 0);
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
	size_t l = strlen(lhs.str) + strlen(rhs.str) + 1;
	char *buf;
	buf = new char[l];
	strcpy(buf, lhs.str);
	strcat(buf, lhs.str);
	Mystring result = buf;

	delete[] buf;
	return result;
}

Mystring operator-(const Mystring &obj)
{
	char *buf = new char[strlen(obj.str) + 1];
	strcpy(buf, obj.str);
	for (int i = 0; i < strlen(buf); i++)
	{
		buf[i] = tolower(buf[i]);
	}
	Mystring result = buf;
	delete[] buf;
	return result;
}
*/
// class name :: current obj -- overloading operator -- what we are assining
// // deep copy assignment
// it works with l value refrence ;

Mystring &Mystring::operator=(const Mystring &rhs)
{
	cout << " copy assignment " << endl;
	if (this == &rhs)
	{
		return *this;
	}
	delete[] this->str;
	this->str = new char[strlen(rhs.str) + 1];
	strcpy(this->str, rhs.str);
	return *this;
}

// move assignment operator
// work with r value refrence;

Mystring &Mystring::operator=(Mystring &&rhs)
{

	cout << "using move assignment operator \n";

	if (this == &rhs) // step 1 self assignment check
		return *this; // if so then return

	delete[] this->str; // step 2 delete this->str because save us from memory
	// leakege

	strcpy(this->str, rhs.str); // step 4 steal from source and copy to destination

	rhs.str = NULL; // null the source because when distrcture is called it not
	// disroy orignal

	return *this;
}

Mystring Mystring::operator-() const
{
	cout << " -() called" << endl;
	char *buf;
	buf = new char[strlen(str) + 1];
	strcpy(buf, str);
	for (int i = 0; i < strlen(str); i++)
	{
		buf[i] = tolower(buf[i]);
	}
	Mystring temp = buf;
	delete[] buf;
	return temp;
}

bool Mystring::operator==(const Mystring &rhs) const
{
	if (strcmp(this->str, rhs.str) == 0)
	{
		return true;
	}
	else
		return false;
}

Mystring Mystring::operator+(const Mystring &rhs) const
{
	char *bef;
	size_t len = strlen(rhs.str) + strlen(str) + 1;
	bef = new char[len];
	strcpy(bef, str);
	strcat(bef, rhs.str);
	Mystring temp = bef;
	delete[] bef;
	return temp;
}

// streem insertion opreator
ostream &operator<<(ostream &os, const Mystring &obj)
{
	os << obj.str;
	return os;
}
// stream extraction opreator
istream &operator>>(istream &in, Mystring &obj)
{
	char *buf = new char[1000];
	in >> buf;
	obj = Mystring{buf};
	delete[] buf;
	return in;
}
