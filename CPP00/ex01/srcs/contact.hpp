/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:13:10 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/20 14:58:41 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>  // Permet d'utiliser l'element string de la librarie std:

class	Contact{

public:

	Contact(void);
	
private: // Mais il est suppose etre private. Pourquoi? 

	std::string _firstName;  // variable de type string nomme first_name
	std::string	_lastName;   // variable de type string nomme last_name
	std::string	_nickname;    // variable de type string nomme nickname
	std::string	_phoneNumber; // variable de type string nomme phone_number
	std::string	_darkestSecret; // variable de type string nomme darkest_secret
};

#endif