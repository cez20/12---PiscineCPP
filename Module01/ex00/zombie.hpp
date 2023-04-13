/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:49:49 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/24 12:52:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// Declaration de la classe Zombie

class Zombie{

private:
	std::string _name;
	
public:
	Zombie(std::string name); // Constructeur : fonction qui cree un object(instance) Zombie
	~Zombie();                // Destructeur : fonction qui detruit une instance Zombie
	void announce(void);      //Fonction membre qui invite le zombie a dire son nom
};

//Prototype des fonctions non-membres:
Zombie*	newZombie(std::string name); 
void	randomChump(std::string name);