#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>
# include <sstream>

class Scalar
{
	public:

		Scalar(std::string const & input);
		Scalar( Scalar const & src );
		~Scalar();

		Scalar &		operator=( Scalar const & rhs );

		std::string toChar() const;
		std::string toInt() const;
		std::string toFloat() const;
		std::string toDouble() const;
		bool		isInteger(std::string input);
		void		analyzeInput();

	private:
		enum	InputType { isChar, isInt, isFloat, isDouble };

		Scalar();
		std::string _input;
		bool		_error;
		char 		_char;
		int			_int;
		InputType	type;


		

};

std::ostream &			operator<<( std::ostream & o, Scalar const & i );

#endif /* ********************************************************** SCALAR_H */