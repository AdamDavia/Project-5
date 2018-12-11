#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Chromes
{
  private:
	int num_Chrome;

	string Chromosome;

	void TesterList();
	int entry;
	void Inputtester();
	vector<std::string> ChromosomePair;
	vector<std::string> Chromosomes;
	string ChromosomeA;
	string ChromosomeB;
	string NewChrome;

  public:
	void Combine();
	void CreateChromosomePair();
	void ExportChromosome();

	Chromes();
	void addgenie(string entrery);
	bool Check(string test, int &helper);
	void CheckfileData();
	vector<std::string> Genes;
	int response;
	string outputfile;
	void SetGene();
	void genecall();
	void Validfile();
	void FindGene(string &testering);
	void GeneList();
	unsigned int num;
	string GiveChrome();
	void Create();
	void List();
	void Analyze();
	void Output();
	void Input();
	void Reader();
	int Sizer();
	void SetChrome(int x);
};
