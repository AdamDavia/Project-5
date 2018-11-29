#include <iostream>
#include <vector>
#include "Chromes.h"
#include "Gene.h"
#include "Allele.h"
#include <fstream>
#include <algorithm>

using namespace std;

void Gene::setgene(string intputgene)
{
	gene = intputgene;
}
void Gene::GCreate()
{
	Allele all;
	string part;
	string GeneSeq;

	cout << "How many Genes do you want this Chromosome to have?" << endl;
	cin >> num_Genes;

	for (int i = 0; i <= num_Genes; i++)
	{
		char B = 'n';

		cout << "Ok. We have to make " << num_Genes << "." << endl;

		cout << "You sure you still want to make this many genes?(y/n)" << endl;
		cin >> B;

		while (B != 'n' && B != 'y')
		{
			B = 'o';
			cout << "Invalid Input. Please enter y or n." << endl;
			cin >> B;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		if (B == 'n')
		{
			cout << "Ok please enter the number of genes you would like to create." << endl;
			cin >> num_Genes;
			B = 'y';
		}

		if (B == 'y')
		{

			cout << "Ok. Please enter an aspect of the body that you can add two different modifiable triats to. EX: Light Brown Hair. You'd enter Hair in this. " << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			getline(cin, part);

			cout << "Ok. Please enter the Gene Sequence." << endl;

			getline(cin, GeneSeq);
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Ok time to make the two alleles for this Gene." << endl;

			all.Create();
		}

		gene = "Gene: " + GeneSeq + ", " + part + ", " + all.GetAllelee();
		num_Genes = num_Genes - 1;
	}
};
void Gene::Output()
{
	Chromes C;
	C.GetChrome();
	C.GiveChrome();
	C.GeneList();
	C.Validfile();
	C.FindGene();

	ofstream myfile;

	myfile.open(C.outputfile, ios::app);

	myfile << gene;

	myfile.close();
};

void Gene::SetAllele()
{
	Chromes C;
	C.FindGene();
	C.genecall();
	string word = "";
	string Phrase = "";
	int x = 0;
	for (unsigned int i = 0; i < gene.size(); i++)
	{
		word = word + gene.at(i);

		if (word == "1" && x == 0)
		{
			word.clear();
			x = x + 1;
		}
		else if (word == "2" && x == 1)
		{
			word.clear();
			x = 0;
		}

		if (gene.at(i) == ' ')
		{
			word.clear();
		}

		if (x == 1)
		{
			Phrase = Phrase + gene.at(i);
		}
	}
};
