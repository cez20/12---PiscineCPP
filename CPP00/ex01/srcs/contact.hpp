/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:13:10 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/15 16:14:34 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>  // Permet d'utiliser l'element string de la librarie std:

class	Contact{

public: // Mais il est suppose etre private ????

	std::string	first_name;  // variable de type string nomme first_name
	std::string	last_name;   // variable de type string nomme last_name
	std::string	nickname;    // variable de type string nomme nickname
	std::string	phone_number; // variable de type string nomme phone_number
	std::string	darkest_secret; // variable de type string nomme darkest_secret
};

#endif