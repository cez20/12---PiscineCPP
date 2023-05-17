/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/17 13:18:00 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap hero1("Cesar");
	hero1.printInfo();

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                              ATTACK()                                             *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;
	
	hero1.attack("Jules");
	hero1.printInfo();

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                             TAKE DAMAGE()                                         *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;

	hero1.takeDamage(3);
	hero1.printInfo();
	
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                             BE REPAIRED()                                         *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;
	
	hero1.beRepaired(2);
	hero1.printInfo();

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                     ATTACK(), BE REPAIRED(), TAKE DAMAGE() NOT POSSIBLE           *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;

	ClapTrap hero2("Robert");
	
	for (int i = 0; i < 10; i++)
		hero2.attack("Jules");
		
	hero2.printInfo();
	
	hero2.beRepaired(3);
	hero2.attack("John");
	hero2.takeDamage(11);
	hero2.takeDamage(2);
	
	hero2.printInfo();
	std::cout << "\n";
	
	return (0);
}