/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/15 18:52:06 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	//robot.guardGate();  //Impossible to use because base class cannot use a function of derived class
	delete robot1;
	std::cout << std::endl;
	
	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                      SCAVTRAP ROBOT CREATION (DERIVED FROM CLAPTRAP):             *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;
	
	std::cout << "SCAVTRAP ROBOT CREATION (DERIVED FROM CLAPTRAP):" << std::endl;
	ScavTrap* derivedRobot2 = new ScavTrap("Robot 2");
	derivedRobot2->getInfo();
	derivedRobot2->attack("Daniel");
	derivedRobot2->getInfo();
	derivedRobot2->takeDamage(3);
	derivedRobot2->getInfo();
	derivedRobot2->beRepaired(2);
	derivedRobot2->getInfo();
	derivedRobot2->guardGate();
	//derivedRobot2->highFiveGuys(); // Impossible for ScavTrap to call highFivedGuys
	delete derivedRobot2;
	std::cout << std::endl;

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*                      FRAGTRAP ROBOT CREATION (DERIVED FROM CLAPTRAP)              *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;
	
	FragTrap* derivedRobot3 = new FragTrap("Robot 3");
	derivedRobot3->getInfo();
	derivedRobot3->attack("Henri");
	derivedRobot3->getInfo();
	derivedRobot3->takeDamage(3);
	derivedRobot3->getInfo();
	derivedRobot3->beRepaired(3);
	derivedRobot3->getInfo();
	derivedRobot3->highFiveGuys();
	//derivedRobot3->guardGate(); // Pourquoi je suis capable d'appeler guardGate
	delete derivedRobot3;
	std::cout << std::endl;

	std::cout << GRN"*************************************************************************************" RESET << std::endl;
    std::cout << GRN"*             MAKING SURE ATTACK() AND BASE CLASS DESTRUCTOR ARE 'VIRTUAL'          *" RESET << std::endl;
    std::cout << GRN"*************************************************************************************" RESET << std::endl;
	
	ClapTrap* robot4 = new ScavTrap("Robot 4");
	robot4->getInfo();
	robot4->attack("Robby");
	delete robot4;

	return (0);
}