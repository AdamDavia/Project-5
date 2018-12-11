#include <iostream>
#include <vector>
#include "Chromes.h"
#include "Gene.h"
#include "Allele.h"
#include <fstream>
#include <algorithm>

using namespace std;

Gene::Gene() {}

void Gene::setgene(string intputgene)
{
	gene = intputgene;
}

void Gene::GCreate()
{
	Allele all;
	string part;
	string GeneSeq;
	Chromes C;

	cout << "How many Genes do you want this Chromosome to have?" << endl;
	string temp;

	getline(cin, temp);

	while (!C.Check(temp, num_Genes) && num_Genes < 1)
	{
		cout << "Please enter a valid number." << endl;
		getline(cin, temp);
	}

	if (num_Genes > 0)
	{
		for (int i = 0; i <= num_Genes; i++)
		{
			string B = "n";

			cout << "Ok. We have to make " << num_Genes - i << " genes." << endl;

			cout << "Ok. Please enter an aspect of the body that you can add two different modifiable triats to. EX: Light Brown Hair. You'd enter Hair in this. " << endl;
			getline(cin, part);

			cout << "Ok. Please enter the Gene Sequence or Gene name." << endl;
			cout << "This usually relates to the aspect of the body but doesn't matter really." << endl;
			cout << "This program will only use it as reference if you have multiple genes modifying alike parts." << endl;

			getline(cin, GeneSeq);

			cout << "Ok time to make the two alleles for this Gene." << endl;

			all.Create();

			gene = "Gene: " + GeneSeq + ", " + part + ". " + all.GetAllelee();
			cout << gene << endl;
			Chromes C;

			C.addgenie(gene);
		}
	}
};
int Gene::num_Genies()
{
	return num_Genes;
}
string Gene::GetGene()
{
	return this->gene;
}

/*void Gene::Output()
{
	Chromes C;
	C.Analyze();
	C.GiveChrome();
	C.GeneList();
	C.Validfile();
	C.FindGene();

	ofstream myfile;

	myfile.open(C.outputfile, ios::app);

	myfile << gene;

	myfile.close();
};
Was working on but didn't finish.


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
*/
