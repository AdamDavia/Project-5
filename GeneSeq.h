#include <iostream>
#include <vector>

using namespace std;

class GenSeq
{
  private:
	vector<std::string> ChromosomePair;

  public:
	void Combine();
	void CreateChromosomePair();
	void ExportChromosomePair();

	void OutputOrigins();
	void Read();

	/*
        // executes all unit tests on each object. Returns true if all tests pass
        bool PowerOnSelfTest();
*/
};

/*

Implement unit tests for each class.
Implement a “POST” or PowerOnSelfTest() in the GeneSequencer class that will call each classes unit tests.
Separate each class into its own header (.h) and implementation (.cpp) file with correct header guards
Archive project to your github account

	*/
