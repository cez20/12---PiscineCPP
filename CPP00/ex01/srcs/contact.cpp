/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:46:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/21 13:55:24 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "contact.hpp"
#include "phonebook.hpp"

Contact::Contact(void): _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""),_darkestSecret("")
{
	std::cout << "Je suis dans le constructeur de Contact" << std::endl;
	// if (_firstName.empty())
	// 	std::cout << "First name est vide" << std::endl;
	// if (_lastName.empty())
	// 	std::cout << "Last name est vide" << std::endl;
	// if (_nickname.empty())
	// 	std::cout << "Nickname est vide" << std::endl;
	// if (_phoneNumber.empty())
	// 	std::cout << "Phonenumber est vide" << std::endl;
	// if (_darkestSecret.empty())
	// 	std::cout << "Darkestsecret est vide" << std::endl;
}

void	Contact::addContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	if (!std::cin.eof())
	{
		_firstName = first;
		_lastName = last;
		_nickname = nick;
		_phoneNumber = phone;
		_darkestSecret = secret;
		std::cout << "\n\033[1;34mCONTACT HAS BEEN SUCCESSFULLY ENTERED IN PHONEBOOK!\n\033[0m" << std::endl;
	}
}

std::string	Contact::getFirstName(){

	return _firstName;
}

std::string	Contact::getLastName(){

	return _lastName;
}

std::string	Contact::getNickName(){

	return _nickname;
}

std::string	Contact::getPhoneNumber(){

	return _phoneNumber;
}

std::string	Contact::getDarkestSecret(){

	return _darkestSecret;
}
