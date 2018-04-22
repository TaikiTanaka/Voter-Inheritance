#include "Person.h"
#include <iostream>
using namespace std;


//===================================MEMBER FUNCTIONS========================================
Person::Person() :m_age(0), m_ssn(""){
	m_name = new char[5];
	for (size_t i = 0; i < 4; i++)
	{
		m_name[i] = '*';
	}
	m_name[4] = '\0';
}
//--------------------------------------------------------------------------------------------
Person::Person(const char * const name, 
const int & age, const string & ssn) : m_age(age), m_ssn(ssn)
{
	m_name = new char[(int)strlen(name) + 1];
	for (int i = 0; i < (int)strlen(name) + 1; i++)
	{
		m_name[i] = name[i];
	}
}
//--------------------------------------------------------------------------------------------
Person::Person(const Person & object):m_age(object.m_age), m_ssn(object.m_ssn){
	m_name = new char[(int)strlen(object.m_name) + 1];
	for (int i = 0; i < (int)strlen(object.m_name) + 1; i++)
	{
		m_name[i] = object.m_name[i];
	}
}
//--------------------------------------------------------------------------------------------
Person::~Person()
{
	delete [] m_name;
}
//--------------------------------------------------------------------------------------------
void Person::Read(istream & is)
{
	string name;
	if (&is == &cin)
	{
		cout << "Please enter the student's name: ";
		getline(cin, name);
		cout << "Please enter the age: ";
		cin >> m_age;

		cin.sync();
		cout << "Please enter the social security number (with hyphens): ";
		cin >> m_ssn;
	}

	else
	{
		getline(is, name);
		if (!is)
			return;
		if (name.length() == 0)
		{
			getline(is, name);
		}
		is >> m_age;
		is >> m_ssn;
	}

	delete[] m_name;
	m_name = new char[name.length() + 1];
	for (size_t i = 0; i < name.length(); i++)
	{
		m_name[i] = name[i];
	}
	m_name[name.length()] = '\0';
}
//--------------------------------------------------------------------------------------------
void Person::Write(ostream &os) const
{
	unsigned int size = (unsigned int)strlen(m_name);
	if (&os == &cout)
	{
		cout << "Name: ";
		for (size_t i = 0; i < size; i++)
		{
			cout << m_name[i];
		}
		cout << "\n" << "Age: " << m_age << '\n'
			 << "SSN: " << m_ssn << "\n";
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			os << m_name[i];
		}
		os << '\n' << m_age << '\n' << m_ssn;
	}
}
//--------------------------------------------------------------------------------------------
void Person::Age(int age){
	if (age > 1)
	{
		m_age = age;
	}
}
//--------------------------------------------------------------------------------------------
int Person::Age()const{
	return m_age;
}
//--------------------------------------------------------------------------------------------
void Person::SSN(string ssn){
	m_ssn = ssn;
}
//--------------------------------------------------------------------------------------------
string Person::SSN()const{
	return m_ssn;
}
//--------------------------------------------------------------------------------------------
void Person::Name(const char * const name){
	delete m_name;
	m_name = new char[(int)strlen(name) + 1];
	for (int i = 0; i < (int)strlen(name) + 1; i++)
	{
		m_name[i] = name[i];
	}
}
//--------------------------------------------------------------------------------------------
string Person::Name()const{
	return string(m_name);
}
//--------------------------------------------------------------------------------------------
Person & Person::operator =(const Person & p)
{
	if (this != &p)
	{
		m_age = p.m_age;
		m_ssn = p.m_ssn;
		delete[] m_name;
		unsigned int size = (unsigned int)strlen(p.m_name);
		m_name = new char[size + 1];
		for (size_t i = 0; i < size + 1; i++)
		{
			m_name[i] = p.m_name[i];
		}
	}
	return *this;
}
//---------------------------------------------------------------------
string Person:: Type(){
	return "Person";
}

//============================================FRIEND FUNCTIONS================================

ostream& operator << (ostream & os, const Person & object)
{
	object.Write(os);
	return os;
}
//--------------------------------------------------------------------------------------------
istream& operator >> (std::istream & is, Person & object)
{
	object.Read(is);
	return is;
}

