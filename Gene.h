#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Gene
{
  public:
	void GCreate();
	//void Output();
	//void SetAllele();
	Gene();
	string GetGene();
	void setgene(string inputgene);
	int Creation(int x);
	string gene;
	int num_Genies();

  private:
	int num_Genes;
};
