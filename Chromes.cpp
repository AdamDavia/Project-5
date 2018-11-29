#include <iostream>
#include <vector>
#include "Chromes.h"
#include "Gene.h"
#include "Allele.h"
#include <fstream>
#include <algorithm>

using namespace std;

void Chromes::Create()
{

	if (Chromosomes.size() == 0)
	{
		Chromosomes.resize(1);
	}
	string Name;
	cout << "How many chromosomes would you like to create?" << endl;
	cin >> num_Chrome;

	for (unsigned int y = 0; y < num_Chrome; y++)
	{
		cout << "Please name Chromosome " << y + 1 << "." << endl;
		getline(cin, Name);
		cin.clear();
		cin.ignore(1000, '\n');

		Chromosomes.at(y) = Name;

		Gene GE;
		GE.GCreate();
		int x = Genes.size();
		char b = x + '0';
		Chromosome = "Chromosome: " + Name + ", " + b + ", ";
		for (unsigned int i = 0; i < Genes.size(); i++)
		{
			Chromosome = Chromosome + Genes.at(i);
		}
		Chromosomes.push_back(0);
	}
};
void Chromes::Analyze()
{
	if (Chromosomes.size() != 0)
	{
		string name;
		int leave = 0;
		int found = 0;

		cout << "Please enter the excat name of the Chromosome you would like to look at. If you do not know the name, type \"List\"." << endl;

		cin.clear();
		cin.ignore(1000, '\n');
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
						leave = 1;
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
	}
	else
	{
		cout << "There are no current Chromosomes." << endl;
	}
};

void Chromes::List()
{
	if (Chromosomes.size() != 0)
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
	}
	else
	{
		cout << "No Chromosomes currently set." << endl;
	}
};

void Chromes::Validfile()
{

	cout << "Pleae enter the file you would like to open." << endl;
	getline(cin, outputfile);
	cin.clear();
	cin.ignore(1000, '\n');

	ofstream myfile;

	myfile.open(outputfile, ios::app);
	while (!myfile.is_open())
	{
		cout << "File " << outputfile << " could not open. Please try again." << endl;

		cout << "Please enter the file location of the file you would like to open." << endl;
		getline(cin, outputfile);

		myfile.open(outputfile, ios::app);
	}
	myfile.close();
};

void Chromes::Output()
{
	if (Chromosomes.size() != 0)
	{
		int num_exports = 1;
		char answer = 'y';
		while (num_exports > 0)
		{
			Chromes::Validfile();

			GetChrome();
			ofstream myfile;
			myfile.open(outputfile, ios::app);

			myfile << Chromosomes.at(num);

			myfile.close();

			cout << "Is there anymore exports you would like to do? (y/n)" << endl;
			cin >> answer;
			while (answer != 'y' || answer != 'n')
			{
				cout << "Invailid input. Please enter a valid input." << endl;
				cin >> answer;
			}
			if (answer == 'n')
			{
				num_exports = 0;
			}
			else if (answer == 'y')
			{
				cout << "Ok. How many more imports would you like to do?" << endl;
				cin >> num_exports;
			}
		}
	}
	else
	{
		cout << "There are no current Chromosomes." << endl;
	}
};

void Chromes::Input()
{
	vector<string> test(2);

	int num_Imports = 0;
	cout << "How many files are you going to import?" << endl;

	cin >> num_Imports;
	cin.clear();
	cin.ignore(1000, '\n');

	if (num_Imports <= 0 || isdigit(num_Imports) == false)
	{
		cout << "Invalid input. Returning to main menu." << endl;
	}

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
		cout << "Except don't put a comma or a space on the end of every Allele 2." << endl;
		cout << "Make sure not to have anymore lines in your file than the required amount." << endl
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

		Chromes::Validfile();

		ifstream myfile;

		myfile.open(outputfile);

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

	for (unsigned int i = 0; i < test.size(); i++)
	{
		Chromosome = Chromosome + test.at(i);
	}

	Chromosomes.resize(Chromosomes.size() + 1);
	Chromosomes.at(Chromosomes.size() - 1);
};
void Chromes::GetChrome()
{
	int finished = 0;
	entry = 200;
	while (finished != 1)
	{
		if (entry != 200)
		{
			Chromosome = Chromosomes.at(num);
			finished = 0;
			GiveChrome();
		}
		else
		{
			string Num = "";
			cout << "Please enter the Chromosome Name or Number you would like to see. If unknown type \"List\"." << endl;
			getline(cin, Num);
			int leave = 0;
			while (leave != 1)
			{
				if (Num == "List")
				{
					Chromes::List();
					cout << "Please enter the Chromosome Name or Number you would like to export." << endl;
					getline(cin, Num);
					int test1 = 0;
					int test2 = 0;
					while (test1 != 1 || test2 != 1)
					{
						if (isdigit(Num.at(1)) == true)
						{
							char x = Num.at(1);
							num = x - '0';

							if (num > (Chromosomes.size()))
							{
								char x = Num.at(1);
								num = x - '0';

								leave = 1;

								test1 = 1;
							}
							else
							{
								cout << "Your number is too high to be a Chromosome as there is no Chromosome in that spot. Don't forget it starts at zero. Please enter a lower value." << endl;
								getline(cin, Num);
							}
						}
						else
						{

							for (unsigned int i = 0; i < Chromosomes.size(); i++)
							{
								string tester = "";
								string save = Chromosomes.at(i);
								save.resize(17);

								for (unsigned int f = 0; f < save.size(); f++)
								{
									tester = tester + save.at(f);

									if (tester == Num)
									{

										num = i;
										test2 = 1;

										i = Chromosomes.size();
										test2 = 1;
										leave = 1;
									}
									else if (save.at(f) == ' ')
									{
										tester.clear();
									}
								}
							}
						}
					}
				}
				if (leave != 1)
				{
					cout << "Name not found. Please try again. If you do not know the name, type \" List \"." << endl;
					getline(cin, Num);
				}
				entry = 200;
			}
		}
	}
};

string Chromes::GiveChrome()
{
	return Chromosome;
};
void Chromes::GeneList()
{
	Chromes::SetGene();

	for (unsigned int i = 0; i < Genes.size(); i++)
	{
		string Name = "";
		string help = Genes.at(i);
		cout << "Gene " << i << " name: ";

		for (unsigned int o = 0; o < help.size(); o++)
		{

			if (help.at(o) == ',')
			{
				string rid = "";
				help.resize(o);
				for (unsigned int p = 0; p <= help.size(); p++)
				{
					rid = rid + help.at(p);
					if (rid == "Gene: ")
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
void Chromes::SetGene()
{
	Gene G;
	GiveChrome();
	Genes.resize(0);
	string word = "";
	string Phrase = "";
	int x = 0;

	for (unsigned int i = 0; i < Chromosome.size(); i++)
	{
		word = word + Chromosome.at(i);

		if (word == "Gene" && x == 0)
		{
			word.clear();
			x = x + 1;
		}
		else if (word == "Gene" && x == 1)
		{
			word.clear();
			x = 0;
		}

		if (Chromosome.at(i) == ' ')
		{
			word.clear();
		}

		if (x == 1)
		{
			Phrase = Phrase + Chromosome.at(i);
			Genes.push_back(Phrase);
		}
	}
};
void Chromes::FindGene()
{
	Chromes::SetGene();
	string Num = "";
	cout << "Please enter the Gene Name or Number you would like to see. If unknown type \"List\"." << endl;
	getline(cin, Num);
	int leave = 0;
	while (leave != 1)
	{
		if (Num == "List")
		{
			Chromes::GeneList();
			cout << "Please enter the Gene Name or Number you would like to use." << endl;
			getline(cin, Num);
			int test1 = 0;
			int test2 = 0;
			while (test1 != 1 || test2 != 1)
			{
				if (isdigit(Num.at(1)) == true)
				{
					char x = Num.at(1);
					num = x - '0';

					if (num > (Chromosomes.size()))
					{
						char x = Num.at(1);
						num = x - '0';

						leave = 1;

						test1 = 1;
					}
					else
					{
						cout << "Your number is too high to be a Chromosome as there is no Chromosome in that spot. Don't forget it starts at zero. Please enter a lower value." << endl;
						getline(cin, Num);
					}
				}
				else
				{

					for (unsigned int i = 0; i < Chromosomes.size(); i++)
					{
						string tester = "";
						string save = Chromosomes.at(i);
						save.resize(17);

						for (unsigned int f = 0; f < save.size(); f++)
						{
							tester = tester + save.at(f);

							if (tester == Num)
							{

								num = i;
								test2 = 1;

								i = Chromosomes.size();
								test2 = 1;
								leave = 1;
							}
							else if (save.at(f) == ' ')
							{
								tester.clear();
							}
						}
					}
				}
			}
		}
		if (leave != 1)
		{
			cout << "Name not found. Please try again. If you do not know the name, type \" List \"." << endl;
			getline(cin, Num);
		}
		entry = 200;
	}
};

void Chromes::genecall()
{
	Gene G;
	G.setgene(Genes.at(response));
};