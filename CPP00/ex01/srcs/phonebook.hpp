/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:39:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/19 17:17:55 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>
#include "contact.hpp"

class	PhoneBook{

public:

	PhoneBook(void);
	std::string	choice;
	void		menu_options(void);
	void		ADD(void);
	void		SEARCH(void);
	void		EXIT(void);

private:

	int			_nbrOfContact;
	Contact		contact[8]; //Array of 8 of class Contact 
};

#endif