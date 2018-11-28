#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Chromes
{
  private:
	unsigned int num_Chrome;
	vector<std::string> Chromosomes;
	string Chromosome;
	vector<std::string> Genes;

	string GetChromosome();
	int entry();
	int num;

  public:
	void Create();
	void List();
	void Analyze();

	void Output();

	void Input();
};
