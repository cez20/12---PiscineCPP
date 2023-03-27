/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:29:29 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/27 15:58:28 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

class Weapon{

	private:
		std::string type;
		
	public:
		Weapon(std::string);
		~Weapon();
		const std::string& getType(); // Il faut que ce une refence vers un string de type string.  
		void  setType(std::string);

};