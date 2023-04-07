/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/07 13:48:06 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap robot = ClapTrap("Main Robot");

	robot.getInfo();
	robot.attack("Jules");
	robot.takeDamage(3);
	robot.beRepaired(2);
	robot.getInfo();
	//robot.guardGate();  //Impossible to use because base class cannot use a function of derived class
	
	std::cout << "\n\n" << std::endl;
	
	ScavTrap derivedRobot1 = ScavTrap("Derived Robot");
	
	derivedRobot1.getInfo();
	derivedRobot1.attack("Henri");
	derivedRobot1.takeDamage(3);
	derivedRobot1.beRepaired(2);
	derivedRobot1.getInfo();
	derivedRobot1.guardGate();

	return (0);
}