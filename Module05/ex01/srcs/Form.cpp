/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:08:38 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/07/05 08:42:31 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(): _name("Default form"), _gradeToSign(150), _gradeToExecute(150)
{
	verifyGrade();
	this->_isSigned = false;
	std::cout << "[FORM DEFAULT CONSTRUCTOR] Default constructor is called" << std::endl;
}

Form::Form(std::string const name, unsigned int const sign, unsigned int const exec): _name(name), _gradeToSign(sign), _gradeToExecute(exec)
{
	verifyGrade();
	this->_isSigned = false;
	std::cout << "[FORM CONSTRUCTOR W ARGS] Constructor with argument is called" << std::endl;
}


Form::Form( const Form & src ): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	verifyGrade();
	this->_isSigned = false;
	std::cout << "[FORM COPY CONSTRUCTOR] Copy constructor is called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "[FORM DESTRUCTOR] Destructor is called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
		this->_isSigned = false;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Form::verifyGrade() const
{
	if (this->_gradeToSign < HIGHEST_GRADE || this->_gradeToExecute < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	else if (this->_gradeToSign > LOWEST_GRADE || this->_gradeToExecute > LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

void	Form::beSigned(Bureaucrat & b)
{
	if (b.getGrade() > this->_gradeToSign)
	{
		this->_isSigned = false;
		std::cout << b.getName() << " couldn't signed " << this->_name 
		<< " because its grade was too low!" << std::endl;
		throw Form::GradeTooLowException();
	}
	this->_isSigned = true;
	std::cout << b.getName() << " signed " << this->_name << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & Form::getName() const
{
	return (this->_name);
}

bool Form::getSignStatus() const
{
	return (this->_isSigned);
}

unsigned int const & Form::getGradeToSign() const 
{
	return (this->_gradeToSign);
}

unsigned int const & Form::getGradeToExecute() const 
{
	return (this->_gradeToExecute);
}

/* ************************************************************************** */

std::ostream &			operator<<( std::ostream & o, Form const & form)
{
	o << "Form Name: " << form.getName() << std::endl;
	o << "Form is signed? : " << form.getSignStatus() << std::endl;
	o << "Minimum grade needed for Form to be signed: " << form.getGradeToSign() << std::endl;
	o << "Minimum grade needed for Form to be executed: " << form.getGradeToExecute() << std::endl;
	return o;
}
