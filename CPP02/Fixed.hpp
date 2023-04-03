/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:29:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/03 17:55:25 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{

private:
	int	_nbr; // Maybe call it raw bits.  
	int static const _nbr1 = 8; // Is it the right time to assign it forever ?

public:
	Fixed(); // Default Constructor
	Fixed(Fixed const & src);  // Constructor de recopie 
	~Fixed(); // Destructor 

	Fixed & operator=(Fixed const & rhs); // Surcharge de l'operateur d'affectation 

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};


#endif