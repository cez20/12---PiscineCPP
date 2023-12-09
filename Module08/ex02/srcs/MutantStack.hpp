#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>


template <typename T>
class MutantStack: public std::stack<T>
{
	public:

		MutantStack();
		MutantStack( MutantStack const & src );
		~MutantStack();

		MutantStack &								operator=( MutantStack const & rhs );

		std::stack<T>::container_type::iterator		begin();
		std::stack<T>::container_type::iterator		end();
};

#endif /* ***************************************************** MUTANTSTACK_H */