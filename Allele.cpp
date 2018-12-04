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
		cout << "Please enter the sequence of the allele " << o + 1 << " traits. Should be 2 letters." << endl
			 << endl;
		cout << "This will also automatically set any of the letters that are capitalized to change the trait to Dominant and visa versa." << endl;
		if (o == 1)
		{
			cout << "Make sure that the data you enter into these two traits of this allele correlates to the data of the first otherwise your data will look really wacky." << endl;
			//Shorter way of making a data tester. Can't really test their data without a defined set of parameters for data which were not defined.
		}

		cin >> sequence;
		cin.ignore(1000, '\n');
		cin.clear();

		Allele::Unittest();

		if (isupper(sequence[0]))
		{
			cout << "Ok trait 1 is set to dominant." << endl;
			Dominon1 = "Dominant";
		}
		else
		{
			cout << "Ok trait 1 is set to recessive." << endl;
			Dominon1 = "Recessive";
		}

		if (isupper(sequence[1]))
		{
			cout << "Ok trait 2 is set to dominant." << endl;
			Dominon2 = "Dominant";
		}
		else
		{
			cout << "Ok trait 2 is set to recessive." << endl;
			Dominon2 = "Recessive";
		}

		if (o == 0)
		{
			allelee = "Allele Sequence:" + sequence;
		}
		else
		{
			int i = 0;
			i = allelee.find("Allele Sequence");
			allelee.insert(i, sequence);
		}

		cout << "Ok. Please enter the first trait of the allele." << endl;

		getline(cin, trait1);

		for (unsigned int i = 0; i < trait1.size(); i++)
		{
			if (trait1 == "")
			{
				char ahhhh = 'o';
				cout << "Are you sure you don't want to give this trait a name?(y/n) It will be very hard to read the data." << endl;
				cin >> ahhhh;
				if (ahhhh == 'n')
				{
					cout << "Please enter a trait name." << endl;
					getline(cin, trait1);
				}
				if (ahhhh == 'y')
				{
					cout << "Invalid answer. There has to be a name." << endl;
					cout << "Please enter a trait name." << endl;
					getline(cin, trait1);
				}
			}
		}

		cout << "Ok. Please enter the second trait that correlates with the first trait of the Allele. EX: Dark Brown, Light Brown or Dark Blond, Light Blond." << endl;

		getline(cin, trait2);

		while (trait2 == "")
		{
			char ahhhh = 'o';
			cout << "Are you sure you don't want to give this trait a name?(y/n) It will be very hard to read the data." << endl;
			cin >> ahhhh;
			if (ahhhh == 'n')
			{
				cout << "Please enter a trait name." << endl;
				getline(cin, trait2);
			}
			if (ahhhh == 'y')
			{
				cout << "Invalid answer. There has to be a name." << endl;
				cout << "Please enter a trait name." << endl;
				getline(cin, trait2);
			}
		}

		cout << "Ok Allele " << o + 1 << " of the two made inside of a Gene is done. Here is the information of the first allele. Now to the next allele." << endl;

		cout << "Allele " << o + 1 << ":" << endl;
		cout << "Sequence:   " << sequence << endl;
		cout << "Trait 1:    " << trait1 << endl;
		cout << "Dominance:  " << Dominon1 << endl;
		cout << "Trait 2:    " << trait2 << endl;
		cout << "Dominance:  " << Dominon2 << endl
			 << endl;

		cout << "Allele " << o + 1 << " is done. " << endl;

		if (o == 0)
		{
			allele1 = sequence + ", " + trait1 + ", " + Dominon1 + ", " + trait2 + ", " + Dominon2;
		}
		else
		{
			allele2 = sequence + ", " + trait1 + ", " + Dominon1 + ", " + trait2 + ", " + Dominon2;
		}
		sequence = "";
		trait1 = "";
		trait2 = "";
		Dominon1 = "";
		Dominon2 = "";
	}
	Allele::Mixer();
};
void Allele::Unittest()
{
	int check = 0;
	while (check != 2)
		for (unsigned int i = 0; i < sequence.size(); i++)
		{

			if (isdigit(sequence.at(i)) == true)
			{
				cout << "Please enter only characters in the Allele sequence. Reenter a valid expression." << endl;

				getline(cin, sequence);
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else
			{
				check = 1;
			}
			if (sequence.size() > 2 || sequence.size() < 2)
			{
				cout << "Please enter only 2 characters long in the Allele sequence. Reenter a valid expression." << endl;

				getline(cin, sequence);
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else
			{
				check = check + 1;
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
			Dominon2.clear();
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
	cout << allelee;
};

Allele::Allele(string &allele)
{
	allele1 = "";
	allele2 = "";

	//testing for the alleles
	for (unsigned int i = 0; i < allele.size(); i++)
	{
		allele1 = allele1 + allele.at(i);

		if (allele1 == "1")
		{

			i = allele1.size();
		}
		else if (allele1.at(i) == ' ')
		{
			allele1.clear();
		}
	}
	for (unsigned int i = 0; i < allele2.size(); i++)
	{
		allele2 = allele2 + allele.at(i);

		if (allele2 == "2")
		{
			i = allele2.size();
		}
		else if (allele2.at(i) == ' ')
		{
			allele2.clear();
		}
	}
}
void Allele::GetAllele2()
{
}