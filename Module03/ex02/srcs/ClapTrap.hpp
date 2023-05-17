/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/16 19:12:07 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

	# define RESET "\e[0m"
	# define RED "\e[0;31m"
	# define GRN "\e[0;32m"
	# define CYN "\e[0;36m"
	# define YEL "\e[0;33m"
	# define REDB "\e[41m"

#include <string>

class ClapTrap {

protected:
	std::string		_name;
	unsigned int	_hitpoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	ClapTrap();  // Default Constructor 
	ClapTrap(std::string name); 
	ClapTrap(ClapTrap const & src); // Copy constructor 
	virtual ~ClapTrap(); // Destructor

	ClapTrap & operator=(ClapTrap const & rhs); // Operator overload. 

	virtual	void attack(const std::string & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	
	void		getInfo();
	std::string getName() const;
	int			getHitpoints() const;
	int			getEnergyPoints() const;
	int			getDamage() const;

};

#endif 



