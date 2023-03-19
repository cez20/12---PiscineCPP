/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:39:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/16 15:11:17 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>
#include "contact.hpp"

// Est-ce que j'ai besoin d'un constructeur et d'un destructeur ici? 
// In the public section, we find function members and the attributes these functions takes. How the function works will be declared in PhoneBook.cpp
//
class	PhoneBook{

public:

	PhoneBook(void);
	//~PhoneBook(void); // Est-ce que j'ai besoin d'ajoute un destructeur 
	std::string choice;
	void		display_phonebook_options(void);
	void		ADD(void);
	void		SEARCH(void);
	void		EXIT(void);

private:

	int			nbr_of_contact;
	Contact		contact[8]; //Array of 8 of class Contact 
};

#endif