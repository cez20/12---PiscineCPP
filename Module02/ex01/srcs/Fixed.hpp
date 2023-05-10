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

		Fixed & operator=(Fixed const & rhs);

		int		toInt(void) const; 
		float	toFloat(void) const; 

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		getFractionalBits() const;

	private:
		int				 _nbr;
		static int const _fractionalBits; 
};

std::ostream & operator<<(std::ostream & output, Fixed const & input);

#endif