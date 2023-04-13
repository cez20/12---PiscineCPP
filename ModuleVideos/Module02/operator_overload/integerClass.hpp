/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integerClass.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:40:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/03 14:11:33 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGERCLASS_HPP
# define INTEGERCLASS_HPP

#include <iostream>

class Integer{

	private:
		int _n;

	public:
		Integer(int const n);
		~Integer();
		int		getValue(void) const; // Permet d'obtenir la valeur de l'entier _n
		
		
		// Lorsqu'on fait appel aux fonctions membres ci-dessous, C++ passe systematiquement
		// en premier parametre , une instance de la classe courante. C'est pourquoi ici,
		// La fonction ci-dessous sous-entend 2 parametres: Instance de la classe courante (represente par l'espace apres la parenthese)
		// et l'autre parametre (Integer const & rhs) ce qui fait du sens sachant que l'operateur = est une operateur binaire qui prends 2 operand
		// rhs = signifie right hand side et est utile ici par que l'operator lfs (left hand side est cache) :
		// il s'agit d'une instance de la classe courante.
		// l'operateur cache est l'equivalent de "this", reference a l'instance de la Classe elle-meme. 
		Integer & operator=( Integer const & rhs);
		Integer	  operator+( Integer const & rhs) const;
	
};

std::ostream & operator<<(std::ostream & o, Integer const & rhs);

#endif