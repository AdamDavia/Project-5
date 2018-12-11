#include <iostream>
#include <vector>
#include "Chromes.h"
#include "Gene.h"
#include "Allele.h"
#include <fstream>
#include <algorithm>

using namespace std;

Chromes::Chromes(){};

void Chromes::SetChrome(int x)
{
	Chromosome = Chromosomes.at(x);
}

void Chromes::Create()
{

	string CName;
	cout << "How many chromosomes would you like to create?" << endl;
	string temp;
	getline(cin, temp);

	while (!Check(temp, num_Chrome))
	{
		cout << "Please enter a valid number." << endl;
		getline(cin, temp);
	}

	if (num_Chrome > 0)
	{

		for (int y = 0; y < num_Chrome; y++)
		{

			cout << "Please name Chromosome " << y + 1 << "." << endl;
			getline(cin, CName);

			Gene GE;

			string answer;
			cout << "Do you want any genes with this Chromosome?(y/n)" << endl;
			getline(cin, answer);

			if (answer == "y")
			{
				GE.GCreate();

				string x = to_string(Genes.size());

				Chromosome = "Chromosome: " + CName + ", " + x;
				for (unsigned int i = 0; i < Genes.size(); i++)
				{
					Chromosome = Chromosome + ". " + Genes.at(i);
				}
			}
			else
			{
				Chromosome = "Chromosome: " + CName + " 0.";
			}
			Chromosomes.push_back(Chromosome);
		}
	}
};

void Chromes::Analyze()
{

	if (Chromosomes.size() != 0)
	{
		string thefound = "";
		int leave = 0;
		int found = 0;

		cout << "Please enter the excat name of the Chromosome you would like to look at." << endl;
		cout << "If you do not know the name, type \"List\"." << endl;
		cout << "Or enter \"All\" if you wish to see all of the Chromosomes." << endl;

		while (leave != 1)
		{

			getline(cin, thefound);

			if (thefound == "All")
			{
				for (unsigned int i = 0; i < Chromosomes.size(); i++)
				{
					Chromosome = Chromosome + Chromosomes.at(i);
				}
				string word = "";
				for (unsigned int i = 0; i < Chromosome.size(); i++)
				{

					word = word + Chromosome.at(i);
					if (Chromosome.at(i) == '.')
					{
						cout << word << endl;
						word.clear();
					}
				}
				leave = 1;
			}
			else if (thefound == "List")
			{
				Chromes::List();
				cout << "Please enter a name." << endl;
			}
			else
			{

				for (unsigned int i = 0; i < Chromosomes.size(); i++)
				{
					string word = "";
					string save = Chromosomes.at(i);

					for (unsigned int g = 0; g < save.size(); g++)
					{
						char h = save.at(g);
						if (h == ',')
						{
							g = g - 12;
							word = save.substr(12, g);
							g = save.size();

							if (word == thefound)
							{
								Chromosome = Chromosomes.at(i);
								Chromes::Reader();
								leave = 1;
								found = 1;
							}
						}
					}
				}
				if (found == 0)
				{
					cout << "Name not found. Please try again. If you do not know the name, type \" List \"." << endl;
				}
			}
		}
	}
	else
	{
		cout << "There are no current Chromosomes." << endl;
	}
};

void Chromes::List()
{
	if (Chromes::Sizer() != 0)
	{
		for (unsigned int g = 0; g < Chromosomes.size(); g++)
		{
			string Name = "";
			cout << "Chromosome " << g + 1 << " name: ";
			Name = Chromosomes.at(g);
			for (unsigned int i = 0; i < Name.size(); i++)
			{
				char h = Name.at(i);
				if (h == ',')
				{
					i = i - 12;
					string Nama = Name.substr(12, i);
					cout << Nama;
					i = Name.size();
				}
			}

			cout << endl;
		}
		cout << "End of list." << endl;
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
		string answer = "y";
		while (num_exports > 0)
		{
			Chromosome.clear();
			cout << "Would  you like to create a new file(Create) or use an exisiting file(Use)?" << endl;
			getline(cin, answer);
			while ((answer != "Create") && (answer != "Use"))
			{
				cout << "Invailid input. Please enter a valid input." << endl;
				getline(cin, answer);
			}
			if (answer == "Create")
			{
				cout << "Please enter the name of the file you would like to create.(Whats gonna go before the .txt)" << endl;
				getline(cin, outputfile);
				while (outputfile == "")
				{
					cout << "There needs to be some sorta name for the file you are creating. Please enter one." << endl;
					getline(cin, outputfile);
				}
				Chromes::Analyze();

				ofstream myfile;
				myfile.open(outputfile, ios::app);
				string word = "";
				string statementout = "";
				for (unsigned int i = 0; i < Chromosome.size(); i++)
				{
					word = word + Chromosome.at(i);
					if (Chromosome.at(i) == '.')
					{
						cout << word << endl;
						myfile << word;
						myfile << endl;
						word.clear();
					}
				}
			}
			else if (answer == "Use")
			{
				Chromes::Validfile();
				Chromes::Analyze();
				ofstream myfile;
				myfile.open(outputfile, ios::app);
				string word = "";
				string statementout = "";
				int starting = 0;
				for (unsigned int i = 0; i < Chromosome.size(); i++)
				{
					word = word + Chromosome.at(i);
					if (Chromosome.at(i) == '.')
					{
						cout << word << endl;
						myfile << word << endl;
						word.clear();
						starting = starting + 1;
					}
				}
				myfile.close();
			}
			if (num_exports == 1)
			{
				cout << "Is there anymore exports you would like to do? (y/n)" << endl;
				getline(cin, answer);
				while (answer != "y" && answer != "n")
				{
					cout << "Invailid input. Please enter a valid input." << endl;
					getline(cin, answer);
				}
				if (answer == "n")
				{
					num_exports = 0;
				}
				else if (answer == "y")
				{
					string temp;
					cout << "Ok. How many more Exports would you like to do?" << endl;
					getline(cin, temp);
					while (!Check(temp, num_exports))
					{
						cout << "Please enter a valid number." << endl;
						getline(cin, temp);
					}
					num_exports = num_exports + 1;
				}
			}
			else
			{
				num_exports = num_exports - 1;
			}
		}
	}
	else
	{
		cout << "There are no current Chromosomes." << endl;
	}
};

void Chromes::addgenie(string entrery)
{

	Genes.push_back(entrery);
}

bool Chromes::Check(string test, int &helper)
{
	if (test.size() == 0)
	{
		return false;
	}
	for (unsigned int i = 0; i < test.size(); i++)
	{
		if (!isdigit(test.at(i)))
		{
			return false;
		}
	}
	helper = stoi(test);
	return true;
}
void Chromes::Input()
{

	int num_Imports = 0;
	cout << "How many files are you going to import?" << endl;

	string temp;
	getline(cin, temp);
	while (!Chromes::Check(temp, num_Imports))
	{
		cout << "Please enter a valid number." << endl;
		getline(cin, temp);
	}

	if (num_Imports <= 0 || isdigit(num_Imports) == false)
	{
		cout << "Invalid input. Returning to main menu." << endl;
	}

	for (int i = 0; i < num_Imports; i++)
	{
		cout << endl;
		cout << "Please make sure your file is set up as follows." << endl
			 << endl;
		cout << "Chromosome: Name, # of Genes" << endl;
		cout << "Gene 1: Gene Name, Body Aspect" << endl;
		cout << "Allele Sequence: Allele sequence" << endl;
		cout << "Allele 1: Trait 1, Dominent or Recessive, Trait 2, Dominent or Recessive " << endl;
		cout << "Allele 2: Trait 1, Dominent or Recessive, Trait1 2, Dominent or Recessive" << endl;
		cout << "Gene 1: Gene Name, Body Aspect" << endl;
		cout << "Allele Sequence: Allele sequence" << endl;
		cout << "Allele 1: Trait 1, Dominent or Recessive, Trait 2, Dominent or Recessive" << endl;
		cout << "Allele 2: Trait 1, Dominent or Recessive, Trait1 2, Dominent or Recessive" << endl;
		cout << "Etc..." << endl
			 << endl;

		cout << "Make sure not to have anymore lines in your file than the required amount." << endl;
		cout << "Don't forget a period at the end." << endl;
		cout << "Lastly, make sure to have a sinlge empty line in between each Chromosome if there are multiple." << endl
			 << endl;

		cout << "Chromosome: Tim, 3." << endl;
		cout << "Gene: CATH, Hair." << endl;
		cout << "Allele Sequence: BrBR, " << endl;
		cout << "Allele 1: Brown, Dominent, Light, Recessive." << endl;
		cout << "Allele 2: Brown, Domient, Dark, Domient." << endl;
		cout << "Gene: FEFEFE, Feet." << endl;
		cout << "Allele Sequence: BbBb." << endl;
		cout << "Allele 1: Wide, Dominent, Flat, Recessive." << endl;
		cout << "Allele 2: Skinny, Domient, Flat, Recessive." << endl;
		cout << "Gene: EYEE, Eyes." << endl;
		cout << "Allele Sequence: Eeee" << endl;
		cout << "Allele 1: Green, Dominent, Light, Recessive." << endl;
		cout << "Allele 2: Blue, Recessive, Light, Recessive." << endl
			 << endl;

		cout << "Chromosome: John, 3." << endl;
		cout << "etc..." << endl
			 << endl;

		string Chrome_Line;

		Chromes::Validfile();

		Chromes::Inputtester();
	}
};

void Chromes::Inputtester()
{

	vector<string> test(2);

	ifstream myfile;

	myfile.open(outputfile);

	int num_addChrome;

	cout << "How many Chromosomes are in this file? " << endl;

	string temp;
	getline(cin, temp);

	while (!Chromes::Check(temp, num_addChrome))
	{
		cout << "Please enter a valid number." << endl;
		getline(cin, temp);
	}

	test.resize(num_addChrome + (1 * (num_addChrome - 1)));

	string line = "";
	int num_commas = 0;
	unsigned int num_line = test.size();
	getline(myfile, line);
	int startfile = 0;

	while (num_addChrome > 0)
	{
		if (line.find("Chromosome:") != string::npos)
		{
			for (unsigned int i = 0; i < line.size(); i++)
			{

				if (isdigit(line.at(i)) == true)
				{

					if (startfile == 0)
					{
						num_line = test.size();
						startfile = 1;
					}

					if (startfile == 1)
					{
						char num_Genes = line.at(i);
						char x = num_Genes;
						num_line = x - '0';

						num_line = (num_line * 5) + test.size();
						if (num_line != test.size())
						{
							test.resize(num_line);
						}
						else
						{
							num_Genes = line.at(i);
						}
					}
				}
			}
			num_addChrome = num_addChrome - 1;
		}

		std::getline(myfile, line);
	}

	myfile.close();

	myfile.open(outputfile);

	int Num = 0;
	while (std::getline(myfile, line))
	{

		test.at(Num) = line;
		Num = Num + 1;
	}

	num_line = num_addChrome - 1;

	int allset = 1;

	int what = 0;
	unsigned int where = 0;

	line = test.at(0);

	for (unsigned int i = 0; i < line.size(); i++)
	{

		if (isdigit(line.at(i)) == true)
		{
			char y = line.at(i);
			char x = y;
			num_line = x - '0';
		}
	}

	for (unsigned int i = 0; i < test.size(); i++)
	{

		num_commas = 0;
		line = test.at(i);

		if ((what == 7) && (line.at(1) != ' ') && (line.size() != 0))
		{

			what = 0;
			cout << "There is an line where there should be an empty space at line " << where << "." << endl;
			allset = 0;
		}
		else if (line.size() == 0)
		{
			line = test.at(i + 1);
			if (line.find("Chromosome:") != string::npos)
			{
				for (unsigned int i = 0; i < line.size(); i++)
				{

					if (isdigit(line.at(i)) == true)
					{
						char y = line.at(i);
						char x = y;
						num_line = x - '0';
					}
				}
			}
			line = test.at(i);
			what = 0;
		}
		else if (line.size() > 0)
		{

			for (unsigned int o = 0; o < line.size(); o++)
			{
				if (line.at(o) == ',')
				{
					num_commas = num_commas + 1;
				}
			}
			if (((what == 0) && (line.find("Chromosome:") == string::npos)) || ((what == 0) && (num_commas != 1)))
			{
				cout << "You've imported an improper file. Please fix your file and try again." << endl;
				cout << "You have an error in a Chromosome line input at " << where << "." << endl;
				allset = 0;
			}
			else if (((what == 1) && (line.find("Gene:") == string::npos)) || ((what == 1) && (num_commas != 1)))
			{
				cout << "You've imported an improper file. Please fix your file and try again." << endl;
				cout << "You have an error in a Gene line input at " << where << "." << endl;
				allset = 0;
			}
			else if (((what == 2) && (line.find("Allele Sequence:") == string::npos)) || ((what == 2) && (num_commas != 0)))
			{
				cout << "You've imported an improper file. Please fix your file and try again." << endl;
				cout << "You have an error in a Allele Sequence line input at " << where << "." << endl;
				allset = 0;
			}
			else if (((what == 3) && (line.find("Expressed Traits:") == string::npos)) || ((what == 3) && (num_commas != 3)))
			{
				cout << "You've imported an improper file. Please fix your file and try again." << endl;
				cout << "You have an error in a Expressed Triats:" << where << "." << endl;
				allset = 0;
			}
			else if (((what == 4) && (line.find("Allele 1:") == string::npos)) || ((what == 4) && (num_commas != 3)))
			{
				cout << "You've imported an improper file. Please fix your file and try again." << endl;
				cout << "You have an error in a Allele 1:" << where << "." << endl;
				allset = 0;
			}
			else if (((what == 5) && (line.find("Allele 2:") == string::npos)) || ((what == 5) && (num_commas != 3)))
			{
				cout << "You've imported an improper file. Please fix your file and try again." << endl;
				cout << "You have an error in a Allele 2:" << where << "." << endl;
				allset = 0;
			}

			if (what == 5)
			{
				what = 0;
				num_line = num_line - 1;
			}

			if ((what == 1) && (num_line == 0))
			{
				what = 7;
			}
			else
			{
				what = what + 1;
			}
		}

		where = where + 1;
	}

	if (allset == 1)
	{
		myfile.close();
		cout << "Here is your file data: " << endl;

		for (unsigned int i = 0; i < test.size(); i++)
		{
			Chromosome = Chromosome + test.at(i);
			cout << test.at(i) << endl;
		}

		Chromosome.clear();
		Chromosome = test.at(0);

		for (unsigned int i = 1; i < test.size(); i++)
		{
			line = test.at(i);

			if (line.find(":") == string::npos || i == test.size() - 1)
			{

				Chromosome = Chromosome + test.at(i);
				Chromosomes.push_back(Chromosome);
				Chromosome.clear();
			}
			else
			{
				Chromosome = Chromosome + test.at(i);
			}
		}
	}
	else
	{
		cout << "Please fix these errors and try again. Returning to main menu." << endl;
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
		string help = Chromosome;
		cout << "Gene " << i << " name: ";

		for (unsigned int o = 0; o < Chromosome.size(); o++)
		{

			if (help.at(o) == ',')
			{
				string rid = "";
				help.resize(o);
				for (unsigned int p = 0; p <= help.size(); p++)
				{
					rid = rid + help.at(p);
					if (rid.find("Gene") != string::npos)
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

void Chromes::genecall()
{
	Gene G;
	G.setgene(Genes.at(response));
};
void Chromes::Reader()
{

	string word = "";
	string statementout = "";
	for (unsigned int i = 0; i < Chromosome.size(); i++)
	{
		word = word + Chromosome.at(i);
		if (Chromosome.at(i) == '.')
		{
			cout << word << endl;
			word.clear();
		}
	}
};

int Chromes::Sizer()
{
	return Chromosomes.size();
}

void Chromes::SetGene()
{
	int found = 0;
	int whatgene = 0;
	string genestring;
	int num_periods = 0;
	for (unsigned int i = 0; i < Chromosome.size(); i++)
	{
		genestring = genestring + Chromosome.at(i);
		if (isdigit(Chromosome.at(i)) && found == 0)
		{
			char x = Chromosome.at(i);
			int xx = x - '0';
			found = 1;
			Genes.resize(0);
			Genes.resize(xx);
		}
		else if (Chromosome.at(i) == '.')
		{
			num_periods = num_periods + 1;
		}
		if (num_periods == 1 && found == 1)
		{
			genestring.clear();
			found = 2;
			num_periods = 0;
		}
		else if (num_periods == 5)
		{
			Genes.at(whatgene) = genestring;
			whatgene = whatgene + 1;
			genestring.clear();
			num_periods = 0;
		}
	}
};
void Chromes::FindGene(string &Num)
{
	int leave = 1;
	string Phrase = "";

	for (unsigned int i = 0; i < Genes.size(); i++)
	{
		if (Genes.at(i).find(Num) != string::npos)
		{
			entry = i;
			leave = 0;
		}
	}

	if (leave != 0)
	{
		cout << "Part not found. Please try again." << endl;
	}
};

void Chromes::CreateChromosomePair()
{

	Chromes::List();
	cout << "Please enter in the number of the first Chromosome you would like to use." << endl;
	string temp = "";
	int xx = 0;
	int xxx = 0;
	getline(cin, temp);

	while (!Chromes::Check(temp, xx) && xx > Chromes::Sizer() && xx < 1)
	{
		cout << "Please enter a valid number." << endl;
		getline(cin, temp);
	}

	temp = "";

	cout << "Please enter in the number of the Second Chromosome you would like to use." << endl;
	getline(cin, temp);

	while (!Chromes::Check(temp, xxx) && xxx > Chromes::Sizer() - 1)
	{
		cout << "Please enter a valid number." << endl;
		getline(cin, temp);
	}

	cout << "Please enter the Part that both Genes modify. " << endl;
	getline(cin, NewChrome);

	xx = xx - 1;
	xxx = xxx - 1;

	if (Chromosomes.at(xx).find(NewChrome) == string::npos || Chromosomes.at(xxx).find(NewChrome) == string::npos)
	{
		cout << "Both Chromosomes must have Gene part to Mix. Please create two chromosomes with the same excat Part name and try again." << endl;
	}
	else
	{
		Chromes::SetChrome(xx);
		Chromes::SetGene();
		Chromes::FindGene(NewChrome);
		ChromosomeA = Genes.at(entry);

		entry = 0;

		Chromes::SetChrome(xxx);
		Chromes::SetGene();
		Chromes::FindGene(NewChrome);
		ChromosomeB = Genes.at(entry);

		Combine();
		ExportChromosome();
	}
};

void Chromes::Combine()
{
	string all = ChromosomeA + ChromosomeB;
	Allele A;
	A.setAllele1(all);

	Chromes::ExportChromosome();
};

void Chromes::ExportChromosome()
{
	string name = "";
	string Newboy = "";

	cout << "Please name your new Chromosome." << endl;
	getline(cin, name);

	Newboy = "Chromosome: " + name + ", 1.";

	cout << "Please give your Gene a sequence." << endl;
	getline(cin, name);

	Newboy = Newboy + "Gene: " + name + ", " + NewChrome + ".";

	Allele A;
	string expert1 = A.NewGene();
	string expert2 = A.NewGeus();
	cout << "and Here are your two alleles." << endl;
	cout << expert1 << endl;
	cout << expert2 << endl;

	Newboy = Newboy + "Allele 1: " + A.NewGene() + "." + "Allele 2: " + A.NewGeus() + ".";
};
