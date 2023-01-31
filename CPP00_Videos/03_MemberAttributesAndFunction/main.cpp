/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:09:15 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/25 18:56:57 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SampleClass.hpp"


// Ici on montre la creation d'une instance (un cas) de la classe Sample
// Nous aurions pu appele l'instance d'un autre nom comme Cesar au lieu de "instance"

int main(){

	Sample instance; 

	instance.foo = 42;
	std::cout << "instance foo: " << instance.foo << std::endl;

	instance.bar();
	
	return 0;	
}
