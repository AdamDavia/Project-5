
/*

Menu

⦁	1 – Create chromosome
⦁	2 – Analyze chromosome
⦁	3 – Output chromosome to file
⦁	4 – Input chromosome from file
⦁	5 – Combine chromosomes
⦁	6 – Exit

Gene Output

Gene 1

⦁	Name:			     	       UH56
⦁	Genetic trait:			Hair color
⦁	Expressed allele:		   Dark – dominant
⦁	Nucleotide sequence:		CATGTAC
etc....

Types of Genees

<gene name>, <gene trait>, <alleleA variant>, <alleleA type>, <alleleA nucleotide sequence>, <alleleB variant>, <allele type>,<alleleB nucleotide sequence>
UH56,hair color,blonde,recessive,TTCC,Dark,dominant,CCAGG
WPM987,Cancer-L,High,recessive,TCGC,Low,dominant,CATGG

Allele

Goes in private

Classes should be hidden

*/

/*
class GeneSequencer{
    public:
        // default constructor
        ChromosomePair  CreateChromosomePair();

        // returns a chromosome object from data in 'filename'
        ChromosomePair  ImportChromosomePair(const string& fileName = "");

        // saves chromosome 'c' data to file 'filename'
        void ExportChromosomePair(ChromosomePair c, const string& fileName = "");

        // returns chromosome from 'x' and 'y' genes - allele selection is random
        ChromosomePair  DoMeiosis(ChromosomePair x, ChromosomePair y);

        // outputs genotype (dominant alleles for each gene) in 'c'
        void SequenceChromosomePair(ChromosomePair c);

        // executes all unit tests on each object. Returns true if all tests pass
        bool PowerOnSelfTest();

class ChromosomePair{
    public:
        // default constructor
        ChromosomePair();

        // outputs genotype which is each dominant allele in each gene
        void AnalyzeGenotype();     

        // configures this chromosome with data from filestream 'ifs'
        void    InputFromFile(ifstream& ifs);

        // writes the state data from this chromosome to filestream 'ofs'
        void    OutputToFile(ofstream& ofs);

        // adds a new Gene object 'g' to a collection in this object
        void    AddGene(Gene g);

        // returns a Gene object that matches a Gene with name 'n'
        Gene    FindGene(string n);

        // returns a chromosome that is a recombination of one Allele from each of two genes - random selection
        ChromosomePair operator+(ChromosomePair rhs);

        bool RunUnitTests();

    private:

        vector<Gene>    genes;
        string          fileName;
};

*/