#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Gene.h"
#include "Allele.h"
#include "GeneSeq.h"
#include "Chromes.h"

using namespace std;

void GenSeq::CreateChromosomePair()
{
	int answer = 0;
	cout << "Would you like to create by hand(1) or would you like to import a Chromosome Pair(2)?" << endl;

	cin >> answer;
	cin.clear();
	cin.ignore(1000, '\n');

	while (answer != 1 && answer != 2)
	{
		answer = 0;
		cout << "Invalid Input. Please enter 1 or 1." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> answer;
	}

	if (answer == 1)
	{
		cout << "Ok time to create two brand new Chromosomes..... Yay." << endl;
		Chromes C;
		int chorme_num = 0;
		while (chorme_num < 2)
		{
			C.Create();
			chorme_num = chorme_num + 1;
		}
	}
	else
	{
		Chromes C;
		C.Input();
		ChromosomeA = C.GiveChrome();
		C.Input();
		ChromosomeB = C.GiveChrome();
		cout << "Chromosome Pair set." << endl;
	}
};
void GenSeq::Read()
{
	cout << "Chromosome A: " << endl;
	cout << ChromosomeA << endl;
	cout << "Chromosome B: " << endl;
	cout << ChromosomeB << endl;
};

void GenSeq::ExportChromosomePair()
{
	int decision = 0;
	cout << "What file would you like to export? Chromosome pair(1)? Chromosome(2)? Gene(3)? Allele(4)?" << endl;
	cin >> decision;

	while (decision > 4 || decision < 1)
	{
		cout << "Invailid input. Please enter a valid input." << endl;
		cin >> decision;
	}

	if (decision == 2)
	{
		Chromes C;
		C.Output();
	}
	else if (decision == 3)
	{
		Gene G;
		G.Output();
	}
	else if (decision == 4)
	{
		Allele A;
		A.Output();
	}
	else
	{

		char answer = 'y';
		cout << "Would you like to use the existing set of Chromosomes? (y/n) Enter \'R\' if you would like to see the current Chromosomes." << endl;
		cin >> answer;

		while (answer != 'y' || answer != 'n' || answer != 'R')
		{
			cout << "Invailid input. Please enter a valid input." << endl;
			cin >> answer;
		}

		if (answer == 'R')
		{
			Read();
			cout << "Now would you like to use the existing set of Chromosomes?(y/n)" << endl;
			cin >> answer;
		}

		if (answer == 'n')
		{
			CreateChromosomePair();
			answer = 'y';
		}

		if (answer == 'y')
		{
			string outputfile = "";
			cout << "Pleae enter the file you would like to output your Chromosome to." << endl;
			getline(cin, outputfile);
			cin.clear();
			cin.ignore(1000, '\n');

			ofstream myfile;

			myfile.open(outputfile);
			while (!myfile.is_open())
			{
				cout << "File " << outputfile << " could not open. Please try again." << endl;

				cout << "Please enter the file location of the file containing the Chromes you would like to import." << endl;
				getline(cin, outputfile);

				myfile.open(outputfile, ios::app);
			}
			//finish this file
			myfile << ChromosomeA << ChromosomeB;
		}
	}
};

void GenSeq::Combine()
{

	GenSeq::CreateChromosomePair();
	cout << "The current two Chromosomes are " << ChromosomeA << " and " << ChromosomeB << endl;

	cout << "The new Chromosome is " << NewChrome << endl;
};
