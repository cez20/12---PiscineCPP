/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:46:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/20 16:44:44 by cemenjiv         ###   ########.fr       */
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

void	Contact::setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	_firstName = first;
	_lastName = last;
	_nickname = nick;
	_phoneNumber = phone;
	_darkestSecret = secret;
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

// void	Contact::setFirstName(std::string first){

// 	_firstName = first;
// 	return ;
// }

// void	Contact::setLastName(std::string last){

// 	_lastName = last;
// 	return ;
// }

// void	Contact::setNickName(std::string nick){

// 	_nickname = nick;
// 	return ;
// }

// void	Contact::setPhoneNumber(std::string phone){

// 	_phoneNumber = phone;
// 	return ;
// }

// void	Contact::setDarkestSecret(std::string secret){

// 	_darkestSecret = secret;
// 	return ;
// }