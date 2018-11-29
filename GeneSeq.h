#include <iostream>
#include <vector>

using namespace std;

class GenSeq
{
  private:
	vector<std::string> ChromosomePair;
	string ChromosomeA;
	string ChromosomeB;
	string NewChrome;

  public:
	void Combine();
	void CreateChromosomePair();
	void ExportChromosomePair();

	void Read();

	/*
        // executes all unit tests on each object. Returns true if all tests pass
        bool PowerOnSelfTest();
*/
};
