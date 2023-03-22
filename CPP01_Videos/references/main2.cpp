/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:16:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/22 12:22:12 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

void	byPtr(std::string* str)
{
	*str += " and ponies";
}

void	byConstPtr(std::string const *str)
{
	std::cout << *str << std::endl;

}

void	byRef(std::string& str)
{
	str += " and ponies:";
}

void	byConstRef(std::string const & str)
{
	std::cout << str << std::endl;
}


int main()
{
	std::string str = "I like butterflies";
	
	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);
	
	str = "I like otters";

	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);

	return (0);
}