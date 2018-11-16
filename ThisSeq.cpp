#include <iostream>
#include <vector>
#include "GeneSeq.h"

using namespace std;

void GeneSeq::Create()
{
	int num_Chrome = 0;
	string Name;
	int num_Genes;

	if (num_Chrome == 23)
	{

		cout << "Max number of Chromosomes made. Please either delete some to create more." << endl;
	}
	else
	{

		cout << "Please name your Chromosome." << endl;
		getline(cin, Name);

		cout
			<< "How many Genes do you want this Chromosome to have?" << endl;
		cin >> num_Genes;

		for (int i = 0; i <= num_Genes; i++)
		{
			char Pre_Gene;
			cout << "Do you have a file with Genes already made? (y/n)" << endl;
			cin >> Pre_Gene;

			while (Pre_Gene == 'y')
			{

				//how to import txt files

				cout << "Is there any more Genes you would like to import?(y/n)" << endl;
				cin >> Pre_Gene;
			}

			if (Pre_Gene == 'n')
			{
				cout << "Ok. We will have to make some Genes then. We have to make " << num_Genes << "." << endl;

				string AlleleSeq;
				vector<string> Sequence(0);
				vector<string> BodyPart(0);
				vector<string> Trait1(0);
				vector<string> Trait2(0);
				vector<string> Dominance1(0);
				vector<int> Dominon1(0);
				vector<string> Dominance2(0);
				vector<int> Dominon2(0);
				int Alleles = 1;

				for (int i = 0; i <= num_Genes; i++)
				{
					char B;
					cout << "We have to make " << num_Genes << " genes. You sure you want to make this many?(y/n)" << endl;
					cin >> B;
					for (int y = 0; y <= Alleles; y++)
					{
						if (B == 'n')
						{
							cout << "Ok please enter the number of genes you would like to create." << endl;
							cin >> num_Genes;
						}
						else if (B != 'n' || B != 'y')
						{
							while (B != 'n' || B != 'y')
							{
								cout << "Invalid Input. Please enter y or n." << endl;
								cin >> B;
							}
						}
						else if (B == 'y')
						{
							string A;
							cout << "Ok. If you would ever like to change the total number of Genes just say the character \" z \".  Please enter the Allele Sequence." << endl;
							while (A != "z")
							{
								string part;
								string trait;
								char C;

								getline(cin, A);
								getline(cin, AlleleSeq);
								Sequence.push_back(0);
								Sequence.at(0) = AlleleSeq;

								cout << "Ok. Please enter an aspect of the body." << endl;
								getline(cin, A);
								BodyPart.push_back(0);
								getline(cin, part);
								BodyPart.at(0) = part;

								cout << "Ok. Please enter the first aspect of the " << BodyPart.at(0) << "." << endl;
								getline(cin, A);
								getline(cin, trait);
								Trait1.at(0) = trait;
								Trait1.push_back(0);
								trait = "";

								cout << "Ok. Please enter whether it is dominant(1) or recessive(2). " << endl;
								cin >> C;
								getline(cin, A);
								if (C == 1)
								{
									cout << "Ok trait 1 is set to dominant." << endl;
									Dominance1.push_back(0);
									Dominon1.push_back(0);
									Dominance1.at(0) = "Dominant";
									Dominon1.at(0) = 1;
								}
								else if (C == 2)
								{
									cout << "Ok trait 1 is set to recessive." << endl;
									Dominance1.push_back(0);
									Dominon1.push_back(0);
									Dominance1.at(0) = "Recessive";
									Dominon1.at(0) = 2;
								}
								else
								{
									while (C != 1 || C != 2)
									{
										cout << "Invalid Input. Please enter 1 or 2." << endl;
										cin >> C;
										getline(cin, A);
										cout << "Ok trait 1 is set to " << C << "." << endl;
									}
								}
								C = 0;

								cout << "Ok. Please enter the second trait that correlates with the first trait of the Allele. EX: Dark Brown, Light Brown or Dark Blond, Light Blond." << endl;
								getline(cin, A);
								getline(cin, trait);
								Trait2.at(0) = trait;
								Trait2.push_back(0);
								trait = "";

								cout << "Ok. Please enter whether it is dominant(1) or recessive(2). " << endl;
								cin >> C;
								getline(cin, A);

								if (C == 1)
								{
									cout << "Ok trait 2 is set to dominant." << endl;
									Dominance2.push_back(0);
									Dominon2.push_back(0);
									Dominance2.at(0) = "Dominant";
									Dominon2.at(0) = 1;
								}
								else if (C == 2)
								{
									cout << "Ok trait 2 is set to recessive." << endl;
									Dominance2.push_back(0);
									Dominon2.push_back(0);
									Dominance2.at(0) = "Recessive";
									Dominon2.at(0) = 2;
								}
								else
								{
									while (C != 1 || C != 2)
									{
										cout << "Invalid Input. Please enter 1 or 2." << endl;
										cin >> C;
										getline(cin, A);
										cout << "Ok trait 1 is set to " << C << "." << endl;
									}
								}
								C = 0;

								cout << "Ok allele " << y + 1 << " of the two made inside of a Gene. Here is the information of the first allele. Now to the next allele." << endl;

							}
						}
					}
				}
			}
			else
			{
				while (Pre_Gene != 'n' || Pre_Gene != 'y')
				{
					cout << "Invalid Input. Please enter y or n." << endl;
					cin >> Pre_Gene;
				}
			}
		}
	}
}
/*
void Analyze(){};
void Output(){};
void Input(){};
void Combine(){};
*/