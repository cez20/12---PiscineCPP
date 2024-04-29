/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:48:46 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/04/28 21:40:25 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef	typename std::stack<T>::container_type::iterator iterator;
		typedef	typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef	typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef	typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		MutantStack();
		MutantStack( MutantStack const & src );
		~MutantStack();

		MutantStack &operator=( MutantStack const & rhs );

		iterator	begin();
    	iterator	end();
};

#endif