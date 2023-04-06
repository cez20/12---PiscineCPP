/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heritage3.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:18:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/05 18:27:56 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Niveau d'encapsulation 
1- Public
2- Private
3- Protected (seulement utilise dans les cas d'heritage)

*/
#include <string>

class Quadruped{ // can access name, legs and run()

	private:
		std::string	name; // Only accessible from an Quadruped object
		
	protected:
		Leg 	legs[4]; // Accessible from an Quadruped or derived object

	public:
		void	run();  // Accessible from wherever 
};

class Dog : public Quadruped{  // Can acces run and legs
	
};