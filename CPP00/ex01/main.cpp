/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:51:11 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/15 17:22:16 by cemenjiv         ###   ########.fr       */
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


//Creer un constructeur pour initialiser choice a NULL et ventuellement nbr_contact a 0.
int main()
{
	//std::string	choice;  Would no longer be necessary if variable is inside member function
	Contact		person;  // Create an instance/object of class Contact named Person 
	PhoneBook	phonebook; // Create an instance/object of class PhoneBook named repertoire 
	int			nbr_contacts; // Integer named nbr_contact 

	nbr_contacts = 0;
	while (1)
	{	
		phonebook.display_menu_options();
		//std::getline(std::cin, choice);
		if (phonebook.choice.compare("ADD") == 0) // Maybe I can use a switch and the case 1, case 2 , etc)
		{	
			if (nbr_contacts == 8)
				nbr_contacts = 0;
			phonebook.ADD(nbr_contacts);
			nbr_contacts++;
		}
		else if (phonebook.choice == "SEARCH")
			std::cout << "We are in the SEARCH option!\n" << std::endl;
		else if (phonebook.choice == "EXIT") // We can also use "relational operators" such as "=" and "!=", but this has to be used with std::string. 
		 	phonebook.EXIT();
		else
			std::cout << "\033[31mThis choice is not valid! Please re-enter a valid choice!\033[0m\n" << std::endl;
	}		
	return 0;
}
