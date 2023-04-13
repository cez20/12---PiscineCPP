/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:40:16 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/13 14:40:19 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Maybe there is an easier way to do this
Zombie* zombieHorde(int N, std::string name){

	Zombie* zombie = new Zombie[N]; // Alloue N Objets Zombie en une seule allocation 
	
	for (int i = 0; i < N ; i++)
		zombie[i].setName(name); // Initialise les zombies en donnant a chacun le nom passe en parametre

	return (zombie); // Retourne un pointeur 
}