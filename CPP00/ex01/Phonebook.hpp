/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:39:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/31 09:26:48 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

// Ne pas oublier de mettre private et public
// ADD: programme demande de remplir les champs de la class contact;
//		std::cout << pour afficher contenu
//		std::cin >> pour mettre contenu a quelquepart (ex: first_name);
// 		Les champs de chacun des attributs Contact ne peuvent etre vide lorsqu'on call ADD
// SEARCH: affiche le contact qui est demande



class	PhoneBook{

private:

	char	*contact[8];	// Cree un tableau de 8 contacts en se basant sur la classe Contact ? 

public:

	void	ADD(void);
	void	SEARCH(void);
	void	EXIT(void);
};


// Utilise des arrays, car allocation dynamique non-atuorise pour l'instant 
class	Contact{

private:

	char	first_name[50];
	char	last_name[50];
	char	nickname[50];
	int		phone_number[10];
	char	darkest_secret[100];
};


#endif