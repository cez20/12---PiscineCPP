/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:49:49 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/13 14:38:26 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie{

private:
	std::string _name;
	
public:
	Zombie(std::string name); 
	~Zombie();                
	void announce(void);   
};

//Prototype des fonctions non-membres:
Zombie*	newZombie(std::string name); 
void	randomChump(std::string name);
