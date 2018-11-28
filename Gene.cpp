#include <iostream>
#include <vector>
#include "Gene.h"
#include "Allele.h"
#include <fstream>
#include <algorithm>

using namespace std;
//Gene::Gene(){};
void Gene::GCreate()

{

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

		if (B != 'n' && B != 'y')
		{
			while (B != 'n' && B != 'y')
			{
				B = 'o';
				cout << "Invalid Input. Please enter y or n." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> B;
			}
		}
		else if (B == 'n')
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

			Allele ALL;
			ALL.Create();
		}

		Genes.resize(num_Genes);

		//This is where Gene will put together all its data.
		//Genes.at(i) = GeneSeq + ", " + "Allele 1: " + Alleles.at(0) + ", Allele 2: " + Alleles.at(1);
	}
};