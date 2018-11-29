#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Gene
{
  public:
	void GCreate();
	void Output();
	void SetAllele();

	void setgene(string inputgene);

  private:
	int num_Genes;

	string gene;
};
