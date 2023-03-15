/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:51:11 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/02/01 11:34:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "phonebook.hpp"

// void	if_empty(std::string string)
// {
// 	if (string.empty())
		
	
// }

int main()
{
	std::string	choice;
	Contact		person;
	PhoneBook	repertoire;
	int			nbr_contacts;

	nbr_contacts = 0;
	while (1)
	{
		std::cout << "\033[1;32mPlease enter ADD, SEARCH OR EXIT to use this PHONEBOOK: \033[0m" << std::endl;
		std::cout << "ADD ----------> Allows you to enter a new contact in this PHONEBOOK" << std::endl;
		std::cout << "SEARCH -------> Allows you to search one contact in this PHONEBOOK" << std::endl;
		std::cout << "EXIT ---------> Allows you to quit the current PHONEBOOK\n" << std::endl;

		std::cout << "\033[1;32mYour choice: \033[0m";
		
		
	//"Please enter one of the following options: ADD, SEARCH or EXIT : " << std::endl;
		std::getline(std::cin, choice);

		if (choice == "EXIT") // We can also use "relational operators" such as "=" and "!=", but this has to be used with std::string. 
		{
			std::cout << "Je suis dans la condition EXIT" << std::endl;
			repertoire.EXIT();
		}
		else if (choice.compare("ADD") == 0)
		{	
			if (nbr_contacts == 8)
				nbr_contacts = 0;
			repertoire.ADD(nbr_contacts);
			nbr_contacts++;
			// while(person.first_name.empty())
			// {
			// 	std::cout << "Please enter first name: ";
			// 	std::getline(std::cin, person.first_name);
			// }
			// while(person.last_name.empty())
			// {
			// 	std::cout << "Please enter last name: ";
			// 	std::getline(std::cin, person.last_name);
			// }
			// while(person.nickname.empty())
			// {
			// 	std::cout << "Please enter nickname: ";
			// 	std::getline(std::cin, person.nickname);
			// }
			// while(person.phone_number.empty())
			// {
			// 	std::cout << "Please enter phone_number: ";
			// 	std::getline(std::cin, person.phone_number);
			// }
			// while(person.darkest_secret.empty())
			// {
			// 	std::cout << "Please enter darkest secret: ";
			// 	std::getline(std::cin, person.darkest_secret);
			// }
			// std::cout << std::endl;
			// std::cout << "\033[1;34mCONTACT HAS BEEN SUCCESSFULLY ENTERED IN PHONEBOOK !!!\033[0m\n" << std::endl;
		}
		else if (choice == "SEARCH")
			std::cout << "I am freaking tired my friend\n" << std::endl;
	}
	return 0;
}