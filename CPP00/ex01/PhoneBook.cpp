/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:50:56 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/15 17:05:06 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

void	PhoneBook::display_menu_options(void)
{
	std::cout << "\033[1;32mPlease enter ADD, SEARCH OR EXIT to use this PHONEBOOK: \033[0m" << std::endl;
	std::cout << "ADD ----------> Allows you to enter a new contact in this PHONEBOOK" << std::endl;
	std::cout << "SEARCH -------> Allows you to search one contact in this PHONEBOOK" << std::endl;
	std::cout << "EXIT ---------> Allows you to quit the current PHONEBOOK\n" << std::endl;

	std::cout << "\033[1;32mEnter your choice here: \033[0m";

	std::getline(std::cin, this->choice);
}

void	PhoneBook::ADD(int index)
{
	std::cout << "The value of index is: " << index << std::endl;
	while(contact[index].first_name.empty())
	{
		std::cout << "Please enter first name: ";
		std::getline(std::cin, contact[index].first_name);
	}
	while(contact[index].last_name.empty())
	{
		std::cout << "Please enter last name: ";
		std::getline(std::cin, contact[index].last_name);
	}
	while(contact[index].nickname.empty())
	{
		std::cout << "Please enter nickname: ";
		std::getline(std::cin, contact[index].nickname);
	}
	while(contact[index].phone_number.empty())
	{
		std::cout << "Please enter phone_number: ";
		std::getline(std::cin, contact[index].phone_number);
	}
	while(contact[index].darkest_secret.empty())
	{
		std::cout << "Please enter darkest secret: ";
		std::getline(std::cin, contact[index].darkest_secret);
	}
	std::cout << std::endl;
	std::cout << "\033[1;34mCONTACT HAS BEEN SUCCESSFULLY ENTERED IN PHONEBOOK !!!\033[0m\n" << std::endl;
}

void	PhoneBook::EXIT(void)
{
	std::cout << "I am inside the exit function" << std::endl;
	exit(0);
	return;
}