#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>

#define IMPOSSIBLE 0
#define CHAR 1
#define INTEGER 2
#define FLOAT 3
#define DOUBLE 4
#define PSEUDOFLOAT 5

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

		void		printChar();
		void		printInt();
		void		printFloat(std::string & entry);
		void 		printDouble(std::string & entry);
		

		int			findNbrOfDots(std::string & entry);
		bool		isPseudoLiteralFloat(std::string & entry);
		bool		isPseudoLiteralDouble(std::string & entry);
		bool		isNan(double 	nan);
		bool		isInfinite(double nbr);
		std::string createString(std::string & entry, std::string const &type);


	private:

		Scalar();
		char		_char;
		int			_int;
		float		_float; 
		double		_double;
		int			_type;

};





#endif /* ********************************************************** SCALAR_H */