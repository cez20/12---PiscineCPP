#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <deque>
# include <algorithm>

class PMergeMe
{
	public:
		PMergeMe();
		PMergeMe( PMergeMe const & src );
		~PMergeMe();

		PMergeMe &		operator=( PMergeMe const & rhs );
		void			processArguments(int argCount, char **argList);
		void			initializeContainers();
		void			mergeInsertionSort();
		void			recursiveSortPairs(int n);

		void			printInitialIntSequence();
		void			printSequenceAfterSort();

	private:
		std::clock_t 			_start;
		std::vector<double>		_myVector;    // sortedIntSequence1
		std::deque<double>		_myDeque;    // sortedIntSequence2;  
		std::list<double>		_initialIntSequence;  // TODO: Should I call it int sequence or double sequence
		// size_t					_myVectorSortTime;
		// size_t					_myDequeSortTime;
};

double  stringToDouble(const std::string& s);
bool 	isValidNumberFormat (const std::string& arg);
bool 	isBelowIntMax(const std::string& arg);



#endif /* ******************************************************** PMERGEME_H */