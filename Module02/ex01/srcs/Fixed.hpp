/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:29:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/09 19:50:10 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{

private:
	int				 _nbr;
	static int const _fractionalBits; 

public:
	Fixed();
	Fixed(int const & nbr);
	Fixed(float const & nbr);
	Fixed(Fixed const & src);  
	~Fixed(); 

	Fixed & operator=(Fixed const & rhs);

	int		toInt(void) const; 
	float	toFloat(void) const; 

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};

std::ostream & operator<<(std::ostream & output, Fixed const & input);

#endif