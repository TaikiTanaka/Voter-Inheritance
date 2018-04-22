#include <iostream>
using namespace std;

void PersonTesting();
void FacultyTesting();
void StudentTesting();
void StudentVoterTesting();
void VoterTesting();

int main()
{
	int menuOption;
	bool flag = true;
	while (flag)
	{
		system("cls");
		cout << "Choose an option\n"
			<< "1. Test Person class\n"
			<< "2. Test Student class\n"
			<< "3. Test Voter class\n"
			<< "4. Test Faculty class\n"
			<< "5. Test StudentVoter class\n"
			<< "6. Exit\n";
		cin >> menuOption;
		cin.get();
		system("cls");

		switch (menuOption)
		{
		case 1:
			PersonTesting();
			break;
		case 2:
			StudentTesting();
			break;
		case 3:
			VoterTesting();
			break;
		case 4:
			FacultyTesting();
			break;
		case 5:
			StudentVoterTesting();
			break;
		case 6:
		{
			flag = false;
			break;
		}
		default:
			break;
		}
	}
	return 0;
}