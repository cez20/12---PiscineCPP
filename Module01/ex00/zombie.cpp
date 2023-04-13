/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:00:42 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/24 12:19:40 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

// Constructeur qui prend un nom et initialise le Zombie avec ce nom. 
Zombie::Zombie(std::string name): _name(name){

	std::cout << "Constructor is called. Zombie's name is: " << _name << std::endl;
}

// Destructeur qui indique le nom du zombie qui meurt
Zombie::~Zombie(void){

	std::cout << _name << " is destroyed" << std::endl;
}

void	Zombie::announce(void){
	
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;  // PAs oblige de mettre this->_name
}

