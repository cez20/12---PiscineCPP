/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:46:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/01 21:47:00 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact(): _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""),_darkestSecret("") {}

Contact::Contact(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	_firstName = first;
	_lastName = last;
	_nickname = nick;
	_phoneNumber = phone;
	_darkestSecret = secret;
}

std::string	Contact::getFirstName() const
{
	return _firstName;
}

std::string	Contact::getLastName() const
{
	return _lastName;
}

std::string	Contact::getNickName() const
{
	return _nickname;
}

std::string	Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

std::string	Contact::getDarkestSecret() const
{
	return _darkestSecret;
}
