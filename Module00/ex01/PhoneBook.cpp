/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:45:34 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/02 15:21:16 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _count(0), choice("") {}

void	PhoneBook::display_options()
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

void	PhoneBook::add()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret; 
	
	if (this->_count == 8)
		this->_count = 0;
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

	addContact(Contact(firstName, lastName, nickname, phoneNumber, darkestSecret));
 	this->_count++;
}

void	PhoneBook::addContact(Contact contact)
{
	if (!std::cin.eof())
	{
		_contact[this->_count] = contact;
		std::cout << "\n\033[1;34mCONTACT HAS BEEN SUCCESSFULLY ENTERED IN PHONEBOOK!\n\033[0m" << std::endl;
	}
}

void	PhoneBook::search(void)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string choice;
	int			index;
	
	if (_contact[0].getFirstName().empty())
	{
		std::cout << "\033[31mPhonebook is empty! Please add 1 contact in phonebook\n" << std::endl;
		return ;
	}

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

	index = -1;
	while (index < 0 || index > 7)
	{
		std::cout << "Which entry would you like to see? Please enter index number: ";
		std::getline(std::cin, choice);
		try {
			index = std::stoi(choice);
		}
		catch (std::invalid_argument)
		{
			std::cerr << "Bad entry" << std::endl;
			return ;
		}
		if (index < 0 || index > 7)
		{
			std::cout << "\033[31mThis is an invalid index\033[0m" << std::endl;
			index = -1;
		}
		else if (_contact[index].getFirstName().empty())
		{
			std::cout << "\033[31mThis index is empty\033[0m" << std::endl;
			index = -1;
		}
	}
	std::cout << std::endl;
	std::cout << "First name: " << _contact[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contact[index].getNickName() << std::endl;
	std::cout << "Phone number: " << _contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contact[index].getDarkestSecret() << "\n" << std::endl;
}

std::string truncate_str(std::string str, size_t size)
{
    if (str.size() > size) 
	{
        str.resize(size);
        str.replace(size - 1, 1, ".");
    }
    return str;
}

int	is_all_digits(std::string number)
{
	for(size_t i = 0; i < number.size(); i++)
	{
		if (!isdigit(number[i]))
		{
			number.clear();
			std::cout << "\033[31mPlease enter digits!\033[0m" << std::endl;
			return(0);
		}
	}
	return (1);
}