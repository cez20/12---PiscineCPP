/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/11/23 20:34:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <list>

template < typename T >
void easyfind(T const & a, int const & b)
{
	std::list<int>::const_iterator it;
    std::list<int>::const_iterator ite = a.end();

	for(it = a.begin(); it != ite; ++it)
    {
        if (*it == b)
		{
			std::cout << *it << std::endl;
			return; 
		}
	}
	throw("Message error");
}

#endif
