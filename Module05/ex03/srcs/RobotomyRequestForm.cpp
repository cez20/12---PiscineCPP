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
	std::cout << "[ROBOTOMY CONSTRUCTOR W ARG] Constructor has been called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
: AForm("Shrubbery", src.getTarget(), 72, 45)
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

/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	isFormExecutable(executor);

	std::cout 	<< "Bzzz zzzzz Bzzzzz zzzzz. " << std::endl;
	srand(time(NULL));

	if (rand() % 2  == 0)
        std::cout << getTarget() << " robotomy was sucessfully done" << std::endl;
    else
        std::cout << getTarget() << " robotomy failed" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */