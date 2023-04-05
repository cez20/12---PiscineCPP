/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:29:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/05 16:47:48 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{

private:
	int	_nbr; // stocke la valeur du nombre en virgule fixe une fois qu'on lui mets 8bits de chiffres fractionnaire a gauche
	static int const _bits; //stock le nombre de chiffres de la partie fractionnaire

public:
	Fixed(); 
	Fixed(Fixed const & src);  
	Fixed(int const & nbr); // Constructeur prenant un entier constant
	Fixed(float const & nbr); // Constructeur prenant un flottant 
	~Fixed(); 

	Fixed & operator=(Fixed const & rhs);

	//float	toFloat(void) const; // convertit la valeur en virgule fixe en nombre a virgule flotante
	int		toInt(void) const; // Convertit la valeur en virgule fixe en nombre entier.  

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};

std::ostream & operator<<(std::ostream & output, Fixed const & input);


#endif