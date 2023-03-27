/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:56:01 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/27 15:04:04 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombie;

	zombie = zombieHorde(10, "Cesar"); // Appelle la fonction zombiehorde

	for (int i = 0; i < 10 ; i++)
		zombie[i].announce();
	
	delete[] zombie; // Delete an array of zombies on the heap. 

	return (0);
}