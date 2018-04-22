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

#include "StudentVoter.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void StudentVoterTesting()
{
	//***** Testing Constructors *****
	cout << left << setprecision(1) << fixed;
	StudentVoter sv1, sv2("Taiki Tanaka", 21, "643-54-3453", 3.8f, "Democrat");
	//   ***** Check out the constructors, output operator for monitor *****
	cout << "***** Check out the constructors, output operator for monitor *****\n";
	cout << "\nAfter:"
		<< "\nStudentVoter sv1, sv2(\"Taiki Tanaka\", 21, \"643 - 54 - 3453\", 3.8, \"Democrat\")"
		<< "\nv1 follows:\n" << sv1
		<< "\nv2 follows:\n" << sv2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

	StudentVoter sv3(sv2);
	cout << "\nAfter:"
		<< "\n      Voter sv3(sv2);"
		<< "\nv2 follows:\n" << sv2
		<< "\nv3 follows:\n" << sv3
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

	sv2.Name("Jon Jones");
	cout << "\nAfter:"
		<< "\n      sv2.Name(\"Jon Jones\");"
		<< "\nsv2 follows:\n" << sv2
		<< "\nsv3 follows:\n" << sv3
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	sv1.Name("Chael Sonnen");
	sv1.Age(33);
	sv1.SSN("554-23-6432");
	sv1.GPA(3.5);
	sv1.partyAffiliation("Republican");


	//--------------------------------------------------------------------------------------------
	//   ***** Testing the accessors and mutators *****
	cout << "***** Testing the accessors and mutators *****"
		<< "\n\nAfter:"
		<< "\n      sv1.Name(\"Chael Sonnen\");"
		<< "\n      sv1.Age(33);"
		<< "\n      sv1.SSN(\"554 - 23 - 6432\");"
		<< "\n      sv1.GPA(3.5);"
		<< "\n      sv1.partyAffiliation(\"Republican\");"
		<< "\nsv1.Name() = " << sv1.Name()
		<< "\nsv1.Age() = " << sv1.Age()
		<< "\nsv1.SSN() = " << sv1.SSN()
		<< "\nsv1.GPA() = " << sv1.GPA()
		<< "\nsv1.partyAffiliation() = " << sv1.partyAffiliation()
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//--------------------------------------------------------------------------------------------
	//   ***** Testing reading from the keyboard *****
	cout << "***** Testing reading from the keyboard *****"
		<< "\n\nEnter data for Voter v1:\n";
	cin >> sv1;
	cout << "\nAfter:"
		<< "\n      cin >> sv1;"
		<< "\nsv1 follows:\n" << sv1 << "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//--------------------------------------------------------------------------------------------
	//   ***** Testing File I/O Consistency *****
	cout << "***** Testing File I/O Consistency *****";

	string outputFileName;
	ofstream outputFile;

	cout << "\n\nEnter the the name of an output file for sv1, sv2, and sv3: " << flush;
	getline(cin, outputFileName);
	outputFile.open(outputFileName);
	if (outputFile.fail())
	{
		cout << "\n\n***** ERROR. There was a problem opening the output file."
			<< "\n\nHit enter to exit the program: " << flush;
		cin.get();
		exit(1);
	}
	outputFile << sv1 << '\n' << sv2 << '\n' << sv3;
	outputFile.close();

	ifstream inputFile;
	StudentVoter sv1c, sv2c, sv3c;
	inputFile.open(outputFileName);

	inputFile >> sv1c >> sv2c >> sv3c;
	inputFile.close();
	cout << "\nAfter:"
		<< "\n      outputFile << sv1 << '\\n' << sv2 << '\\n' << sv3;"
		<< "\n      outputFile.close();"
		<< "\n      ifstream inputFile;"
		<< "\n      Vehicle sv1c, sv2c, sv3c;"
		<< "\n      inputFile.open(outputFileName);"
		<< "\n      inputFile >> sv1c >> sv2c >> sv3c;"
		<< "\nsv1 follows:\n" << sv1
		<< "\nsv1c follows:\n" << sv1c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cout << "\nsv2 follows:\n" << sv2
		<< "\nsv2c follows:\n" << sv2c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cout << "\nsv3 follows:\n" << sv3
		<< "\nsv3c follows:\n" << sv3c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//--------------------------------------------------------------------------------------------
	//   ***** Making Sure Output Operator and Accessors Work With const Objects *****
	const StudentVoter csv("George Pierre", 35, "853-34-1823",3.0f, "Communist");
	cout << "***** Making Sure Output Operator and Accessors Work With const Objects *****"
		<< "\n\nAfter:"
		<< "\n      const Voter(\"George Pierre\", 35, \"853 - 34 - 1823\", 3.0f, \"Communist\");"
		<< "\ncsv follows:\n" << csv
		<< "\n\ncsv.Name() = " << csv.Name()
		<< "\ncsv.Age() = " << csv.Age()
		<< "\ncsvSSN() = " << csv.SSN()
		<< "\ncsv.GPA() = " << csv.GPA()
		<< "\ncsv.partyAffiliation() = " << csv.partyAffiliation()
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//--------------------------------------------------------------------------------------------
	//   ***** Verifying Assignment Operator Works Properly *****
	cout << "***** Verifying Assignment Operator Works Properly *****"
		<< "\n\nEnter data for sv1:\n";
	cin >> sv1;
	sv2 = sv1;
	cout << "\nAfter:"
		<< "\n      cin >> sv1;"
		<< "\n      sv2 = sv1;"
		<< "\nsv1 follows:\n" << sv1 << "\nsv2 follows:\n" << sv2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

	sv1.Name("Leo Zee");
	sv1.Age(28);
	sv1.SSN("842-85-5342");
	sv1.GPA(1.8f);
	sv1.partyAffiliation("Undecided");
	cout << "\nAfter:"
		<< "\n      sv1.Name(\"Leo Zee\");"
		<< "\n      sv1.Age(28);"
		<< "\n      sv1.SSN(\"842 - 85 - 5342\");"
		<< "\n      sv1.GPA(1.8f);"
		<< "\n		sv1.partyAffiliation(\"Undecided\");"
		<< "\nsv1 follows:\n" << sv1 << "\nsv2 follows:\n" << sv2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
}