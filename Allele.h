#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Allele
{
  public:
	void Create();

  private:
	string sequence;
	string domTrait;
	string trait1;
	string trait2;
	string Dominon1;
	string Dominon2;

	std::vector<std::string> Alleles;
};
