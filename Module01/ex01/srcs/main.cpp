/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:56:01 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/04 12:29:16 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\e[0m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define CYN "\e[0;36m"
# define YEL "\e[0;33m"
# define REDB "\e[41m"

#include "Zombie.hpp"

int main()
{
	std::cout << RED "Initializing horde of 10 zombies. Zombies' names are Cesar" RESET << std::endl;
	Zombie *zombie;
	zombie = zombieHorde(10, "Cesar"); 

	std::cout << RED "\nEach zombie introduce itself with announce()" RESET << std::endl;
	for (int i = 0; i < 10 ; i++)
		zombie[i].announce();
	
	std::cout << RED "\nFreeing all zombies allocated on heap" RESET << std::endl;
	delete[] zombie; 
	
	return (0);
}