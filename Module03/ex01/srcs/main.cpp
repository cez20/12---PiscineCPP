/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/15 18:34:10 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                               CLAPTRAP ROBOT CREATION                             *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;
	
	ClapTrap* robot1= new ClapTrap("Robot1");
	robot1->getInfo();
	robot1->attack("Jules");
	robot1->getInfo();
	robot1->takeDamage(3);
	robot1->getInfo();
	robot1->beRepaired(2);
	robot1->getInfo();
	//robot1->guardGate();  //Impossible to use because base class cannot use a function of derived class
	delete robot1;
	std::cout << "\n" << std::endl;
	
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                      SCAVTRAP ROBOT CREATION (DERIVED FROM CLAPTRAP):             *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;
	
	ScavTrap* derivedRobot2 = new ScavTrap("Robot 2");
	derivedRobot2->getInfo();
	derivedRobot2->attack("Default Robot");
	derivedRobot2->getInfo();
	derivedRobot2->takeDamage(3);
	derivedRobot2->getInfo();
	derivedRobot2->beRepaired(2);
	derivedRobot2->getInfo();
	derivedRobot2->guardGate();
	delete derivedRobot2;
	std::cout << "\n" << std::endl;

	
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*           MAKING SURE ATTACK() AND BASE CLASS DESTRUCTOR ARE 'VIRTUAL'             *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;

	ClapTrap* robot3 = new ScavTrap("Robot3");
	robot3->getInfo();
	robot3->attack("Default Robot");
	delete robot3;

	return (0);
}