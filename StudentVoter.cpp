#include "StudentVoter.h"
#include <iostream>
#include <string>
using namespace std;

//====================================PUBLIC FUNCTIONS========================================
StudentVoter::StudentVoter(): Student(), Voter(), Person(){}
//--------------------------------------------------------------------------------------------
StudentVoter::StudentVoter(const char * const name, const int & age, const string & ssn,
	float gpa,const string &partyAffiliation) : Student(name, age, ssn, gpa), 
	Voter(name, age, ssn, partyAffiliation), Person(name,age,ssn){}
//--------------------------------------------------------------------------------------------
StudentVoter::StudentVoter(const StudentVoter & stv): Student(stv), Voter(stv), Person(stv){}
//--------------------------------------------------------------------------------------------
StudentVoter::~StudentVoter(){}
//--------------------------------------------------------------------------------------------
string StudentVoter::Type(){
	return "Student Voter";
}
//=========================================PROTECTED FUNCTIONS================================
void StudentVoter::Read(std::istream &is)
{
	string partyAffiliation;
	Student::Read(is);
	if (&is == &cin)
	{
		cin.ignore(1000, '\n');
		cout << "Enter the party affiliation of the voter: " << flush;
		getline(cin, partyAffiliation);
	}
	else
	{
		is.ignore(1000, '\n');
		getline(is, partyAffiliation);
	}
	Voter::partyAffiliation(partyAffiliation);
}
//--------------------------------------------------------------------------------------------
void StudentVoter::Write(std::ostream &os) const
{
	Student::Write(os);
	if (&os == &cout)
	{
		cout << "Party Affiliation: " << partyAffiliation() << "\n";
	}
	else
	{
		os << '\n' << partyAffiliation();
	}
}