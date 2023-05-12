/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:14:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/12 14:48:17 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(int const & nbr);
		Fixed(float const & nbr);
		Fixed(Fixed const & src);  
		~Fixed(); 

		static			Fixed 		& 	min (Fixed & a, Fixed & b);
		static			Fixed const &	min (Fixed const & a, Fixed const & b);
		static			Fixed 		& 	max (Fixed & a, Fixed & b);
		static 			Fixed const & 	max (Fixed const & a, Fixed const & b);

		bool	operator>( Fixed const & rhs ) const;
		bool	operator<( Fixed const & rhs ) const;
		bool	operator>=( Fixed const & rhs ) const;
		bool	operator<=( Fixed const & rhs ) const;
		bool	operator==( Fixed const & rhs ) const;
		bool	operator!=( Fixed const & rhs ) const;
		
		Fixed & operator= (Fixed const & rhs);
		Fixed 	operator+ (Fixed const & rhs) const;
		Fixed 	operator- (Fixed const & rhs) const;
		Fixed 	operator* (Fixed const & rhs) const;
		Fixed   operator/ (Fixed const & rhs) const;

		Fixed &	operator++ ();
		Fixed   operator++ (int);
		Fixed &	operator-- ();
		Fixed 	operator-- (int);


		int		toInt(void) const;
		float	toFloat(void) const;

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int				 _nbr;
		static int const _fractionalBits; 
};

std::ostream & operator<<(std::ostream & output, Fixed const & input);

#endif