/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:50:56 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/19 13:01:49 by cemenjiv         ###   ########.fr       */
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

PhoneBook::PhoneBook(void){

	this->nbr_of_contact = 0;
	this->choice = ""; // Create an empty string
}

void	PhoneBook::display_phonebook_options(void)
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
	std::cout << "The value of this->nbr_of_contact is: " << this->nbr_of_contact << std::endl;
	if (this->nbr_of_contact == 8)
	{
		std::cout << "\033[31mWARNING! THIS PHONEBOOK IS ALREADY FULL. THIS ACTION WILL ERASE A PREVIOUS ENTRY IN THE PHONEBOOK.\033[0m" << std::endl;
		this->nbr_of_contact = 0;
	}
	if (!contact[this->nbr_of_contact].first_name.empty())
	{
		contact[this->nbr_of_contact].first_name.clear();
		contact[this->nbr_of_contact].last_name.clear();
		contact[this->nbr_of_contact].nickname.clear();
		contact[this->nbr_of_contact].phone_number.clear();
		contact[this->nbr_of_contact].darkest_secret.clear();
		
	}
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
		for(size_t i = 0; i < contact[this->nbr_of_contact].phone_number.size(); i++)
		{
			if (!isdigit(contact[this->nbr_of_contact].phone_number[i]))
			{
				contact[this->nbr_of_contact].phone_number.clear();
				std::cout << "\033[31mPlease enter a phone number ONLY composed of digits!\033[0m" << std::endl;
				break;
			}
		}
	}
	while(contact[this->nbr_of_contact].darkest_secret.empty())
	{
		std::cout << "Please enter darkest secret: ";
		std::getline(std::cin, contact[this->nbr_of_contact].darkest_secret);
	}
	this->nbr_of_contact++;
	std::cout << std::endl;
	std::cout << "\033[1;34mCONTACT HAS BEEN SUCCESSFULLY ENTERED IN PHONEBOOK! PRESS -ENTER- TO CONTINUE !!!\033[0m" << std::endl;
	std::cin.get();
}

void	PhoneBook::SEARCH(void)
{
	std::string copy_first_name;  // Is it a good practice to declare new variable here 
	std::string copy_last_name;
	std::string copy_nickname;
	std::string choice1;
	int		index;
	
	std::cout << "\n" << std::setfill('.') << std::setw(10) << "INDEX" << "|"
			  << std::setfill('.') << std::setw(10) << "FIRST NAME" << "|"
			  << std::setfill('.') << std::setw(10) << "LAST NAME" << "|"
			  << std::setfill('.') << std::setw(10) << "NICKNAME" << "|" << std::endl;


	for (int i = 0; i < 8; i++)
    {
	   copy_first_name = truncate_str(contact[i].first_name, 10);
	   copy_last_name = truncate_str(contact[i].last_name, 10);
	   copy_nickname = truncate_str(contact[i].nickname, 10);
	   std::cout<< std::setw(10) << i << "|"
	   			<< std::setw(10) << copy_first_name << "|"
	   			<< std::setw(10) << copy_last_name << "|"
	   			<< std::setw(10) << copy_nickname << "|" << std::endl;
    }

	std::cout << "\nWhich entry would you like to see? Please enter index number: ";  //Manage entry errors here 
	std::getline(std::cin, choice1);
	index = std::stoi(choice1);
	std::cout << std::endl;
	
	std::cout << "First name: " << contact[index].first_name << std::endl;
	std::cout << "Last name: " << contact[index].last_name << std::endl;
	std::cout << "Nickname: " << contact[index].nickname << std::endl;
	std::cout << "Phone number: " << contact[index].phone_number << std::endl;
	std::cout << "Darkest secret: " << contact[index].darkest_secret << "\n" << std::endl;
}

void	PhoneBook::EXIT(void)
{
	std::cout << "I am inside the exit function" << std::endl;
	exit(0);
	return;
}