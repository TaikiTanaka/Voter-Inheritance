#pragma once
#ifndef STUDENTVOTER_H
#define STUDENTVOTER_H
#include "Student.h"
#include "Voter.h"
#include <iostream>

class StudentVoter : public Student,public Voter
{
protected:
	virtual void Read(std::istream &is);
	virtual void Write(std::ostream &os) const;
public:
	StudentVoter();
	StudentVoter(const char * const name,const int & age, const std::string & ssn, float gpa, 
		const std::string &partyAffiliation);
	StudentVoter(const StudentVoter & stv);
	~StudentVoter();
	virtual std::string Type();
};
#endif