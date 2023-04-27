#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(): AForm ("Robotomy", "target", 72, 45)
{
	std::cout << "[ROBOTOMY DEFAULT CONSTRUCTOR] Constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm ("Robotomy", target, 72, 45)
{
	std::cout << "[ROBOTOMY CONSTRUCTOR W ARGS] Constructor has been called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
: AForm("Shrubbery", "target", 72, 45)
{
	std::cout << "[ROBOTOMY COPY CONSTRUCTOR] Copy construtor is called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[SHRUBBERY DESTRUCTOR] DESTRUCTOR is called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */