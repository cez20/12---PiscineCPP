/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:09:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/22 11:49:19 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_and_delete.hpp"


int main()
{
	Student bob = Student("bfubar");  // Declaration et initialisation sur la meme ligne. Contneu s'initialise et se trouve dans le meme espace memoire
	Student bobby("boubar");  // Declaration se fait a un endroit et l'assignation se fait a quelque part dans la memoire par la suite. 
	Student* jim = new Student("jbufar"); // objet jim cree sur la heap en assignant de la memoire avec new 

	delete jim;  // Delete est l'equivalent de free(); 

	return (0); // Destructor is called 
}
