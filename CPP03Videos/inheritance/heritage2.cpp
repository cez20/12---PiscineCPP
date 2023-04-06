/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage2.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:00:26 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/05 18:18:26 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERITAGE2_HPP
#define HERITAGE2_HPP

#include <string>

/* J'ai cree une classe parent Animal qui regroupe les caracteristiques communes 
des animaux soit nbrOfLegs et run. Chaque instance de Cat et Pony herite donc
de la classe Animal (de la meme maniere qu'un enfant herite de ses parents.) */

/* Il est possible de repeter des fonctions quis e trouve dans Animal dans les enfants d'animal */

/* Il existe d'autre type type d'inheritance soit private et protected  */

/* Points qui reste a explorer: 
1- Comment un enfant appelle le constructeur de son parents
2- Comment s'assurer que les destructeurs sont bien appeles pour les 2 (parent et enfant)
3- Par exemple, lorsque j'instancie un chat, je me dois d'instancier la classe Animale mais aussi
la classe Chat ou ce qui est specifique au chat, car sinon je cree seulement un animal et non un chat 
4- 

 */


class Animal {

	private:
		int 	_nbrOfLegs;

	public;
		Animal();
		Animal(Animal const &);
		Animal& operator=(Animal const &);
		~Animal();

		void run(int distance);

}


class Cat: public Animal {

	private:
		int 	_nbrOfLegs;

	public;
		Cat();
		Cat(Cat const &);
		Cat& operator=(Cat const &);
		~Cat();

		void run(int distance);

		void scornSomeone(std::string const & target);

}

class Pony: public Animal {

	private:
		int 	_nbrOfLegs;

	public;
		Pony();
		Pony(Pony const &);
		Pony& operator=(Pony const &);
		~Pony();

		void run(int distance);

		void doMagic(std::string const & target);

}

#endif
