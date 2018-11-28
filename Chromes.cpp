#include <iostream>
#include <vector>
#include "Chromes.h"
#include "Gene.h"
#include "Allele.h"
#include <fstream>
#include <algorithm>

using namespace std;

void Chromes::Chromesize()
{
	Chromosomes.resize(num_Chrome);
};
void Chromes::Create()
{

	//solve issue of origninal number of Chromosomes.......................................................................................

	string Name;

	cin.clear();
	cin.ignore(1000, '\n');

	if (Chromosomes.size() == 0)
	{
		Chromosomes.resize(1);
	}

	num_Chrome = Chromosomes.size();

	if (num_Chrome >= 23)
	{

		cout << "Max number of Chromosomes made. Please either delete some to create more." << endl;
	}
	else
	{
		int i = 0;
		cout << "How many Chromosomes would you like to have in total? Max you can have is 23. " << endl;
		cin >> i;
		num_Chrome = num_Chrome + i;

		while (num_Chrome > 23 || num_Chrome < Chromosomes.size())
		{
			cout << "Number is too high. You can only have 23 total Chromosomes. Please enter another number. Don't go lower than the current number of Chromosomes. Size is originally set at 1." << endl;
			cout << "Current Size: " << num_Chrome << endl;

			cin >> num_Chrome;
		}

		Chromes::Chromesize();

		cin.clear();
		cin.ignore(1000, '\n');

		if (num_Chrome == 0)
		{
			cout << "Well why did you click create Chromosome?" << endl;
		}
		else
		{
			for (unsigned int y = 0; y < num_Chrome; y++)
			{
				cout << "Please name Chromosome " << y + 1 << "." << endl;
				getline(cin, Name);

				Chromosomes.at(y) = Name;
			}

			for (unsigned int y = 0; y < num_Chrome; y++)
			{

				Gene GE;
				GE.GCreate();
			}
		}
	}
};

void Chromes::Analyze()
{
	string name;
	int leave = 0;
	int found = 0;

	cout << "Please enter the excat name of the Chromosome you would like to look at. If you do not know the name, type \" List \"." << endl;
	getline(cin, name);

	if (name == "List")
	{
		Chromes::List();
	}

	while (leave != 1)
	{
		for (unsigned int i = 0; i < Chromosomes.size(); i++)
		{
			string word = "Hello world. I need this to be long enough so that no name will ever beat me. Hopefully this is long enough.";
			string save = Chromosomes.at(i);

			for (unsigned int f = 0; f < save.size(); f++)
			{
				word = save.at(f);

				if (word == name)
				{
					cout << "Chromosome Found!!" << endl;
					found = i;

					i = Chromosomes.size();
				}
				else if (save.at(f) == ' ')
				{
					word.clear();
				}
			}
		}
		if (found == 0)
		{
			cout << "Name not found. Please try again. If you do not know the name, type \" List \"." << endl;
			getline(cin, name);
		}
		if (name == "List")
		{
			Chromes::List();
		}
	}

	cout << Chromosomes.at(found);

	//need to seperate into line by line................................................................................................................................
};

void Chromes::List()
{
	for (unsigned int i = 0; i < Chromosomes.size(); i++)
	{
		string Name = "";
		string help = Chromosomes.at(i);
		cout << "Chromosome " << i << " name: ";

		for (unsigned int o = 0; o < help.size(); o++)
		{

			if (help.at(o) == ',')
			{
				string rid = "";
				help.resize(o);
				for (unsigned int p = 0; p <= help.size(); p++)
				{
					rid = rid + help.at(p);
					if (rid == "Chromosome: ")
					{
						for (unsigned int l = p; l <= help.size(); l++)
						{
							Name = help.at(l);
						}
					}
				}
			}
		}
	}
};

void Chromes::Output()
{
	string outputfile = "";
	cout << "Pleae enter the file you would like to output your Chromosome to." << endl;
	getline(cin, outputfile);

	string Num = "";
	cout << "Please enter the Chromosome Name or Number you would like to export. If unknown type \"List\"." << endl;
	getline(cin, Num);

	if (isdigit(Num.at(1)) == true)
	{
		//need conversion thing from computer..................................................................................
		int num = Num.at(1);
		ofstream myfile;

		myfile.open(outputfile);
		while (!myfile.is_open())
		{
			cout << "File " << outputfile << " could not open. Please try again." << endl;

			cout << "Please enter the file location of the file containing the genes you would like to import." << endl;
			getline(cin, outputfile);

			myfile.open(outputfile);
		}

		myfile << Chromosomes.at(num);
		myfile.close();
	}
	else
	{
		int found = 0;
		int leave = 0;
		if (Num == "List")
		{
			Chromes::List();
		}
		for (unsigned int i = 0; i < Chromosomes.size(); i++)
		{
			string word = "Hello world. I need this to be long enough so that no name will ever beat me. Hopefully this is long enough.";
			string save = Chromosomes.at(i);

			for (unsigned int f = 0; f < save.size(); f++)
			{
				word = save.at(f);

				if (word == Num)
				{
					cout << "Chromosome Found!!" << endl;
					found = i;

					i = Chromosomes.size();
				}
				else if (save.at(f) == ' ')
				{
					word.clear();
				}
			}
			if (found == 0)
			{
				cout << "Name not found. Please try again. If you do not know the name, type \" List \"." << endl;
				getline(cin, Num);
			}
		}

		if (isdigit(Num.at(1)) == true)
		{
			//need conversion thing from computer..................................................................................
			char x = Num.at(1);
			int num = x - '0';

			ofstream myfile;

			myfile.open(outputfile);
			while (!myfile.is_open())
			{
				cout << "File " << outputfile << " could not open. Please try again." << endl;

				cout << "Please enter the file location of the file containing the genes you would like to import." << endl;
				getline(cin, outputfile);

				myfile.open(outputfile);
			}

			myfile << Chromosomes.at(num);
			myfile.close();
		}
	}
};

void Input()
{

	int option = 0;
	cout << "At what level do you want to import your file to? Chromosome(1)? Gene(2)? Allele(3)?" << endl;
	if (option == 2)
	{
		Gene G;
		G.Import();
	}
	else if (option == 3)
	{
		Allele A;
		A.Import();
	}
	else
	{

		int num_Imports = 0;
		cout << "How many files are you going to import?" << endl;

		cin >> num_Imports;
		cin.clear();
		cin.ignore(1000, '\n');

		for (int i = 0; i < num_Imports; i++)
		{
			cout << endl;
			cout << "Please make sure your file is set up as follows." << endl
				 << endl;
			cout << "Chromosome: Name, # of Genes, " << endl;
			cout << "Gene 1: Gene Name, Body Aspect, " << endl;
			cout << "Allele Sequence: Allele sequence, " << endl;
			cout << "Allele 1: Trait 1, Dominent or Recessive, Trait 2, Dominent or Recessive, " << endl;
			cout << "Allele 2: Trait 1, Dominent or Recessive, Trait1 2, Dominent or Recessive" << endl;
			cout << "Gene 1: Gene Name, Body Aspect" << endl;
			cout << "Allele Sequence: Allele sequence" << endl;
			cout << "Allele 1: Trait 1, Dominent or Recessive, Trait 2, Dominent or Recessive, " << endl;
			cout << "Allele 2: Trait 1, Dominent or Recessive, Trait1 2, Dominent or Recessive" << endl;
			cout << "Etc..." << endl
				 << endl;

			cout << "Don't forget the comma at the end. Also put a space at the end of each line. " << endl;
			cout << "Except don't put a comma or a space on the end of every Allele 2." << endl
				 << endl;

			cout << "Chromosome: Tim, 3." << endl;
			cout << "Gene: CATH, Hair, " << endl;
			cout << "Allele Sequence: BrBR, " << endl;
			cout << "Allele 1: Brown, Dominent, Light, Recessive, " << endl;
			cout << "Allele 2: Brown, Domient, Dark, Domient" << endl;
			cout << "Gene: FEFEFE, Feet, " << endl;
			cout << "Allele Sequence: BbBb." << endl;
			cout << "Allele 1: Wide, Dominent, Flat, Recessive, " << endl;
			cout << "Allele 2: Skinny, Domient, Flat, Recessive" << endl;
			cout << "Gene: EYEE, Eyes, " << endl;
			cout << "Allele Sequence: Eeee, " << endl;
			cout << "Allele 1: Green, Dominent, Light, Recessive, " << endl;
			cout << "Allele 2: Blue, Recessive, Light, Recessive" << endl
				 << endl;

			string Chrome_Line;

			cout << "Please enter the file location of the file." << endl;

			getline(cin, Chrome_Line);
			cin.clear();
			cin.ignore(1000, '\n');

			ifstream myfile;
			myfile.open(Chrome_Line);

			vector<string> test(2);

			while (!myfile.is_open())
			{
				cout << "File " << Chrome_Line << " could not open. Please try again." << endl;

				cout << "Please enter the file location of the file containing the genes you would like to import." << endl;
				getline(cin, Chrome_Line);

				myfile.open(Chrome_Line);
			}
			string line = "";
			getline(myfile, test.at(0));

			char num_Genes = '0';
			line = test.at(0);

			for (unsigned int i = 0; i < line.size(); i++)
			{

				if (isdigit(line.at(i)) == true)
				{
					num_Genes = line.at(i);
				}
			}

			char x = num_Genes;
			int num_total = x - '0';

			num_total = ((num_total * 5) + 1);

			test.resize(num_total);

			int Num = 0;
			while (std::getline(myfile, line))
			{

				Num = Num + 1;

				test.at(Num) = line;
			}

			myfile.close();
		}
	}
};

/*
Need Objects again as Im outputting the data into a file which isn't hard to write, just need the ability to write to another file with reference.

Haven't started. Can do with and without Objects void Combine(){};

Working on.
*/