/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:06:40 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/24 12:52:28 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

//Fonction qui cree une instance de Zombie. Prend le nom assigne
void	randomChump(std::string name)
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}