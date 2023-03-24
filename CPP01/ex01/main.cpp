/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:56:01 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/24 14:25:41 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

//Objectif
//1- Creer une horde de Zombie avec la fonction suivante --> Zombie* zombieHorde( int N, std::string name )
//2- LA fonction doit allour N zombie en une seule allocation (Tres important = une seule allocation)
//3- Elle doit initialiser les zombies en donnant a chacun le nom passe en parametres
//4- Elle retourn un pointeur sur le PREMIER zombie
//5- Tester
// -  La fonction ZombieHorde fonctionne correctement
// -  Essayer d'appeler annouce() pour chacun des Zombie cree
// -  Delete chacun des zombies
// - Aucun leak 

int main()
{
	Zombie *zombie;

	zombie = zombieHorde(10, "Cesar");

	delete[] zombie; // Delete an array of zombies on the heap. 

	return (0);
}