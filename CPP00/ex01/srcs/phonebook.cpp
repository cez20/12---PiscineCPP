/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:45:34 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/21 14:41:51 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "contact.hpp"
#include "phonebook.hpp"

std::string truncate_str(std::string str, size_t size) 
{
    if (str.size() > size) 
	{
        str.resize(size);
        str.replace(size - 1, 1, ".");
    }
    return str;
}

int 	is_all_digits(std::string phoneNumber)
{
	for(size_t i = 0; i < phoneNumber.size(); i++)
	{
		if (!isdigit(phoneNumber[i]))
		{
			phoneNumber.clear();
			std::cout << "\033[31mPlease enter a phone number ONLY composed of digits!\033[0m" << std::endl;
			return(0);
		}
	}
	return (1);
}

PhoneBook::PhoneBook(void): choice(""), _nbrOfContact(0) {}

void	PhoneBook::display_options(void)
{
	std::cout << "\033[1;32mPlease enter ADD, SEARCH OR EXIT to use this PHONEBOOK: \033[0m" << std::endl;
	std::cout << "ADD ----------> Allows you to enter a new contact in this PHONEBOOK" << std::endl;
	std::cout << "SEARCH -------> Allows you to search one contact in this PHONEBOOK" << std::endl;
	std::cout << "EXIT ---------> Allows you to quit the current PHONEBOOK\n" << std::endl;

	std::cout << "\033[1;32mEnter your choice here: \033[0m";
	std::getline(std::cin, this->choice);
	if (std::cin.eof())
		return ;
}

void	PhoneBook::ADD()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret; 
	
	if (this->_nbrOfContact == 8)
		this->_nbrOfContact = 0;
	while (firstName.empty())
	{
		std::cout << "Please enter first name: ";
 		std::getline(std::cin, firstName);
		if (std::cin.eof())
			return ;
	}
	while(lastName.empty())
	{
		std::cout << "Please enter last name: ";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			return ;
	}
	while(nickname.empty())
	{
		std::cout << "Please enter nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			return ;
	}
	while(phoneNumber.empty())
	{
		std::cout << "Please enter phone number: ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			return ;
		if(is_all_digits(phoneNumber) == 0)
			phoneNumber.clear();
	}
	while(darkestSecret.empty())
	{
		std::cout << "Please enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
		if (std::cin.eof())
			return ;
	}
	_contact[this->_nbrOfContact].addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
 	this->_nbrOfContact++;
}

void	PhoneBook::SEARCH(void)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string choice;
	int			index;
	
	std::cout << "\n" << std::setfill(' ') << std::setw(10) << "INDEX" << "|"
			  << std::setfill(' ') << std::setw(10) << "FIRST NAME" << "|"
			  << std::setfill(' ') << std::setw(10) << "LAST NAME" << "|"
			  << std::setfill(' ') << std::setw(10) << "NICKNAME" << "|" << std::endl;

	for (int i = 0; i < 8; i++)
    {
	   firstName = truncate_str(_contact[i].getFirstName(), 10);
	   lastName = truncate_str(_contact[i].getLastName(), 10);
	   nickname = truncate_str(_contact[i].getNickName(), 10);
	   std::cout<< std::setw(10) << i << "|"
	   			<< std::setw(10) << firstName << "|"
	   			<< std::setw(10) << lastName << "|"
	   			<< std::setw(10) << nickname << "|" << std::endl;
    }

	std::cout << "\nWhich entry would you like to see? Please enter index number: ";  //Manage entry errors here 
	std::getline(std::cin, choice);
	if (std::cin.eof())
		return ;
	index = std::stoi(choice);
	std::cout << std::endl;

	std::cout << "First name: " << _contact[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contact[index].getNickName() << std::endl;
	std::cout << "Phone number: " << _contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contact[index].getDarkestSecret() << "\n" << std::endl;
}

void	PhoneBook::EXIT(void)
{
	std::cout << "Quitting the phonebook! See you soon!" << std::endl;
	exit(0);
}
