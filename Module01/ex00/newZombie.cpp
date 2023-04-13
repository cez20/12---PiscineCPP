/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:39:19 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/23 18:06:35 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

//1 - Je cree un nouvelle instance de Zombie
//2 - Le constructeur de Zombie prend un nom, je lui donc le nom passe en pa

//1ere facon de faire plus decortique
Zombie*	newZombie(std::string name){

	Zombie* zombie = new Zombie(name);
	return (zombie);
}

// Autre facon de faire plus claire 
// Zombie*	newZombie(std::string name){

// 	return (new Zombie(name))
// }
