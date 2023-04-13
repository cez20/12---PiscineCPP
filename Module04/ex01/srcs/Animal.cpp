#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal(): type("NONE"){
	std::cout << "[DEFAULT CONSTRUCTOR] Animal default constructor has been called!" << std::endl;
}

Animal::Animal( const Animal & src ){

	std::cout << "[COPY CONSTRUCTOR] Animal Copy constructor has been called!" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal(){
	std::cout << "[DESTRUCTOR] Animal destructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal & Animal::operator=( Animal const & rhs )
{
	std::cout << "[OPERATOR OVERLOAD] Animal Equal operator overload has been called!" << std::endl;
	if ( this != &rhs )
	{
		this->type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Animal::getType() const{

	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "[MAKE SOUND] Animal DOES NOT do any sound because no animal is precised" << std::endl;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */