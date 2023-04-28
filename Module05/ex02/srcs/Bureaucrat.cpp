#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(): _name(), _grade()
{
	std::cout << "[BUREAUCRAT DEFAULT CONSTRUCTOR] Constructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "[BUREAUCRAT CONSTRUCTOR W ARGUMENTS] Constructor for " << this->_name << " has been called" << std::endl;
}


Bureaucrat::Bureaucrat( const Bureaucrat & src ): _name(src._name), _grade(src._grade)
{
	std::cout << "[BUREAUCRAT COPY CONSTRUCTOR] COPY Constructor has been called" << std::endl;
	*this = src; 
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "[BUREAUCRAT DESTRUCTOR] Destructor for " << this->_name << " has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooLowException();
		else if (this->_grade > 150)
			throw Bureaucrat::GradeTooHighException();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Bureaucrat::getName() const
{
	return (this->_name);
}


unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade(){

	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decreaseGrade(){

	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too HIGH");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too LOW");
}

void			Bureaucrat::signAForm(AForm & f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << getName() << " cannot sign " << f.getName() << " form because "
		<< e.what() << std::endl;
	}
}

void	Bureaucrat::printData() const 
{
	std::cout	<< "\nBureaucrat's name: " << getName() << "\n"
				<< "Bureaucrat's grade: " << getGrade() << "\n\n";
}


/* ************************************************************************** */