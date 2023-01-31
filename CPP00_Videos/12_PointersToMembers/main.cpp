/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:02:07 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/27 12:32:43 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample_Class.hpp"

int main(){

	Sample	instance;
	Sample	*instancep = &instance; // Creation d'une instance de type pointeur qui pointe ver la premier instance

	int		Sample::*p = NULL;  // Je declare ici un pointeur sur int appelle *p. Ce pointeur pointe sur un element membre de la classe Sample (d'ou la raison du Sample:: avant la declaration du pointeur )
	void	(Sample::*f)(void) const;  // On declare ici un pointeur sur fonction nomme *f. Ce pointeur de fonction pointe sur une fonction membre de sample qui ne prend pas de parametre (void) et qui est constante.  

	
	// On assigne notre pointeur sur un int membre de la classe Sample ----> a l'adresse de foo (attributs membre). On se doit de preciser que celui fait partie de la classe Sample::
	// Par contre a cette etape, il est nullement precise a quelle instance p est associe. 
	p =  &Sample::foo;      

	
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance.*p = 21;		// Operateur ".*" permet de precise a quel instance de Sample of fait reference (Ex: <nom de linstance>.* < nom de la variable> )
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instancep->*p = 42;	    // Operateur "->*" est utilise ici, lorsqu'on fait reference a un pointeur. 
	std::cout << "Value of member foo: " << instance.foo << std::endl;


	f =  &Sample::bar; // On assigne a notre pointeur de fonction "f" la fonction bar 
	
	(instance.*f)();  // Ici on precise qu'on appelle "f" qui fait reference a l'instance nomme "instance"
	(instancep->*f)(); // Ici on precise qu'on appelle "f" qui fait reference au pointeur sur instance nomme "instancep"
}