#include <iostream>
#include <vector>
#include "GeneSeq.h"
#include "Chromes.h"
#include <fstream>
#include <algorithm>

using namespace std;

void GenSeq::CreateChromosomePair()
{
	int answer = 0;
	cout << "Would you like to create by hand(1) or would you like to import a Chromosome Pair(2)?" << endl;
	cin >> answer;

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
		cout << "Chormosome one is :" << Chomosomes.at(Chromosomes.size() - 1);
		C.Input();
	}
};
void GenSeq::Combine(){};
void GenSeq::ExportChromosomePair(){};

void GenSeq::OutputOrigins(){};
