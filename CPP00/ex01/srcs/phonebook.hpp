/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:39:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/21 13:56:45 by cemenjiv         ###   ########.fr       */
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
	void		display_options(void);
	void		ADD(void);
	void		SEARCH(void);
	void		EXIT(void);
	void		printPhonebook(void);


private:

	int			_nbrOfContact;
	Contact		_contact[8]; //Array of 8 of class Contact 
};

#endif