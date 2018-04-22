#include "Faculty.h"
#include <iostream>
#include <fstream>
using namespace std;


void FacultyTesting()
{
	//***** Testing Constructors *****
	string s1[2] = { "Computer Science", "Electrical Engineering" };
	Faculty f1, f2("Satish Singhal", 55, "534-23-1634", 2, s1);
	cout << "***** Check out the constructors, output operator for monitor *****\n";
	cout << "\nAfter:"
		<< "\n      Faculty f1, f2(\"Satish Singhal\", 55, \"534 - 23 - 1634\", 2, s1)"
		<< "\nf1 follows:\n" << f1
		<< "\nf2 follows:\n" << f2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

	Faculty f3(f2);
	cout << "\nAfter:"
		<< "\n      Faculty f3(f2);"
		<< "\nf2 follows:\n" << f2
		<< "\nf3 follows:\n" << f3
		<< "\n\nHit enter to continue: " << flush;
	cin.get();	

	f2.Name("Diego Sanchez");
	cout << "\nAfter:"
		<< "\n      f2.Name(\"Diego Sanchez\");"
		<< "\nf2 follows:\n" << f2
		<< "\nf3 follows:\n" << f3
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//----------------------------------------------------------------------------------------
	//***** Testing the accessors and mutators *****
	f1.Name("John Smith");
	f1.Age(54);
	f1.SSN("832-23-5234");
	string s2[3] = { "Biology", "Mechanical Engineering", "Economics" };
	string * s3 = nullptr;
	f1.degrees(3, s2);
	f1.degrees(s3);
	cout << "***** Testing the accessors and mutators *****"
		<< "\n\nAfter:"
		<< "\n      f1.Name(\"John Smith\");"
		<< "\n      f1.Age(54);"
		<< "\n      f1.SSN(\"832 - 23 - 5234\");"
		<< "\n      f1.degrees(3,s2);"
		<< "\nf1.Name() = " << f1.Name()
		<< "\nf1.Age() = " << f1.Age()
		<< "\nf1.SSN() = " << f1.SSN()
		<< "\nf1.numberOfDegrees() = " << f1.numberOfDegrees()
		<< "\nf1.degrees() = ";
		 for (size_t i = 0; i < static_cast<size_t>(f1.numberOfDegrees()); i++)
			{
				cout << s3[i] << '\n';
			}
	cout << "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//----------------------------------------------------------------------------------------
	//***** Testing File I/O Consistency *****
	cout << "***** Testing File I/O Consistency *****";

	string outputFileName;
	ofstream outputFile;

	cout << "\n\nEnter the the name of an output file for f1, f2, and f3: " << flush;
	getline(cin, outputFileName);
	outputFile.open(outputFileName);
	if (outputFile.fail())
	{
		cout << "\n\n***** ERROR. There was a problem opening the output file."
			<< "\n\nHit enter to exit the program: " << flush;
		cin.get();
		exit(1);
	}
	outputFile << f1 << '\n' << f2 << '\n' << f3;
	outputFile.close();

	ifstream inputFile;
	Faculty f1c, f2c, f3c;

	inputFile.open(outputFileName);

	inputFile >> f1c >> f2c >> f3c;
	inputFile.close();
	cout << "\nAfter:"
		<< "\n      outputFile << f1 << '\\n' << f2 << '\\n' << f3;"
		<< "\n      outputFile.close();"
		<< "\n      ifstream inputFile;"
		<< "\n      Vehicle f1c, f2c, f3c;"
		<< "\n      inputFile.open(outputFileName);"
		<< "\n      inputFile >> f1c >> f2c >> f3c;"
		<< "\nf1 follows:\n" << f1
		<< "\nf1c follows:\n" << f1c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cout << "\nf2 follows:\n" << f2
		<< "\nf2c follows:\n" << f2c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	cout << "\nf3 follows:\n" << f3
		<< "\nf3c follows:\n" << f3c
		<< "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//----------------------------------------------------------------------------------------
	//***** Making Sure Output Operator and Accessors Work With const Objects *****

	string s4[] = { "Art", "Sports Science" };
	const Faculty cf("Chris Wiedman", 29, "644-23-5423", 2, s4);
	string * s5 = nullptr;
	cf.degrees(s5);

	cout << "***** Making Sure Output Operator and Accessors Work With const Objects *****"
		<< "\n\nAfter:"
		<< "\n      const Faculty cf(\"Chris Wiedman\", 29, \"644 - 23 - 5423\",2, s4);"
		<< "\ncf follows:\n" << cf
		<< "\n\ncf.Name() = " << cf.Name()
		<< "\ncf.Age() = " << cf.Age()
		<< "\ncf.SSN() = " << cf.SSN()
		<< "\ncf.numberOfDegrees() = \n" << cf.numberOfDegrees()
		<< "\ncf.degrees(s5); = ";
		for (size_t i = 0; i < (size_t)cf.numberOfDegrees(); i++)
		{
			cout << s5[i] << '\n';
		}
			

	cout << "\n\nHit enter to continue: " << flush;
	cin.get();
	system("cls");

	//----------------------------------------------------------------------------------------
	//***** Verifying Assignment Operator Works Properly *****
	cout << "***** Verifying Assignment Operator Works Properly *****"
		<< "\n\nEnter data for f1:\n";
	cin >> f1;
	f2 = f1;
	cout << "\nAfter:"
		<< "\n      cin >> f1;"
		<< "\n      f2 = f1;"
		<< "\nf1 follows:\n" << f1 << "\nf2 follows:\n" << f2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

	f1.Name("Leo Zee");
	f1.Age(32);
	f1.SSN("842-85-5342");
	cout << "\nAfter:"
		<< "\n      f1.Name(\"Leo Zee\");"
		<< "\n      f1.Age(98);"
		<< "\n      f1.SSN(\"842 - 85 - 5342\");"
		<< "\nf1 follows:\n" << f1 << "\nf2 follows:\n" << f2
		<< "\n\nHit enter to continue: " << flush;
	cin.get();

}