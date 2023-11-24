/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/11/23 21:05:51 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template < typename T >
void easyfind(T a, int b)
{
	typename T::iterator res = std::find(a.begin(), a.end(), b);

	// if(std::find(a.begin(), a.end(), b) != a.end())
	// 	std::cout << "Value " << b << " was found!"<< std::endl;
	if(res != a.end())
		std::cout << "Value " << b << " was found!"<< std::endl;
	else
		std::cout << "Value " << b << " was NOT found!"<< std::endl;
}

#endif
