#ifndef SEQUENCEPROCESSOR_HPP
# define SEQUENCEPROCESSOR_HPP

# include <iostream>
# include <string>
# include <list>

class SequenceProcessor
{
	public:

		SequenceProcessor();
		SequenceProcessor( SequenceProcessor const & src );
		~SequenceProcessor();

		SequenceProcessor &		operator=( SequenceProcessor const & rhs );

		void				processUnsortedSequence(int argCount, char **argList);
		std::list<double>	getUnsortedSequence() const;
		void				printUnsortedSequence();
		
		
		// void			printSortedSequence();
		// void			printSortingTimes();

	private:
		std::list<double>					_unsortedSequence;
		// std::list<double>					_sortedSequence; // Replace by _finalSortedSequence?

		double  							stringToDouble(const std::string& s);
		bool 								isValidNumberFormat (const std::string& arg);
		bool 								isBelowIntMax(const std::string& arg);

		// std::clock_t 						_clockStartVector;
		// std::clock_t 						_clockEndVector;
		// std::clock_t 						_clockStartDeque;
		// std::clock_t						_clockEndDeque;

};

#endif /* *********************************************** SEQUENCEPROCESSOR_H */