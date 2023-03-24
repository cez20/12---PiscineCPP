/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:01:34 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/24 14:22:04 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


class Zombie{

	private:
		std::string _name;

	public:
		Zombie(void);  // Constructor
		~Zombie(void); // Destructor
		void setName(std::string name);
		std::string getName();
		void announce(void);
};

Zombie* zombieHorde(int N, std::string name); //Fonction non-membre.