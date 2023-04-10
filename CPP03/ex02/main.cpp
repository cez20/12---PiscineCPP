/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/10 10:15:55 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "\nCLAPTRAP ROBOT CREATION:" << std::endl;
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
	std::cout << "\n" << std::endl;
	
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
	delete derivedRobot2;

	std::cout << "\nFRAGTRAP ROBOT CREATION (DERIVED FROM CLAPTRAP):" << std::endl;
	FragTrap* derivedRobot3 = new FragTrap("Robot 3");
	derivedRobot3->getInfo();
	derivedRobot3->attack("Henri");
	derivedRobot3->getInfo();
	derivedRobot3->takeDamage(3);
	derivedRobot3->getInfo();
	derivedRobot3->beRepaired(3);
	derivedRobot3->getInfo();
	derivedRobot3->highFiveGuys();
	delete derivedRobot3;


	
	
	std::cout << "\nMAKING SURE BASE CLASS DESTRUCTOR IS 'VIRTUAL'" << std::endl;
	ClapTrap* robot3 = new ScavTrap("Robot 3");
	robot3->getInfo();
	delete robot3;

	return (0);
}