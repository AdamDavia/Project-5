#include <iostream>
#include <vector>
#include "Chromes.h"
#include "Gene.h"
#include <fstream>
#include <algorithm>

using namespace std;
//Chrome::Chrome(){};
void Chrome::Create()
{

	string Name;

	cin.clear();
	cin.ignore(1000, '\n');

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

		Chromes.resize(num_Chrome);

		while (num_Chrome > 23)
		{
			cout << "Number is too high. You can only have 23 total Chromosomes. Please enter another number." << endl;

			cin >> num_Chrome;
		}

		cin.clear();
		cin.ignore(1000, '\n');

		if (num_Chrome == 0)
		{
			cout << "Well why did you click create Chromosome?" << endl;
		}
		else
		{
			for (int y = 0; y < num_Chrome; y++)
			{
				cout << "Please name Chromosome " << y + 1 << "." << endl;
				getline(cin, Name);

				Chromes.at(y) = Name;
			}

			for (int y = 0; y < num_Chrome; y++)
			{

				Gene GE;
				GE.GCreate();
			}
		}
	}
};

/*
Need to understand objects to run this class.
void Analyze(){};

Need Objects again as Im outputting the data into a file which isn't hard to write, just need the ability to write to another file with reference.
void Output(){};

Haven't started. Can do with and without Objects
void Combine(){};



Working on.
void Input()
{};*/
