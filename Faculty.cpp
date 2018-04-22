#include"Faculty.h"
#include <string>
#include<iostream>
using namespace std;

//====================================PUBLIC FUNCTIONS========================================
Faculty::Faculty() : Person(), m_numberOfDegrees(0), m_degrees(nullptr){}
//--------------------------------------------------------------------------------------------
Faculty::Faculty(char * name, int age, const string & ssn, int numberOfDegrees, const string * 
degrees): Person(name, age, ssn), m_numberOfDegrees(numberOfDegrees)
{
	m_degrees = new string[numberOfDegrees];
	for (size_t i = 0; i < (size_t)numberOfDegrees; i++)
	{
		m_degrees[i] = degrees[i];
	}
}
//--------------------------------------------------------------------------------------------
Faculty::Faculty(const Faculty & f) : Person(f)
{
	m_numberOfDegrees = f.m_numberOfDegrees;
	delete [] m_degrees;
	m_degrees = new string[m_numberOfDegrees];
	for (size_t i = 0; i < (size_t)m_numberOfDegrees; i++)
	{
		m_degrees[i] = f.m_degrees[i];
	}
}
//--------------------------------------------------------------------------------------------
Faculty::~Faculty()
{
	delete[] m_degrees;
}
//--------------------------------------------------------------------------------------------
int Faculty::numberOfDegrees() const
{
	return m_numberOfDegrees;
}
//--------------------------------------------------------------------------------------------
void Faculty::degrees(string * & sptr) const //Getter
{
	delete [] sptr;
	sptr = new string[m_numberOfDegrees];
	for (size_t i = 0; i < (size_t)m_numberOfDegrees; i++)
	{
		sptr[i] = m_degrees[i];
	}
}
//--------------------------------------------------------------------------------------------
void Faculty::degrees(int num, const string * sptr) //Mutator
{
	delete[] m_degrees;
	m_numberOfDegrees = num;
	m_degrees = new string[num];
	for (size_t i = 0; i < (size_t)m_numberOfDegrees; i++)
	{
		m_degrees[i] = sptr[i];
	}
}
//--------------------------------------------------------------------------------------------
Faculty & Faculty::operator=(const Faculty & fac)
{
	Person::operator=(fac);
	m_numberOfDegrees = fac.m_numberOfDegrees;
	delete [] m_degrees;
	m_degrees = new string[m_numberOfDegrees];
	for (size_t i = 0; i < (size_t)m_numberOfDegrees; i++)
	{
		m_degrees[i] = fac.m_degrees[i];
	}
	return *this;
}
//---------------------------------------------------------------------
string Faculty::Type(){
	return "Faculty";
}

//=========================================PROTECTED FUNCTIONS================================
void Faculty::Write(std::ostream & os) const
{
	Person::Write(os);
	if (&os == &cout)
	{
		cout << "Number of degrees: " << m_numberOfDegrees << "\n";
		for (size_t i = 0; i < (size_t)m_numberOfDegrees; i++)
		{
			cout << "Degree " << i << ": "<<m_degrees[i] << "\n";
		}
	}

	else
	{
		os << '\n' <<m_numberOfDegrees;
		for (size_t i = 0; i < static_cast<size_t>(m_numberOfDegrees); i++)
		{
			os << '\n' << m_degrees[i];
		}
	}
}
//--------------------------------------------------------------------------------------------
void Faculty::Read(std::istream & is)
{
	Person::Read(is);
	delete[] m_degrees;

	if (&is == &cin)
	{
		cout << "Enter the number of degrees: " << flush;
		cin >> m_numberOfDegrees;
		cin.ignore(1000, '\n');
		m_degrees = new string[m_numberOfDegrees];
		for (size_t i = 0; i < (size_t)m_numberOfDegrees; i++)
		{
			cout << "Enter the degree: " << flush;
			getline(cin, m_degrees[i]);
		}
	}

	else
	{
		string tempDegree;
		is >> m_numberOfDegrees;
		is.ignore(1000, '\n');
		m_degrees = new string[m_numberOfDegrees];
		for (size_t i = 0; i < (size_t)m_numberOfDegrees; i++)
		{
			getline(is, tempDegree);
			m_degrees[i] = tempDegree;
		}
	}
}
//--------------------------------------------------------------------------------------------
