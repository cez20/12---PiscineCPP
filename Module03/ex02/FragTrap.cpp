#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : Claptrap()
{
	this->_hitpoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	
	std::cout << "[DEFAULT CONSTRUCTOR] FragTrap default constructor is called!" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){

	this->_hitpoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	
	std::cout << "[CONSTRUCTOR WITH ARG] FragTrap constructor "
			  << "is called and creates a robot derived from ClapTrap"
			  << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src._name)
{
	std::cout << "[COPY CONSTRUCTOR] FragTrap copy constructor has been called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "[DESTRUCTOR] FragTrap destructor has been called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "[OPERATOR OVERLOAD] FragTrap equal operator assignment has been called" << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
		this->_hitpoints = rhs.getHitpoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getDamage();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFiveGuys(void){

	std::cout << "[HIGHFIVEGUYS METHOD] FragTrap robot " << getName() 
			  << " ask for a High Five, guys! Up top!" << std::endl;
}

/* ************************************************************************** */