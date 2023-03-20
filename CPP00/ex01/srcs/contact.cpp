/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:46:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/20 15:02:41 by cemenjiv         ###   ########.fr       */
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
	if (_firstName.empty())
		std::cout << "First name est vide" << std::endl;
	if (_lastName.empty())
		std::cout << "Last name est vide" << std::endl;
	if (_nickname.empty())
		std::cout << "Nickname est vide" << std::endl;
	if (_phoneNumber.empty())
		std::cout << "Phonenumber est vide" << std::endl;
	if (_darkestSecret.empty())
		std::cout << "Darkestsecret est vide" << std::endl;
}