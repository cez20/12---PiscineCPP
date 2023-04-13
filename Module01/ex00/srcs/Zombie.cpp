/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:00:42 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/13 14:39:18 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name){

	std::cout << "Constructor is called. Zombie's name is: " << _name << std::endl;
}

Zombie::~Zombie(void){

	std::cout << _name << " is destroyed" << std::endl;
}

void	Zombie::announce(void){
	
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

