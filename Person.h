#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class Person
{

private:
	char * m_name;
	int m_age;
	std::string m_ssn;
protected:
	virtual void Read(std::istream & is);
	virtual void Write(std::ostream &os) const;
public:
	Person();
	Person(const char * const name, const int & age, const std::string & ssn);
	Person(const Person & object);
	virtual ~Person();
	void Age(int age);
	int Age()const;
	void SSN(std::string ssn);
	std::string SSN()const;
	void Name(const char * const name);
	std::string Name()const;
	friend std::ostream& operator << (std::ostream & os, const Person & object);
	friend std::istream& operator >> (std::istream & is, Person & object);
	Person & operator =(const Person & p);
	virtual std::string Type();
};
#endif