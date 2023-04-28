#include "RobotomyRequestForm.hpp"
#include <ctime>

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

// std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try{
		isFormExecutable(executor);
	}catch(std::exception &e){
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout 	<< "Bzzz zzzzz Bzzzzz zzzzz. " << std::endl;

	// srand(time(NULL));

    // // Generate a random number between 0 and 1
    // double random = (double) rand() / RAND_MAX;

    // Display the message 50% of the time
    if (rand() % 2 == 0)
        std::cout << "Robotomy was sucessfully done" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */