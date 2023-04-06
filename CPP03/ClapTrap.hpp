/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:23:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/05 20:47:20 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {

private:
	std::string _name;
	int			_hitpoints;
	int			_energyPoints;
	int			_attackDamage;

public:
	ClapTrap(std::string name);
	~ClapTrap();

	void		attack(const std::string & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	
	void		getInfo();
	std::string	getName();
	int			getHitpoints();
	int			getEnergyPoints();
	//void	getAttackDamage();

	//void	setHitpoints();
	//void	setEnergyPoints();
};

#endif 



