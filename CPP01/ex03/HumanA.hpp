/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:47:20 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/27 16:06:49 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA{

	private:
		std::string Weapon;
		std::string name;
		
	public:
		HumanA(std::string name, Weapon weaponA);
		void attack();

	
};