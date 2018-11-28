#include <iostream>
#include <vector>
#include "Gene.h"
#include "Allele.h"
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>

using namespace std;

void Allele::Create()
{
	Alleles.resize(2);

	cout << "Ok. Please enter the sequence of the alleles. Should be 4 letters." << endl;

	getline(cin, sequence);

	//make this a testbench
	for (unsigned int i = 0; i < sequence.size(); i++)
	{
		if (isdigit(sequence.at(i + 1)) == true)
		{
			cout << "Please enter only characters in the Allele sequence. Reenter a valid expression." << endl;

			getline(cin, sequence);
			cin.clear();
			cin.ignore(1000, '\n');
		}

		toupper(sequence.at(i + 1));
	}

	for (int o = 0; o < 2; o++)
	{

		int C = 0;

		cout << "Ok. Please enter the first aspect of the allele." << endl;

		getline(cin, trait1);

		cout << "Ok. Please enter whether it is dominant or recessive(2). " << endl;
		cin >> C;
		if (C != 1 && C != 2)
		{
			while (C != 1 && C != 2)
			{
				cout << "Invalid Input. Please enter 1 or 2." << endl;
				cin >> C;
			}
		}
		else if (C == 1)
		{
			cout << "Ok trait 1 is set to dominant." << endl;
			Dominon1 = "Dominant";
		}
		else if (C == 2)
		{
			cout << "Ok trait 1 is set to recessive." << endl;
			Dominon1 = "Recessive";
		}

		C = 0;

		cout << "Ok. Please enter the second trait that correlates with the first trait of the Allele. EX: Dark Brown, Light Brown or Dark Blond, Light Blond." << endl;

		getline(cin, trait2);
		cin.clear();
		cin.ignore(1000, '\n');

		C = 0;
		cout << "Ok. Please enter whether it is dominant(1) or recessive(2). " << endl;
		cin >> C;

		if (C != 1 && C != 2)
		{
			while (C != 1 && C != 2)
			{
				cout << "Invalid Input. Please enter 1 or 2." << endl;
				cin >> C;
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Ok trait 1 is set to " << C << "." << endl;
			}
		}
		else if (C == 1)
		{
			cout << "Ok trait 1 is set to dominant." << endl;
			Dominon1 = "Dominant";
		}
		else if (C == 2)
		{
			cout << "Ok trait 1 is set to recessive." << endl;
			Dominon1 = "Recessive";
		}

		C = 0;

		cout << "Ok Allele " << o + 1 << " of the two made inside of a Gene is done. Here is the information of the first allele. Now to the next allele." << endl;

		cout << "Allele " << o + 1 << ":" << endl;
		cout << "Sequence: " << sequence << endl;
		cout << "Trait 1:    " << trait1 << endl;
		cout << "Dominance:  " << Dominon1 << endl;
		cout << "Trait 2:    " << trait2 << endl;
		cout << "Dominance:  " << Dominon2 << endl;

		Alleles.at(o) = trait1 + ", " + Dominon1 + ", " + trait2 + ", " + Dominon2;
		cout << Alleles.at(o);
	}

	string DomAllele = "";
	//This will need to be in Allele.h in the end as an object. The object is a randomizer.
	//randomizer object goes here
	//Still need object orientation
	int AlleleGen = 0;
	AlleleGen = (rand() % 4) + 1;

	if (Dominon1 == Dominon2)
	{
		AlleleGen = (rand() % 2) + 1;
		if (AlleleGen == 1)
		{
			cout << Dominon1;
			//set dominance as one
		}
		else
		{
			cout << Dominon2;
			//set dominance as two
		}
	}
	else if (Dominon1 == "Dominent")
	{
		AlleleGen = (rand() % 4) + 1;
		if (AlleleGen == 1 || AlleleGen == 2 || AlleleGen == 3)
		{
			cout << Dominon1;
			//set dominacne as 1
		}
		else
		{
			cout << Dominon2;
			//set dominance as 2
		}
	}

	else if (Dominon2 == "Recessive")
	{
		AlleleGen = (rand() % 4) + 1;
		if (AlleleGen == 1)
		{
			cout << Dominon1;
			//set dominacne as 1
		}
		else
		{
			cout << Dominon2;
			//set dominance as 2
		}
	}
};