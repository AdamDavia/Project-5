#include <iostream>
#include <vector>

using namespace std;

class GenSeq
{
	/* public :
         // default constructor
        ChromosomePair  CreateChromosomePair();

	         // returns a chromosome object from data in 'filename'
        ChromosomePair  ImportChromosomePair(const string &fileName = "");

	         // saves chromosome 'c' data to file 'filename'
        void ExportChromosomePair(ChromosomePair c, const string &fileName = "");

	         // returns chromosome from 'x' and 'y' genes - allele selection is random
        ChromosomePair  DoMeiosis(ChromosomePair x, ChromosomePair y);

	  // outputs genotype (dominant alleles for each gene) in 'c'
        void SequenceChromosomePair(ChromosomePair c);

	    // executes all unit tests on each object. Returns true if all tests pass*/
};

class ChromosomePair
{
	/*
public :
// default constructor
ChromosomePair();

	         // outputs genotype which is each dominant allele in each gene
        void AnalyzeGenotype();
	     

         // configures this chromosome with data from filestream 'ifs'
        void    InputFromFile(ifstream &ifs);

	         // writes the state data from this chromosome to filestream 'ofs'
        void    OutputToFile(ofstream &ofs);

	         // adds a new Gene object 'g' to a collection in this object
        void    AddGene(Gene g);

	         // returns a Gene object that matches a Gene with name 'n'
        Gene    FindGene(string n);

	         // returns a chromosome that is a recombination of one Allele from each of two genes - random selection
        ChromosomePair operator+(ChromosomePair rhs);

	        bool RunUnitTests();

	    private :

        vector<Gene>    genes;
	        string          fileName;

Implement unit tests for each class.
Implement a “POST” or PowerOnSelfTest() in the GeneSequencer class that will call each classes unit tests.
Separate each class into its own header (.h) and implementation (.cpp) file with correct header guards
Archive project to your github account

	*/
};
