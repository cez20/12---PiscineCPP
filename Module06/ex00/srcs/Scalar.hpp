#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>

#define isError 0
#define isChar 1
#define isInteger 2
#define isFloat 3
#define isDouble 4

class Scalar
{
	public:

		Scalar(std::string entry);
		Scalar( Scalar const & src );
		~Scalar();

		Scalar &		operator=( Scalar const & rhs );

		void	detectType(std::string & entry);

		void	convertToAllTypes(std::string & entry);
		void	convertToChar(std::string & entry);
		void	convertToInteger(std::string & entry);
		void	convertToFloat(std::string & entry);
		void	convertToDouble(std::string & entry);

		void	printChar();
		void	printInt();
		void	printFloat(std::string & entry);
		void 	printDouble(std::string & entry);

	private:

		Scalar();
		char		_char;
		int			_int;
		float		_float; 
		double		_double;
		int			_type;

};

int findNbrOfDots(std::string & entry);
bool isPseudoLiteralFloat(std::string & entry);
bool isPseudoLiteralDouble(std::string & entry);


#endif /* ********************************************************** SCALAR_H */