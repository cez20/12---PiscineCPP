/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:50:22 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/27 16:04:18 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB{

	private:
		std::string Weapon;
		std::string name;
		
	public:
		HumanB(std::string name); // Constructeur qui assigne nom 
		~HumanB(); //Destructeur
		void setWeapon(std::string);
		void attack();

	
};