/*	Project:    Project #5
	Name:       Adam Davis
    Partner:    N/A
    Class:     CSC 1810 - Section 1
*/
#include <iostream>
#include <vector>
#include "GeneSeq.h"
#include "Gene.h"
#include "Allele.h"
#include "Chromes.h"

using namespace std;

void menu()
{
	cout << "1 - Create chromosome" << endl;
	cout << "2 - Analyze chromosome" << endl;
	cout << "3 - Output chromosome to file" << endl;
	cout << "4 - Input chromosome from file" << endl;
	cout << "5 - Combine chromosomes" << endl;
	cout << "6 - Repeat Menu" << endl;
	cout << "7 - Quit" << endl;
	cout << "Hello User. Please input a number to select a menu option. " << endl;
};

int main(int argc, char *argv[])
{

	int Userinput = 0;
	string chromosome = "";

	cout << "1 - Create chromosome" << endl;
	cout << "2 - Analyze chromosome" << endl;
	cout << "3 - Output chromosome to file" << endl;
	cout << "4 - Input chromosome from file" << endl;
	cout << "5 - Combine chromosomes" << endl;
	cout << "6 - Repeat Menu" << endl;
	cout << "7 - Quit" << endl;
	cout << "Hello User. Please input a number to select a menu option. " << endl;

	Chromes CH;
	GenSeq Seq;

	cin >> Userinput;

	while (Userinput != 7)
	{

		if (Userinput == 1)
		{
			CH.Create();
		}
		else if (Userinput == 2)
		{
			CH.Analyze();
		}
		else if (Userinput == 3)
		{
			CH.Output();
		}
		else if (Userinput == 4)
		{
			CH.Input();
		}
		else if (Userinput == 5)
		{
			Seq.Combine();
		}
		else if (Userinput == 6)
		{
			menu();
		}
		else
		{
			cout << "Invalid Input." << endl;
		}
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please Enter a new Menu input number: " << endl;
		cin >> Userinput;
	}

	{
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}
