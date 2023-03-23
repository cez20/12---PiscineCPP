/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:33:59 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/23 18:46:35 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main()
{
	randomChump("Cesar");
	Zombie* first = newZombie("Edouard");

	first->announce();
	delete first; // If delete is not called, destructor for pointer is never called. 
}