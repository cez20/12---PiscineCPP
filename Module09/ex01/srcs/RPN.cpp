#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN() {}

RPN::RPN(std::string s): _mathString(s){

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
		this->_total = rhs._total;
    this->_mathString = rhs._mathString; //TODO: Put getter for this as it is cleaner
    this->_mystack = rhs._mystack;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool RPN::isOperator(char c){

  if(c == '+' || c == '-' || c == '*' || c == '/')
    return true;
  return false;
}

void	RPN::parse(){

      _mathString.erase(std::remove_if(_mathString.begin(), _mathString.end(), ::isspace), _mathString.end()); //TODO: Fix the problem of ::isspace vs std::isspace
      
      int operand1 = 0;
      int operand2 = 0;

      for (size_t i = 0; i != _mathString.size(); ++i){
        if(isOperator(_mathString[i])){
          operand2 = _mystack.top();
          _mystack.pop();
          operand1 = _mystack.top();
          _mystack.pop();
          _total = calculate(operand1, operand2, _mathString[i]);
          _mystack.push(_total);
        }
        else {
          _mystack.push(_mathString[i] - '0');
        }
      }
      std::cout << "The total of the RNP is: " << _total << std::endl;
} 


int RPN::calculate(int operand1, int operand2, char op){

    int total;

    switch(op) {
      case '+':
        total = operand1 + operand2;
        break;
      case '-':
        total = operand1 - operand2;
        break;
      case '*':
        total = operand1 * operand2;
        break;
      case '/':
        total = operand1 / operand2;
        break;
      default:
        std::cerr << "Error: Invalid operator" << std::endl;
        return 0;
    }
    return total;  
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */