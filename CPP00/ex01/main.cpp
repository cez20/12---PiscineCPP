/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:51:11 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/17 00:06:58 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>  // Permet d'utiliser cout/cin
#include <string>    // Permet d'utiliser le type de variable string 
#include "phonebook.hpp"  // Header de la classe phonebook.hpp
#include "contact.hpp"   // Header de la classe contact.hpp

// A) Implementer 2 classes: PhoneBook et Contact 
// Classe PhoneBook:
// 1- Represente le repertoire telephonique qui sera utilise
// 2- Contient un tableau de contacts
// 3- Peut enregistrer 8 contacts maximum. Si l'utilisateur essaie d'en rentrer un 9e, remplacer le plus ancien par celui-ci
// 4- Allocation dynamique interdite 
// Class Contact
//	1- Represente un contact dans le repetoire
// B) Objet nomme "repertoire" doit etre une instance de la classe PhoneBook
// C) objets "contacts" doivent etre une instance de la classe Contact 
// D) Rappel : Ce qui est utilise dans une classe seulement est "private", ce qui peut etre utilise a l'exterieur est public

// Optionnel, si ce qui est ecrit a deja ete utilise ailleurs, ecrire un messafge 
// Accepter que des lettres dans nom, nom de famille, nickname.
// Travailler sur l'option SEARCH qui montre le contenu du PHONEBOOK
// J'ai declare ma fonction normale dans phonebook.cpp
int main()
{
	PhoneBook	phonebook; // Create an instance/object of class PhoneBook named repertoire 
	
	while (1)
	{	
		phonebook.display_phonebook_options();
		if (phonebook.choice.compare("ADD") == 0) // Maybe I can use a switch and the case 1, case 2 , etc)
			phonebook.ADD();
		else if (phonebook.choice == "SEARCH")
			phonebook.SEARCH();
		else if (phonebook.choice == "EXIT") // We can also use "relational operators" such as "=" and "!=", but this has to be used with std::string. 
		 	phonebook.EXIT();
		else
		{
			std::cout << "\033[31mThis choice is invalid! Press ENTER to continue\033[0m" << std::endl;
			std::cin.get();
			//std::cout << "\033[2J\033[1;1H"; // Escape sequence to erase everything
		}
	}		
	return 0;
}
