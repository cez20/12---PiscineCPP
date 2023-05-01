/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:46:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/01 19:43:29 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact(void): _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""),_darkestSecret("") {}


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
