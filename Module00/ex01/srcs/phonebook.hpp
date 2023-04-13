/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:39:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/27 14:54:02 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>
#include "contact.hpp"

class	PhoneBook{

private:

	int			_nbrOfContact;
	Contact		_contact[8]; //Array of 8 of class Contact 

public:

	PhoneBook(void);
	std::string	choice;
	void		display_options(void);
	void		add(void);
	void		search(void);
};

std::string truncate_str(std::string str, size_t size);
int	is_all_digits(std::string phoneNumber);


#endif