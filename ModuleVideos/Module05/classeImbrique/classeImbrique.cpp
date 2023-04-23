/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classeImbrique.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:42:44 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/23 13:52:33 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Cette video traite des classe imbriquees (nested classes). Comme l'exemple ici-bas le 
// mentionne, il est possible de d'inserer une classe a l'interieur d'une meme classe.
// Par contre, il est important de mentionner qu'il y a une classe imbrique Leg specifique
// a Cat et une autre specifique a Dog.  

#include <iostream>

class Cat
{
	public:
	class Leg
	{
		public:
		Leg(){std::cout << "[CAT LEG CONSTRUCTOR]This is the cat's leg" << std::endl;} 
	};	
};

class Dog
{
	public:
	class Leg
	{
		public:
		Leg(){std::cout << "[DOG LEG CONSTRUCTOR]This is the dog's leg" << std::endl;} 
	};	
};

int main()
{
	Cat			somecat;
	Cat::Leg	somecatsleg;

	Dog			somedog;
	Dog::Leg 	somedogsleg;
}