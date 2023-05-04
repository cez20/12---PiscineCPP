/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:16:22 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/04 13:02:58 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\e[0m"
# define RED "\e[0;31m"

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	{
	std::cout << RED "Initializing HumanA with name and weapon." RESET << std::endl;
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	
	{	
	std::cout << RED "\nInitializing HumanB with name ONLY. Weapon is assigned later in process." RESET << std::endl;
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.attack();

	std::cout << "\n";
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}

	
	return (0);
}