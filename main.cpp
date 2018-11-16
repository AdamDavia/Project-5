/*	Project:    Project #5
	Name:       Adam Davis
    Partner:    N/A
    Class:     CSC 1810 - Section 1
*/
#include <iostream>
#include <vector>
#include "GeneSeq.h"
#include "Seq.cpp"
#include "Gene.h"
#include "Allele.h"
#include "Chromosome.h"

using namespace std;

int main(int argc, char *argv[])
{
	int Userinput = 0;
	string chromosome = "";

	cout << "1 - Create chromosome" << endl;
	cout << "2 - Analyze chromosome" << endl;
	cout << "3 - Output chromosome to file" << endl;
	cout << "4 - Input chromosome from file" << endl;
	cout << "5 - Combine chromosomes" << endl;
	cout << "6 - Quit" << endl;
	cout << "Hello User. Please input a number to select a menu option. " << endl;

	cin >> Userinput;

	while (Userinput != 6)
	{

		if (Userinput == 1)
		{
			GeneSeq.Create();
		}
		else if (Userinput == 2)
		{
			GeneSeq.Analyze();
		}
		else if (Userinput == 3)
		{
			GeneSeq.Output();
		}
		else if (Userinput == 4)
		{
			GeneSeq.Input();
		}
		else if (Userinput == 5)
		{
			GeneSeq.Combine();
		}
		else
		{
			cout << "Invalid Input." << endl;
		}
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Please Enter a new input number: " << endl;
		cin >> Userinput;
	}

	{
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}
