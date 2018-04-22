#include "Student.h"
#include <iostream>
using namespace std;

//====================================PUBLIC FUNCTIONS========================================
Student::Student() :Person(), m_gpa(0.0){}
//--------------------------------------------------------------------------------------------
Student::Student(const char * const name, int age, const string & ssn, float gpa)
	: Person(name, age, ssn), m_gpa(gpa){}
//--------------------------------------------------------------------------------------------
Student::Student(const Student & s):Person(s), m_gpa(s.m_gpa){}
//--------------------------------------------------------------------------------------------
Student::~Student(){}
//--------------------------------------------------------------------------------------------
void Student::GPA(float gpa)
{
	if (gpa>0)
	{
		m_gpa = gpa;
	}
}
//--------------------------------------------------------------------------------------------
float Student::GPA() const
{
	return m_gpa;
}
//--------------------------------------------------------------------------------------------
string Student::Type(){
	return "Student";
}

//=========================================PROTECTED FUNCTIONS================================
void Student::Read(istream & is)
{
	Person::Read(is);
	if (&is == &cin)
	{
		cout << "Enter the student's GPA: " << flush;
		cin >> m_gpa;
	}

	else
	{
		is >> m_gpa;		
	}
}
//--------------------------------------------------------------------------------------------
void Student::Write(ostream & os) const
{
	Person::Write(os);
	if (&os == &cout)
	{
		cout << "Student's GPA: " << m_gpa << "\n";
	}
	else
	{
		os <<'\n'<< m_gpa;
	}
}





