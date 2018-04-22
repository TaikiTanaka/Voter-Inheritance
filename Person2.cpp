#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() : m_age(0), m_ssn("")
{
	m_name = new char[5];
	for (size_t i = 0; i < 5; i++)
	{
		m_name[i] = '*';
	}


}