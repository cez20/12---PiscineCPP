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
		bool		isExpressionDigits(std::string & str);
		bool 		hasExpressionValidCharacters(std::string & str);
		void 		retrieveOperands(int& operand1, int& operand2);

		void		calculate(int operand1, int operand2 , char op);

	private:
		int				_rpnTotal;
		std::string		_rpnExpression;
		std::stack<int> _mystack;

};

#endif /* ************************************************************* RPN_H */