#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>

class PMergeMe
{

	public:

		PMergeMe();
		PMergeMe( PMergeMe const & src );
		~PMergeMe();

		PMergeMe &		operator=( PMergeMe const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, PMergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */