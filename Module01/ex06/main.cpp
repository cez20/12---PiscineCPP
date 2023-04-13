/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:37:36 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/02 22:02:47 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	level;
	
	if (argc != 2)
	{
		std::cout << "The program must take ONLY 1 command-line argument" << std::endl;
		return (-1);
	}
	
	for (size_t i = 0; i < strlen(argv[1]); i++)
		level += toupper(argv[1][i]);
	harl.complain(level);
		
	return (0);
}