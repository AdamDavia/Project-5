#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Chromes
{
  private:
	vector<std::string> Chromosomes;
	unsigned int num_Chrome;

  public:
	void Chromesize();
	void Create();
	void List();
	void Analyze();

	void Output();

	void Input();
	/*
	void Combine();
*/
};
