/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:50:22 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/04 12:53:09 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{

	private:
		std::string _nameB;
		Weapon*		_weaponB;
		
	public:
		HumanB(std::string const& name);
		
		void		setWeapon(Weapon& weapon);
		std::string getNameB();
		void		attack();
};

#endif 