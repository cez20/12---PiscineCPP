/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:37:37 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/02/01 11:35:47 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "phonebook.hpp"

void	PhoneBook::EXIT(void)
{
	exit(0);
	return;
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