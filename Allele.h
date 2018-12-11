#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Allele
{
  public:
	void Create();
	void Mixer();
	void Mixer2();
	void GetTrait1();
	void GetTrait2();
	void GetDomin1();
	void GetDomin2();
	void Unittest();
	string GetAllelee();
	void Output();
	void setAllele1(string &all);
	void setAllele2(string &all);

	Allele();
	string NewGene();
	string NewGeus();

  private:
	string Store;
	int num_comma;
	string sequence;
	string trait1;
	string trait2;
	string Dominon1;
	string Dominon2;

	string allele1;
	string allele2;

	string allelee;

	string DomTrait;
	string Domin;
};
