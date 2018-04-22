/*
Name: Taiki Tanaka
Class: CSCI 30, Adcanced Programming in C++
Section: 0124
Assignment Number: 1
File(s): TanakaTprgm1.cpp
Due Date:
--------------------------------------------------------------------------------------
I, Taiki Tanaka, pledge that this is my own independent work, which conforms to
generally accepted guidelines of academic honesty.
--------------------------------------------------------------------------------------
*/

#include "Voter.h"
#include <iostream>
#include <fstream>
using namespace std;


void VoterTesting()
{
	Voter v1, v2("Taiki Tanaka", 21, "345-74-2345", "Democrat");
	//   ***** Check out the constructors, output operator for monitor *****
	cout << "***** Check out the constructors, output operator for monitor *****\n";
	cout << "\nAfter:"
		<< "\n      Voter v1, v2(\"Taiki Tanaka\", 21, \"345 - 74 - 2345\", \"Democrat\");"
		<< "\nv1 follows:\n" << v1
		<< "\nv2 follows:\n" << v2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

	Voter v3(v2);
	cout << "\nAfter:"
		<< "\n      Voter v3(v2);"
		<< "\nv2 follows:\n" << v2
		<< "\nv3 follows:\n" << v3
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

	v2.Name("Jon Jones");
	cout << "\nAfter:"
		<< "\n      v2.Name(\"Jon Jones\");"
		<< "\nv2 follows:\n" << v2
		<< "\nv3 follows:\n" << v3
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");


	v1.Name("Chael Sonnen");
	v1.Age(33);
	v1.SSN("554-23-6432");
	v1.partyAffiliation("Republican");

	//----------------------------------------------------------------------------------------
	//   ***** Testing the accessors and mutators *****
	cout << "***** Testing the accessors and mutators *****"
		<< "\n\nAfter:"
		<< "\n      v1.Name(\"Chael Sonnen\");"
		<< "\n      v1.Age(33);"
		<< "\n      v1.SSN(\"554 - 23 - 6432\");"
		<< "\n      v1.partyAffiliation(\"Republican\");"
		<< "\nv1.Name() = " << v1.Name()
		<< "\nv1.Age() = " << v1.Age()
		<< "\nv1.SSN() = " << v1.SSN()
		<< "\nv1.partAffiliaition() = " << v1.partyAffiliation()
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//----------------------------------------------------------------------------------------
	//   ***** Testing reading from the keyboard *****
	cout << "***** Testing reading from the keyboard *****"
		<< "\n\nEnter data for Voter v1:\n";
	cin >> v1;
	cout << "\nAfter:"
		<< "\n      cin >> v1;"
		<< "\nv1 follows:\n" << v1 << "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//----------------------------------------------------------------------------------------
	//   ***** Testing File I/O Consistency *****
	cout << "***** Testing File I/O Consistency *****";

	string outputFileName;
	ofstream outputFile;

	cout << "\n\nEnter the the name of an output file for v1, v2, and v3: " << flush;
	getline(cin, outputFileName);
	outputFile.open(outputFileName);
	if (outputFile.fail())
	{
		cout << "\n\n***** ERROR. There was a problem opening the output file."
			<< "\n\nHit enter to exit the program: " << flush;
		cin.get();
		exit(1);
	}
	outputFile << v1 << '\n' << v2 << '\n' << v3;
	outputFile.close();

	ifstream inputFile;
	Voter v1c, v2c, v3c;

	inputFile.open(outputFileName);

	inputFile >> v1c >> v2c >> v3c;
	inputFile.close();
	cout << "\nAfter:"
		<< "\n      outputFile << v1 << '\\n' << v2 << '\\n' << v3;"
		<< "\n      outputFile.close();"
		<< "\n      ifstream inputFile;"
		<< "\n      Vehicle v1c, v2c, v3c;"
		<< "\n      inputFile.open(outputFileName);"
		<< "\n      inputFile >> v1c >> v2c >> v3c;"
		<< "\nv1 follows:\n" << v1
		<< "\nv1c follows:\n" << v1c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cout << "\nv2 follows:\n" << v2
		<< "\nv2c follows:\n" << v2c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cout << "\nv3 follows:\n" << v3
		<< "\nv3c follows:\n" << v3c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");


	//----------------------------------------------------------------------------------------
	//   ***** Making Sure Output Operator and Accessors Work With const Objects *****
	const Voter cv("George Pierre", 35, "853-34-1823", "Communist");                   
	cout << "***** Making Sure Output Operator and Accessors Work With const Objects *****"
		<< "\n\nAfter:"
		<< "\n      const Voter(\"George Pierre\", 35, \"853 - 34 - 1823\", \"Communist\");"
		<< "\ncv follows:\n" << cv
		<< "\n\ncv.Name() = " << cv.Name()
		<< "\ncv.Age() = " << cv.Age()
		<< "\ncv.cv.SSN() = " << cv.SSN()
		<< "\ncv.partyAffiliation() = " << cv.partyAffiliation()
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//----------------------------------------------------------------------------------------
	//   ***** Verifying Assignment Operator Works Properly *****
	cout << "***** Verifying Assignment Operator Works Properly *****"
		<< "\n\nEnter data for v1:\n";
	cin >> v1;
	v2 = v1;
	cout << "\nAfter:"
		<< "\n      cin >> v1;"
		<< "\n      v2 = v1;"
		<< "\nv1 follows:\n" << v1 << "\nv2 follows:\n" << v2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

	v1.Name("Leo Zee");
	v1.Age(28);
	v1.SSN("842-85-5342");
	v1.partyAffiliation("Undecided");
	cout << "\nAfter:"
		<< "\n      v1.Name(\"Leo Zee\");"
		<< "\n      v1.Age(28);"
		<< "\n      v1.SSN(\"842 - 85 - 5342\");"
		<< "\n		v1.partyAffiliation(\"Undecided\");"
		<< "\nv1 follows:\n" << v1 << "\nv2 follows:\n" << v2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
}