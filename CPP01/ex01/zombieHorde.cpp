/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:48:41 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/24 14:27:43 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

// Maybe there is an easier way to do this
Zombie* zombieHorde(int N, std::string name){

	Zombie* zombie = new Zombie[N];
	
	for (int i = 0; i < N ; i++)
		zombie[i].setName(name);
	//for (int i = 0; i < N ; i++)
		//std::cout << zombie[i].getName() << std::endl;
	return (zombie);
}