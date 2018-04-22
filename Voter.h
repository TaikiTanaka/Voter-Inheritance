#pragma once
#ifndef VOTER_H
#define VOTER_H
#include "Person.h"
#include <string>

class Voter : public virtual Person
{
private:
	std::string m_partyAffiliation;
protected:
	virtual void Read(std::istream & is);
	virtual void Write(std::ostream &os) const;
public:
	Voter();
	Voter(const char * name, int age, const std::string &ssn, const std::string &partyAffiliation);
	Voter(const Voter &v);
	void partyAffiliation(std::string p);
	std::string partyAffiliation() const;
	virtual std::string Type();
};
#endif