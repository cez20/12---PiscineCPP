/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:50:56 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/16 10:35:56 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

PhoneBook::PhoneBook(void){

	this->nbr_of_contact = 0;
	this->choice = "";
}

void	PhoneBook::display_menu_options(void)
{
	std::cout << "\033[1;32mPlease enter ADD, SEARCH OR EXIT to use this PHONEBOOK: \033[0m" << std::endl;
	std::cout << "ADD ----------> Allows you to enter a new contact in this PHONEBOOK" << std::endl;
	std::cout << "SEARCH -------> Allows you to search one contact in this PHONEBOOK" << std::endl;
	std::cout << "EXIT ---------> Allows you to quit the current PHONEBOOK\n" << std::endl;

	std::cout << "\033[1;32mEnter your choice here: \033[0m";

	std::getline(std::cin, this->choice);
}

void	PhoneBook::ADD()
{
	if (this->nbr_of_contact == 8)
	{
		std::cout << "Please note that this Phonebook is already full! This action will erase a previous entry" << std::endl;
		this->nbr_of_contact = 0;
	}
	std::cout << "The value of this->nbr_of_contact is: " << this->nbr_of_contact << std::endl;
	while(contact[this->nbr_of_contact].first_name.empty())
	{
		std::cout << "Please enter first name: ";
		std::getline(std::cin, contact[this->nbr_of_contact].first_name);
	}
	while(contact[this->nbr_of_contact].last_name.empty())
	{
		std::cout << "Please enter last name: ";
		std::getline(std::cin, contact[this->nbr_of_contact].last_name);
	}
	while(contact[this->nbr_of_contact].nickname.empty())
	{
		std::cout << "Please enter nickname: ";
		std::getline(std::cin, contact[this->nbr_of_contact].nickname);
	}
	while(contact[this->nbr_of_contact].phone_number.empty())
	{
		std::cout << "Please enter phone_number: ";
		std::getline(std::cin, contact[this->nbr_of_contact].phone_number);
	}
	while(contact[this->nbr_of_contact].darkest_secret.empty())
	{
		std::cout << "Please enter darkest secret: ";
		std::getline(std::cin, contact[this->nbr_of_contact].darkest_secret);
	}
	this->nbr_of_contact++;
	std::cout << std::endl;
	std::cout << "\033[1;34mCONTACT HAS BEEN SUCCESSFULLY ENTERED IN PHONEBOOK !!!\033[0m\n" << std::endl;
}

void	PhoneBook::EXIT(void)
{
	std::cout << "I am inside the exit function" << std::endl;
	exit(0);
	return;
}