/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:01:34 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/04 12:29:42 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie{

	private:
		std::string _name;

	public:
		Zombie(void); 
		~Zombie(void);
		void setName(std::string name);
		std::string getName();
		void announce();
};

Zombie* zombieHorde(int N, std::string name);