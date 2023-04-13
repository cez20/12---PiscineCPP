/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:33:59 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/24 12:53:44 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main()
{
	Zombie* first = newZombie("Cesar");
	Zombie* second = newZombie("Rene ");

	std::cout << "\nEach Zombie will introduce themselves with member function announce():" << std::endl;
	first->announce();
	second->announce();

	std::cout << "\nCalling the randomChump() function that creates a Zombie and immediately called function announce()" << std::endl;
	std::cout << "Destructor is also called, because object is not returned in function. Therefore lifetime of object ends\n" << std::endl;
	randomChump("Louis");
	randomChump("Robert");

	std::cout << "\nDelete (free) memory of Zombie* (pointers) to make sure that destructor is called" << std::endl;
	delete first;
	delete second;

	return (0);
}