#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap( ScavTrap const & src );
	~ScavTrap();

	ScavTrap & operator=( ScavTrap const & rhs );

	void			guardGate();
	virtual	void	attack(const std::string & target);

};

#endif /* ******************************************************** SCAVTRAP_H */