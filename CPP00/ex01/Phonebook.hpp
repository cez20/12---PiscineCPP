/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:39:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/02/01 11:16:33 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>  // Permet d'utiliser l'element string de la librarie std:

class	Contact{

public: // Mais il est suppose etre private ????

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};


class	PhoneBook{

public:

	void	ADD(int index);
	void	SEARCH(void);
	void	EXIT(void);

private:

	Contact	contact[8]; // M on tableau de 8 contact doit etre private, car on ne doit pas etre en mesure de pouvoir changerr
};

#endif