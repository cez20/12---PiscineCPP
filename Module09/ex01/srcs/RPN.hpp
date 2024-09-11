#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <algorithm> // This is for std::remove_if
# include <cctype> // For isspace? 
# include <stack>

class RPN
{
	public:

		RPN();
		RPN(std::string s);
		RPN( RPN const & src );
		~RPN();

		RPN &		operator=( RPN const & rhs );

		void		parse();
		bool		isOperator(char c);
		int			calculate(int operand1, int operand2 , char op);

	private:
		int				_total;
		std::string		_mathString;
		std::stack<int> _mystack;

};

#endif /* ************************************************************* RPN_H */