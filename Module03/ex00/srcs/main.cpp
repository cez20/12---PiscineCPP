/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/15 17:47:16 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap hero1("Cesar");
	hero1.getInfo();

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                              ATTACK()                                             *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;
	
	hero1.attack("Jules");
	hero1.getInfo();

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                              TAKE DAMAGE()                                        *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;

	hero1.takeDamage(3);
	hero1.getInfo();
	
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                              BE REPAIRED()                                        *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;
	
	hero1.beRepaired(2);
	hero1.getInfo();

	return (0);
}