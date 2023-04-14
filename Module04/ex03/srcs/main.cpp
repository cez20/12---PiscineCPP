/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:21:23 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/14 16:45:00 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"


int main()
{
	//AMateria material;   // Impossible to instanciate because this is an abstract class 
	AMateria *material = new Ice();
	std::cout << "I am in main function" << std::endl;
	delete material;




	//MAIN INSIDE PDG 
	
	// MateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter* me = new Character("me");
	
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	
	// ICharacter* bob = new Character("bob");
	
	// me->use(0, *bob);
	// me->use(1, *bob);
	
	// delete bob;
	// delete me;
	// delete src;
	return 0;

}
