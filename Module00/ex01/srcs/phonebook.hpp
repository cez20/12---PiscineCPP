/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:39:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/01 19:41:03 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>
#include "Contact.hpp"

class	PhoneBook{

private:
	int			_count;
	Contact		_contact[8];

public:

	PhoneBook();
	std::string	choice;
	void		display_options();
	void		add();
	void		search();
};

std::string truncate_str(std::string str, size_t size);
int	is_all_digits(std::string phoneNumber);


#endif