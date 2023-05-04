/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:33:59 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/04 12:08:31 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* first = newZombie("Cesar");
	Zombie* second = newZombie("Rene");

	// Zombies use annouce() function to introduce themselves
	std::cout << std::endl;
	first->announce();
	second->announce();

	// RandomChump creates a new zombie, calls announce() and are deleted
	std::cout << std::endl;
	randomChump("Louis");
	randomChump("Robert");

	std::cout << std::endl;
	delete first;
	delete second;

	return (0);
}