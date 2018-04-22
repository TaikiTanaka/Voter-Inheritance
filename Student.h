#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <string>
#include <iostream>

class Student : public virtual Person
{
private:
	float m_gpa;
protected:
	virtual void Read(std::istream & is);
	virtual void Write(std::ostream &os) const;
public:
	Student();
	Student(const char * const name, int age, const std::string & ssn, float gpa);
	Student(const Student & s);
	~Student();
	void GPA(float gpa);
	float GPA() const;
	virtual std::string Type();
};

#endif