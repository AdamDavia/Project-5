#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Chromes
{
  private:
	unsigned int num_Chrome;

	string Chromosome;
	vector<std::string> Chromosomes;
	void TesterList();
	int entry;
	void Inputtester();

  public:
	void
	CheckfileData();
	vector<std::string> Genes;
	int response;

	string outputfile;
	void SetGene();

	void genecall();

	void Validfile();
	void GetChrome();
	void FindGene();
	void GeneList();
	unsigned int num;
	string GiveChrome();
	void Create();
	void List();
	void Analyze();

	void Output();

	void Input();
};
