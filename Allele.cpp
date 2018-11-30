#include <iostream>
#include <vector>
#include "Chromes.h"
#include "Gene.h"
#include "Allele.h"
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>

using namespace std;

///home/student/src/Project_5/test.txt

Allele::Allele() {}

void Allele::Output()
{
	int y = 0;
	Chromes C;
	string Num = "";
	string whichgene;

	C.GetChrome();
	C.GiveChrome();
	C.SetGene();
	C.FindGene();

	cout << "Ok which allele would you like to use?(1/2)" << endl;
	cin >> y;
	while (y != 1 || y != 2)
	{
		cout << "Invailid input. Please enter a valid input." << endl;
		cin >> y;
	}
	C.Validfile();

	ofstream myfile;

	if (y == 1)
	{
		myfile << allele1;
	}
	else if (y == 2)
	{
		myfile << allele2;
	}
};

string Allele::GetAllelee()
{
	return allelee;
}

void Allele::Create()
{

	for (int o = 0; o < 2; o++)
	{
		cout << "Ok. Please enter the sequence of the alleles. Should be 4 letters." << endl;

		getline(cin, sequence);
		cin.clear();
		cin.ignore(1000, '\n');

		Allele::Unittest();

		allelee = "Allele Sequence:" + sequence;

		int C = 0;

		cout << "Ok. Please enter the first trait of the allele." << endl;

		getline(cin, trait1);

		cout << "Ok. Please enter whether it is dominant(1) or recessive(2). " << endl;
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
				cout << "Ok trait 2 is set to " << C << "." << endl;
			}
		}
		else if (C == 1)
		{
			cout << "Ok trait 2 is set to dominant." << endl;
			Dominon2 = "Dominant";
		}
		else if (C == 2)
		{
			cout << "Ok trait 2 is set to recessive." << endl;
			Dominon2 = "Recessive";
		}

		// home / student / src / Project_5 / test.txt

		C = 0;

		cout << "Ok Allele " << o + 1 << " of the two made inside of a Gene is done. Here is the information of the first allele. Now to the next allele." << endl;

		cout << "Allele " << o + 1 << ":" << endl;
		cout << "Sequence: " << sequence << endl;
		cout << "Trait 1:    " << trait1 << endl;
		cout << "Dominance:  " << Dominon1 << endl;
		cout << "Trait 2:    " << trait2 << endl;
		cout << "Dominance:  " << Dominon2 << endl;

		if (o == 0)
		{
			allele1 = sequence + ", " + trait1 + ", " + Dominon1 + ", " + trait2 + ", " + Dominon2;
		}
		else
		{
			allele2 = trait1 + ", " + Dominon1 + ", " + trait2 + ", " + Dominon2;
		}
		sequence = "";
		trait1 = "";
		trait2 = "";
		Dominon1 = "";
		Dominon2 = "";
	}
	Allele::Mixer();
};
void Allele::GetAllele1(){

};
void Allele::GetAllele2(){

};
void Allele::Unittest()
{
	for (unsigned int i = 0; i < sequence.size(); i++)
	{
		toupper(sequence.at(i));

		if (isdigit(sequence.at(i)) == true)
		{
			cout << "Please enter only characters in the Allele sequence. Reenter a valid expression." << endl;

			getline(cin, sequence);
			cin.clear();
			cin.ignore(1000, '\n');
		}
		if (sequence.size() > 4)
		{
			cout << "Please enter only 4 characters long in the Allele sequence. Reenter a valid expression." << endl;

			getline(cin, sequence);
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
};

void Allele::GetDomin1()
{
	Dominon1 = "";
	Dominon2 = "";

	//testing for the dominances
	for (unsigned int i = 0; i < allele1.size(); i++)
	{
		Dominon1 = Dominon1 + allele1.at(i);

		if (Dominon1 == "Dominant" || Dominon1 == "Recessive")
		{

			i = allele1.size();
		}
		else if (allele1.at(i) == ' ')
		{
			Dominon1.clear();
		}
	}
	for (unsigned int i = 0; i < allele2.size(); i++)
	{
		Dominon2 = Dominon2 + allele2.at(i);

		if (Dominon2 == "Dominant" || Dominon2 == "Recessive")
		{
			i = allele2.size();
		}
		else if (allele2.at(i) == ' ')
		{
			Dominon1.clear();
		}
	}
};

void Allele::GetTrait1()
{
	num_comma = 0;

	for (unsigned int i = 0; i < allele1.size(); i++)
	{
		trait1 = trait1 + allele1.at(i);

		if (allele1.at(i) == ',')
		{
			num_comma = num_comma + 1;
			if (num_comma == 2)
			{
				trait1.resize(trait1.size() - 1);
				i = allele1.size();
			}
		}
		else if (allele1.at(i) == ' ')
		{
			trait1.clear();
		}
	}
	num_comma = 0;

	for (unsigned int i = 0; i < allele2.size(); i++)
	{
		trait2 = trait2 + allele2.at(i);

		if (allele2.at(i) == ',')
		{
			num_comma = num_comma + 1;
			if (num_comma == 2)
			{
				trait2.resize(trait2.size() - 1);
				i = allele2.size();
			}
		}
		else if (allele2.at(i) == ' ')
		{
			trait2.clear();
		}
	}
};

void Allele::GetTrait2()
{
	//testing for second traits.
	num_comma = 0;

	for (unsigned int i = 0; i < allele1.size(); i++)
	{
		trait1 = trait1 + allele1.at(i);

		if (allele1.at(i) == ',')
		{
			num_comma = num_comma + 1;
			if (num_comma == 4)
			{
				trait1.resize(trait1.size() - 1);
				i = allele1.size();
			}
		}
		else if (allele1.at(i) == ' ')
		{
			trait1.clear();
		}
	}
	num_comma = 0;

	for (unsigned int i = 0; i < allele2.size(); i++)
	{
		trait2 = trait2 + allele2.at(i);

		if (allele2.at(i) == ',')
		{
			num_comma = num_comma + 1;
			if (num_comma == 4)
			{
				trait2.resize(trait2.size() - 1);
				i = allele2.size();
			}
		}
		else if (allele2.at(i) == ' ')
		{
			trait2.clear();
		}
	}
};

void Allele::GetDomin2()
{
	//testing for the second dominances.
	int o = 0;

	for (unsigned int i = 0; i < allele1.size(); i++)
	{
		Dominon1 = Dominon1 + allele1.at(i);

		if (Dominon1 == "Dominant" || Dominon1 == "Recessive")
		{
			o = o + 1;

			if (o == 2)
			{
				i = allele1.size();
			}
			else
			{
				Dominon1.clear();
			}
		}
		else if (allele1.at(i) == ' ')
		{
			Dominon1.clear();
		}
	}
	o = 0;
	for (unsigned int i = 0; i < allele2.size(); i++)
	{
		Dominon2 = Dominon2 + allele2.at(i);

		if (Dominon2 == "Dominant" || Dominon2 == "Recessive")
		{
			o = o + 1;

			if (o == 2)
			{
				i = allele2.size();
			}
			else
			{
				Dominon2.clear();
			}
		}
		else if (allele2.at(i) == ' ')
		{
			Dominon2.clear();
		}
	}
};

void Allele::Mixer()
{
	Allele::GetTrait1();

	Allele::GetDomin1();

	//Randomizer for Expressed trait 1.
	int AlleleGen = 0;

	if (Dominon1 == Dominon2 && Dominon1 == "Recessive")
	{
		AlleleGen = (rand() % 2) + 1;
		Domin = "Recessive";
		if (AlleleGen == 1)
		{
			DomTrait = trait1;
		}
		else
		{
			DomTrait = trait2;
		}
	}
	else if (Dominon1 == Dominon2 && Dominon1 == "Dominant")
	{
		AlleleGen = (rand() % 2) + 1;
		Domin = "Dominant";
		if (AlleleGen == 1)
		{
			DomTrait = trait1;
		}
		else
		{
			DomTrait = trait2;
		}
	}
	else if (Dominon1 == "Dominant")
	{
		AlleleGen = (rand() % 4) + 1;
		if (AlleleGen == 1 || AlleleGen == 2 || AlleleGen == 3)
		{
			DomTrait = trait1;
			Domin = "Dominant";
		}
		else
		{
			DomTrait = trait2;
			Domin = "Recessive";
		}
	}
	else if (Dominon1 == "Recessive")
	{
		AlleleGen = (rand() % 4) + 1;
		if (AlleleGen == 1)
		{
			DomTrait = trait1;
			Domin = "Dominant";
		}
		else
		{
			DomTrait = trait2;
			Domin = "Recessive";
		}
	}

	//setss allelee to first set of data
	allelee = allelee + "Expressed Traits: " + DomTrait + ", " + Domin;

	Allele::GetTrait2();

	Allele::GetDomin2();

	//Randomizer for Expressed trait 2.

	if (Dominon1 == Dominon2 && Dominon1 == "Recessive")
	{
		AlleleGen = (rand() % 2) + 1;
		Domin = "Recessive";
		if (AlleleGen == 1)
		{

			DomTrait = trait1;
		}
		else
		{

			DomTrait = trait2;
		}
	}
	else if (Dominon1 == Dominon2 && Dominon1 == "Dominant")
	{
		AlleleGen = (rand() % 2) + 1;
		Domin = "Dominant";
		if (AlleleGen == 1)
		{

			DomTrait = trait1;
		}
		else
		{

			DomTrait = trait2;
		}
	}
	else if (Dominon1 == "Dominant")
	{
		AlleleGen = (rand() % 4) + 1;
		if (AlleleGen == 1 || AlleleGen == 2 || AlleleGen == 3)
		{

			DomTrait = trait1;
			Domin = "Dominant";
		}
		else
		{

			DomTrait = trait2;
			Domin = "Recessive";
		}
	}
	else if (Dominon1 == "Recessive")
	{
		AlleleGen = (rand() % 4) + 1;
		if (AlleleGen == 1)
		{
			DomTrait = trait1;
			Domin = "Dominant";
		}
		else
		{
			DomTrait = trait2;
			Domin = "Recessive";
		}
	}

	//sets allele to second set of information
	allelee = allelee + ", " + DomTrait + ", " + Domin + " Allele 1: " + allele1 + "Allele 2: " + allele2;
};
