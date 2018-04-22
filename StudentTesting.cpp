/*
Name: Taiki Tanaka
Class: CSCI 30, Advanced Programming in C++
Section: 0124
Assignment Number: 1
File(s): TanakaTprgm1.cpp
Due Date:
--------------------------------------------------------------------------------------
I, Taiki Tanaka, pledge that this is my own independent work, which conforms to
generally accepted guidelines of academic honesty.
--------------------------------------------------------------------------------------
*/

#include "Student.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void StudentTesting()
{
	//***** Testing Constructors *****
	Student s1, s2("Taiki Tanaka", 21, "752-52-3421", 3.8f);
	cout << "***** Check out the constructors, output operator for monitor *****\n";
	cout << "\nAfter:"
		<< "\n      Student s1, s2(\"Taiki Tanaka\", 21, \"752 - 52 - 3421\", 3.8)"
		<< "\ns1 follows:\n" << s1
		<< "\ns2 follows:\n" << s2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	
	Student s3(s2);
	cout << "\nAfter:"
		<< "\n      Student s3(s2);"
		<< "\ns2 follows:\n" << s2
		<< "\ns3 follows:\n" << s3
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

	s2.Name("Hiroto Miyazawa");
	cout << "\nAfter:"
		<< "\n      s2.Name(\"Hiroto Miyazawa\");"
		<< "\ns2 follows:\n" << s2
		<< "\ns3 follows:\n" << s3
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");


	//----------------------------------------------------------------------------------------
	//"***** Testing the accessors and mutators *****
	s1.Name("John Smith");
	s1.Age(18);
	s1.GPA(4.0f);
	cout << left << fixed << setprecision(1);
	cout << "***** Testing the accessors and mutators *****"
		<< "\n\nAfter:"
		<< "\n      s1.Name(\"John Smith\");"
		<< "\n      s1.Age(54);"
		<< "\n      s1.GPA(4.0);"
		<< "\ns1.Name() = " << s1.Name()
		<< "\ns1.Age() = " << s1.Age()
		<< "\ns1.GPA() = " << s1.GPA()
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//----------------------------------------------------------------------------------------
	//   ***** Testing reading from the keyboard *****
	cout << "***** Testing reading from the keyboard *****"
		<< "\n\nEnter data for Student s1:\n";
	cin >> s1;
	cout << "\nAfter:"
		<< "\n      cin >> s1;"
		<< "\ns1 follows:\n" << s1 << "\n\nHit enter to continue: " << flush;
	cin.get();
	cin.get();
	system("cls");

	//----------------------------------------------------------------------------------------
	//   ***** Testing File I/O Consistency *****
	cout << "***** Testing File I/O Consistency *****";

	string outputFileName;
	ofstream outputFile;

	cout << "\n\nEnter the the name of an output file for s1, s2, and s3: " << flush;
	getline(cin, outputFileName);
	outputFile.open(outputFileName);
	if (outputFile.fail())
	{
		cout << "\n\n***** ERROR. There was a problem opening the output file."
			<< "\n\nHit enter to exit the program: " << flush;
		cin.get();
		exit(1);
	}
	outputFile << s1 << '\n' << s2 << '\n' << s3;
	outputFile.close();

	ifstream inputFile;
	Student s1c, s2c, s3c;

	inputFile.open(outputFileName);

	inputFile >> s1c >> s2c >> s3c;
	inputFile.close();
	cout << "\nAfter:"
		<< "\n      outputFile << s1 << '\\n' << s2 << '\\n' << s3;"
		<< "\n      outputFile.close();"
		<< "\n      ifstream inputFile;"
		<< "\n      Vehicle s1c, s2c, s3c;"
		<< "\n      inputFile.open(outputFileName);"
		<< "\n      inputFile >> s1c >> s2c >> s3c;"
		<< "\ns1 follows:\n" << s1
		<< "\ns1c follows:\n" << s1c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cout << "\ns2 follows:\n" << s2
		<< "\ns2c follows:\n" << s2c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cout << "\ns3 follows:\n" << s3
		<< "\ns3c follows:\n" << s3c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//----------------------------------------------------------------------------------------
	//   ***** Making Sure Output Operator and Accessors Work With const Objects *****
	const Student cs("Mary Jones",19, "644-23-1243", 3.3f);       

	cout << "***** Making Sure Output Operator and Accessors Work With const Objects *****"
		<< "\n\nAfter:"
		<< "\n      const Student cs(\"Mary Jones\",19, \"644 - 23 - 1243\", 3.3);"
		<< "\ncs follows:\n" << cs
		<< "\n\ncs.Name() = " << cs.Name()
		<< "\ncs.Age() = " << cs.Age()
		<< "\ncs.SSN() = " << cs.SSN()
		<< "\ncs.GPA() = " << cs.GPA()
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//----------------------------------------------------------------------------------------
	//   ***** Verifying Assignment Operator Works Properly *****
	cout << "***** Verifying Assignment Operator Works Properly *****"
		<< "\n\nEnter data for s1:\n";
		cin >> s1;
		s2 = s1;
		cout << "\nAfter:"
		<< "\n      cin >> s1;"
		<< "\n      s2 = s1;"
		<< "\ns1 follows:\n" << s1 << "\ns2 follows:\n" << s2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cin.get();

	s1.Name("Leanne Fukushima");
	s1.Age(23);
	s1.SSN("644-23-1234");
	s1.GPA(2.6f);

	cout << "\nAfter:"
		<< "\n      s1.Name(\"Leanne Fukushima\");"
		<< "\n      s1.Age(23);"
		<< "\n      s1.SSN(\"644.23.1234\");"
		<< "\n      s1.GPA(2.6);"
		<< "\ns1 follows:\n" << s1 << "\ns2 follows:\n" << s2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

}