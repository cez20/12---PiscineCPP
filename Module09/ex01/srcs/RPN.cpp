#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN() {}

RPN::RPN(std::string s): _rpnTotal(0), _rpnExpression(s){

}


RPN::RPN( const RPN & src ) {

  *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
	{
		this->_rpnTotal = rhs._rpnTotal;
    this->_rpnExpression = rhs._rpnExpression;
    this->_mystack = rhs._mystack;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	RPN::parse(){

      if(!isExpressionDigits(_rpnExpression))
        throw std::runtime_error("ERROR! Math expressions is not only composed of digits. There is a number!");
      
      _rpnExpression.erase(std::remove_if(_rpnExpression.begin(), _rpnExpression.end(), ::isspace), _rpnExpression.end()); //TODO: Fix the problem of ::isspace vs std::isspace
      
      if(!hasExpressionValidCharacters(_rpnExpression))
        throw std::runtime_error("ERROR! Math expression is composed of elements different than + - * / and digits!");

      int operand1 = 0;
      int operand2 = 0;

      for (size_t i = 0; i != _rpnExpression.size(); ++i){
        if(isOperator(_rpnExpression[i])){
          retrieveOperands(operand1, operand2);
          calculate(operand1, operand2, _rpnExpression[i]);
          _mystack.push(_rpnTotal);
        } else {
          _mystack.push(_rpnExpression[i] - '0');
        }
      }
      std::cout << _rpnTotal << std::endl;
} 

bool RPN::isOperator(char c){

  if(c == '+' || c == '-' || c == '*' || c == '/')
    return true;
  return false;
}

bool RPN::isExpressionDigits(std::string& str){
  
  for (size_t i = 0; i < str.size(); ++i) {
    if(isdigit(str[i]) && (i + 1 < str.size()) && isdigit(str[i + 1]))
      return false;
  }
  return true;
}

bool RPN::hasExpressionValidCharacters(std::string& str){

  for (size_t i = 0; i < str.size(); ++i){
    if(str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && !isdigit(str[i]))
      return false;
  }
  return true;
}

void RPN::retrieveOperands (int& operand1, int& operand2){
    
    if (_mystack.empty())
        throw std::runtime_error("ERROR! Invalid RPN mathematical expression (empty stack for operand2)");

    operand2 = _mystack.top();
    _mystack.pop();

    if (_mystack.empty())
        throw std::runtime_error("ERROR! Invalid RPN mathematical expression (empty stack for operand1)");

    operand1 = _mystack.top();
    _mystack.pop();
}

void RPN::calculate(int operand1, int operand2, char op){

    switch(op) {
      case '+':
        _rpnTotal = operand1 + operand2;
        break;
      case '-':
        _rpnTotal = operand1 - operand2;
        break;
      case '*':
        _rpnTotal = operand1 * operand2;
        break;
      case '/':
        _rpnTotal = operand1 / operand2;
        break;
      default:
        std::cerr << "Error: Invalid operator" << std::endl;
    }

}

/* ************************************************************************** */