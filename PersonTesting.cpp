/*
Name: Taiki Tanaka
Class: CSCI 30, Advanced Programming in C++
Section: 0124
Assignment Number: 1
File(s): TanakaTprgm1.cpp
Due Date:
//--------------------------------------------------------------------------------------------
I, Taiki Tanaka, pledge that this is my own independent work, which conforms to
generally accepted guidelines of academic honesty.
//--------------------------------------------------------------------------------------------
*/

#include "Person.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void PersonTesting()
{
	//***** Testing Constructors *****
	Person p1, p2("Taiki Tanaka", 21, "666-66-6666");
	cout << "***** Check out the constructors, output operator for monitor *****\n";
	cout << "\nAfter:"
		<< "\n     Person p1, p2(\"Taiki Tanaka\", 21, \"666 - 66 - 6666\")"
		<< "\np1 follows:\n" << p1
		<< "\np2 follows:\n" << p2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

	Person p3(p2);
	cout << "\nAfter:"
		<< "\n      Person p3(p2);"
		<< "\np2 follows:\n" << p2
		<< "\np3 follows:\n" << p3
		<< "\n\nHit enter to continue: " << flush;
	cin.get();


	cout << "Printing the current values in p2" << "\n";
	cout << "Name: " << p2.Name() << "\n";
	cout << "Age: " << p2.Age() << "\n";
	cout << "SSN: " << p2.SSN() << "\n";

	p2.Name("Hiroto Miyazawa");
	cout << "\nAfter:"
		<< "\n      p2.Name(\"Hiroto Miyazawa\")"
		<< "\np2 follows:\n" << p2
		<< "\np3 follows:\n" << p3
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");


	//--------------------------------------------------------------------------------------------
	//***** Testing the accessors and mutators *****
	p1.Age(45);
	p1.Name("Maya Tanaka");
	cout << "***** Testing the accessors and mutators *****"
		<< "\n\nAfter:"
		<< "\n      p1.Age(45);"
		<< "\n      p1.Name(\"Maya Tanaka\");"
		<< "\np1.Name() = " << p1.Name()
		<< "\np1.Age() = " << p1.Age()
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//--------------------------------------------------------------------------------------------
	//***** Testing reading from the keyboard *****
	cout << "***** Testing reading from the keyboard *****"
		<< "\n\nEnter data for Person p1:\n";
	cin >> p1;
	cout << "\nAfter:"
		<< "\n      cin >> p1;"
		<< "\np1 follows:\n" << p1 << "\n\nHit enter to continue: "
		<< flush;
	cin.get();
	cin.get();
	system("cls");

	//--------------------------------------------------------------------------------------------
	//   ***** Testing File I/O Consistency *****
	cout << "***** Testing File I/O Consistency *****";

	string outputFileName;
	ofstream outputFile;

	cout << "\n\nEnter the the name of an output file for p1, p2, and p3: " << flush;
	getline(cin, outputFileName);
	outputFile.open(outputFileName);
	if (outputFile.fail()) 
	{
		cout << "\n\n***** ERROR. There was a problem opening the output file."
			<< "\n\nHit enter to exit the program: " << flush;
		cin.get();
		exit(1);
	}
	outputFile << p1 << '\n' << p2 << '\n' << p3;
	outputFile.close();

	ifstream inputFile;
	Person p1c, p2c, p3c;

	inputFile.open(outputFileName);

	inputFile >> p1c >> p2c >> p3c;
	inputFile.close();
	cout << "\nAfter:"
		<< "\n      outputFile << p1 << '\\n' << p2 << '\\n' << p3;"
		<< "\n      outputFile.close();"
		<< "\n      ifstream inputFile;"
		<< "\n      Vehicle p1c, p2c, p3c;"
		<< "\n      inputFile.open(outputFileName);"
		<< "\n      inputFile >> p1c >> p2c >> p3c;"
		<< "\np1 follows:\n" << p1
		<< "\np1c follows:\n" << p1c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cout << "\np2 follows:\n" << p2
		<< "\np2c follows:\n" << p2c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cout << "\np3 follows:\n" << p3
		<< "\np3c follows:\n" << p3c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//--------------------------------------------------------------------------------------------
	//   ***** Making Sure Output Operator and Accessors Work With const Objects *****
	const Person cp("Andrew Ryan", 67, "534-23-4324");      

	cout << "***** Making Sure Output Operator and Accessors Work With const Objects *****"
		<< "\n\nAfter:"
		<< "\n      const Person cp(\"Andrew Ryan\",67, \"534 - 23 - 4324\");"
		<< "\ncp follows:\n" << cp
		<< "\n\ncp.Name() = " << cp.Name()
		<< "\ncp.Age() = " << cp.Age()
		<< "\ncp.SSN() = " << cp.SSN()
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//--------------------------------------------------------------------------------------------
	//   ***** Verifying Assignment Operator Works Properly *****
	cout << "***** Verifying Assignment Operator Works Properly *****"
		<< "\n\nEnter data for p1:\n";
	cin >> p1;
	p2 = p1;
	cout << "\nAfter:"
		<< "\n      cin >> p1;"
		<< "\n      p2 = p1;"
		<< "\np1 follows:\n" << p1 << "\np2 follows:\n" << p2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cin.get();

	p1.Name("Leo Zee");
	p1.Age(98);
	p1.SSN("842-85-5342");
	cout << "\nAfter:"
		<< "\n      p1.Name(\"Leo Zee\");"
		<< "\n      p1.Age(98);"
		<< "\n      p1.SSN(\"842 - 85 - 5342\");"
		<< "\np1 follows:\n" << p1 << "\np2 follows:\n" << p2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
}