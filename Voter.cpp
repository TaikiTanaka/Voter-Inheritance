#include "Voter.h"
#include <string>
#include <iostream>
using namespace std;

//====================================PUBLIC FUNCTIONS========================================
Voter::Voter() :Person(), m_partyAffiliation("")
{}
//--------------------------------------------------------------------------------------------
Voter::Voter(const char * name, int age, const std::string &ssn, const std::string &partyAffiliation) 
: Person(name, age, ssn), m_partyAffiliation(partyAffiliation)
{}
//--------------------------------------------------------------------------------------------
Voter::Voter(const Voter &v):Person(v)
{
	m_partyAffiliation = v.m_partyAffiliation;
}
//--------------------------------------------------------------------------------------------
void Voter::partyAffiliation(std::string p)
{
	m_partyAffiliation = p;
}
//--------------------------------------------------------------------------------------------
std::string Voter::partyAffiliation() const
{
	return m_partyAffiliation;
}
//--------------------------------------------------------------------------------------------
string Voter::Type(){
	return "Voter";
}
//=========================================PROTECTED FUNCTIONS================================
void Voter::Read(std::istream & is)
{
	Person::Read(is);
	is.ignore(1000, '\n');
	if (&is == &cin)
	{
		cout << "Enter the party affiliation of the voter: " << flush;
		getline(cin, m_partyAffiliation);
	}
	else
	{
		getline(is, m_partyAffiliation);
	}
}
//--------------------------------------------------------------------------------------------
void Voter::Write(std::ostream &os) const
{
	Person::Write(os);
	if (&os == &cout)
	{
		cout << "Party Affiliation: " << m_partyAffiliation << '\n';
	}
	else
	{
		os << '\n' <<m_partyAffiliation;
	}
}