#pragma once
#ifndef FACULTY_H
#define FACULTY_H
#include "Person.h"
#include <iostream>
#include <string>

class Faculty : public Person
{
private:
	int m_numberOfDegrees;
	std::string * m_degrees;
protected:
	virtual void Write(std::ostream & os) const;
	virtual void Read(std::istream & is);
public:
	Faculty();
	Faculty(char * name, int age, const std::string & ssn, int numberOfDegrees,
		const std::string * degrees);
	Faculty(const Faculty & f);
	~Faculty();
	void degrees(std::string * & sptr) const;
	int numberOfDegrees() const;
	void degrees(int num, const std::string * sptr);
	Faculty & operator = (const Faculty &fac);
	virtual std::string Type();
};
#endif