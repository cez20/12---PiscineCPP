/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/07 13:05:48 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {

private:
	std::string		_name;
	unsigned int	_hitpoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	ClapTrap();  // Default Constructor 
	ClapTrap(std::string name); 
	ClapTrap(ClapTrap const & src); // Constructor de recopie
	~ClapTrap(); // Destructeur 

	ClapTrap & operator=(ClapTrap const & rhs); // Operator overload. 

	void		attack(const std::string & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	
	void		getInfo();
	std::string getName() const;
	int			getHitpoints() const;
	int			getEnergyPoints() const;
	int			getDamage() const;

};

#endif 



