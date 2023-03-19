/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:45:34 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/19 17:17:50 by cemenjiv         ###   ########.fr       */
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

PhoneBook::PhoneBook(void): choice(""), _nbrOfContact(0) {}

void	PhoneBook::menu_options(void)
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
	std::cout << "The value of this->_nbrOfContact is: " << this->_nbrOfContact << std::endl;
	if (this->_nbrOfContact == 8)
	{
		std::cout << "\033[31mWARNING! THIS PHONEBOOK IS ALREADY FULL. THIS ACTION WILL ERASE A PREVIOUS ENTRY IN THE PHONEBOOK.\033[0m" << std::endl;
		this->_nbrOfContact = 0;
	}
	if (!contact[this->_nbrOfContact]._firstName.empty())
	{
		contact[this->_nbrOfContact]._firstName.clear();
		contact[this->_nbrOfContact]._lastName.clear();
		contact[this->_nbrOfContact]._nickname.clear();
		contact[this->_nbrOfContact]._phoneNumber.clear();
		contact[this->_nbrOfContact]._darkestSecret.clear();
	}
	while(contact[this->_nbrOfContact]._firstName.empty())
	{
		std::cout << "Please enter first name: ";
		std::getline(std::cin, contact[this->_nbrOfContact]._firstName);
	}
	while(contact[this->_nbrOfContact]._lastName.empty())
	{
		std::cout << "Please enter last name: ";
		std::getline(std::cin, contact[this->_nbrOfContact]._lastName);
	}
	while(contact[this->_nbrOfContact]._nickname.empty())
	{
		std::cout << "Please enter _nickname: ";
		std::getline(std::cin, contact[this->_nbrOfContact]._nickname);
	}
	while(contact[this->_nbrOfContact]._phoneNumber.empty())
	{
		std::cout << "Please enter _phoneNumber: ";
		std::getline(std::cin, contact[this->_nbrOfContact]._phoneNumber);
		for(size_t i = 0; i < contact[this->_nbrOfContact]._phoneNumber.size(); i++)
		{
			if (!isdigit(contact[this->_nbrOfContact]._phoneNumber[i]))
			{
				contact[this->_nbrOfContact]._phoneNumber.clear();
				std::cout << "\033[31mPlease enter a phone number ONLY composed of digits!\033[0m" << std::endl;
				break;
			}
		}
	}
	while(contact[this->_nbrOfContact]._darkestSecret.empty())
	{
		std::cout << "Please enter darkest secret: ";
		std::getline(std::cin, contact[this->_nbrOfContact]._darkestSecret);
	}
	this->_nbrOfContact++;
	std::cout << std::endl;
	std::cout << "\033[1;34mCONTACT HAS BEEN SUCCESSFULLY ENTERED IN PHONEBOOK! PRESS -ENTER- TO CONTINUE !!!\033[0m" << std::endl;
	std::cin.get();
}

void	PhoneBook::SEARCH(void)
{
	std::string copy__firstName;  // Is it a good practice to declare new variable here 
	std::string copy__lastName;
	std::string copy__nickname;
	std::string choice1;
	int		index;
	
	std::cout << "\n" << std::setfill('.') << std::setw(10) << "INDEX" << "|"
			  << std::setfill('.') << std::setw(10) << "FIRST NAME" << "|"
			  << std::setfill('.') << std::setw(10) << "LAST NAME" << "|"
			  << std::setfill('.') << std::setw(10) << "_nickname" << "|" << std::endl;


	for (int i = 0; i < 8; i++)
    {
	   copy__firstName = truncate_str(contact[i]._firstName, 10);
	   copy__lastName = truncate_str(contact[i]._lastName, 10);
	   copy__nickname = truncate_str(contact[i]._nickname, 10);
	   std::cout<< std::setw(10) << i << "|"
	   			<< std::setw(10) << copy__firstName << "|"
	   			<< std::setw(10) << copy__lastName << "|"
	   			<< std::setw(10) << copy__nickname << "|" << std::endl;
    }

	std::cout << "\nWhich entry would you like to see? Please enter index number: ";  //Manage entry errors here 
	std::getline(std::cin, choice1);
	index = std::stoi(choice1);
	std::cout << std::endl;
	
	std::cout << "First name: " << contact[index]._firstName << std::endl;
	std::cout << "Last name: " << contact[index]._lastName << std::endl;
	std::cout << "_nickname: " << contact[index]._nickname << std::endl;
	std::cout << "Phone number: " << contact[index]._phoneNumber << std::endl;
	std::cout << "Darkest secret: " << contact[index]._darkestSecret << "\n" << std::endl;
}

void	PhoneBook::EXIT(void)
{
	std::cout << "I am inside the exit function" << std::endl;
	exit(0);
	return;
}