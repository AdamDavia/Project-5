/*	Project:    NAME OF PROJECT GOES HERE
	Name:       YOUR NAME GOES HERE
    Partner:    PARTNER'S NAME IF ANY
    Class:      example: CSC 1810 - Section 1
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int num_Imports = 0;
	cout << "How many files are you going to import?" << endl;

	//cin >> num_Imports;
	//cin.clear();
	//cin.ignore(1000, '\n');
	num_Imports = 1;

	for (int i = 0; i < num_Imports; i++)
	{
		cout << endl;
		cout << "Please make sure your file is set up as follows." << endl
			 << endl;
		cout << "Chromosome: Name, # of Genes." << endl;
		cout << "Gene 1: Gene Name, Body Aspect, Allele Sequence" << endl;
		cout << "Allele 1: Trait 1, Dominent or Recessive, Trait 2, Dominent or Recessive." << endl;
		cout << "Allele 2: Trait 1, Dominent or Recessive, Trait1 2, Dominent or Recessive." << endl;
		cout << "Gene 1: Gene Name, Body Aspect, Allele Sequence" << endl;
		cout << "Allele 1: Trait 1, Dominent or Recessive, Trait 2, Dominent or Recessive." << endl;
		cout << "Allele 2: Trait 1, Dominent or Recessive, Trait1 2, Dominent or Recessive." << endl;
		cout << "Etc..." << endl
			 << endl;

		cout << "Don't forget the period at the end." << endl
			 << endl;

		cout << "Chromosome: Tim, 3." << endl;
		cout << "Gene: CATH, Hair, BrBR." << endl;
		cout << "Allele 1: Brown, Dominent, Light, Recessive." << endl;
		cout << "Allele 2: Brown, Domient, Dark, Domient." << endl;
		cout << "Gene: FEFEFE, Feet, BbBb." << endl;
		cout << "Allele 1: Wide, Dominent, Flat, Recessive." << endl;
		cout << "Allele 2: Skinny, Domient, Flat, Recessive." << endl;
		cout << "Gene: EYEE, Eyes, Eeee." << endl;
		cout << "Allele 1: Green, Dominent, Light, Recessive." << endl;
		cout << "Allele 2: Blue, Recessive, Light, Recessive" << endl
			 << endl;

		string Chrome_Line;

		cout << "Please enter the file location of the file." << endl;

		Chrome_Line = "/home/student/src/Project_5/test.txt";
		/*getline(cin, Chrome_Line);
		cin.clear();
		cin.ignore(1000, '\n');*/

		ifstream myfile;
		myfile.open(Chrome_Line);

		int num_lines = 1;

		vector<string> test(num_lines);

		while (!myfile.is_open())
		{
			cout << "File " << Chrome_Line << " could not open. Please try again." << endl;

			cout << "Please enter the file location of the file containing the genes you would like to import." << endl;
			getline(cin, Chrome_Line);

			myfile.open(Chrome_Line);
		}

		getline(myfile, test.at(0));

		int num_Genes = 0;

		// atoi() converts a string to an int
		int Help = test.at(0);

		for (unsigned int i = 0; i < test.at(0).size(); i++)
		{
			if (isdigit(Help.at(i)) == true)
			{
				num_Genes = Help.at(i);

				//Im getting the decimal of the number but not the number itself. Solutions?
			}
			cout << Help.at(i);
		}

		//tester statement
		cout << test.at(0) << endl;

		test.resize(num_Genes);

		while (!myfile.eof())
		{
			for (int i = 0; i < num_Genes; i++)
			{
				getline(myfile, test.at(i));
				//How do you collect the next line.
			}
			/*if (std::find(test.at(i).begin(), test.at(i).end(), '.') != test.at(i).end())
			{
				myfile >> test.at(i);
				cout << test.at(i) << endl;
			}*/
		}
		int a = 0;

		while (a != 100)
		{

			cout << test.at(a) << endl;
			cin >> a;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		//home/student/src/Project_5/test.txt

		myfile.close();
	}
	{
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}