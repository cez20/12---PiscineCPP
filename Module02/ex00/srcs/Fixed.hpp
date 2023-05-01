/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:29:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/01 18:46:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{

private:
	int	_nbr; 
	static int const _bits;

public:
	Fixed(); 
	Fixed(Fixed const & src);
	~Fixed();

	Fixed & operator=(Fixed const & rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};


#endif