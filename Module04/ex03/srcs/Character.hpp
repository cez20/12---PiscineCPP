/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 22:32:25 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/21 13:22:54 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria*	_inventory[4]; // Un array de [4] dont chaque case contient un ptr vers un AMateria 
		AMateria*	_droppedInventory[10];
		std::string	_name;
	
	public:

		Character();
		Character(std::string const & name);
		Character( Character const & src );
		virtual ~Character();

		Character &		operator=( Character const & rhs );

		virtual std::string const & getName() const;
		virtual void 				equip(AMateria* m);
		virtual void 				unequip(int idx);
		virtual void 				use(int idx, ICharacter& target);
		void						printInventory();
		void						fillDroppedInventory(int idx);

};

#endif /* ******************************************************* CHARACTER_H */