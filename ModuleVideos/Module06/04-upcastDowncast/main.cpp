/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:43:10 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/25 14:08:30 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
Nous utilisons ici les cast du langage C pour etre logique avec les exemples precedents!
Mais il est important de savoir que le langage C++, possede ces propres cast. 
*/ 

#include <iostream>

class Parent{};  // Classe de base (general)
class Child1: public Parent{};  // Classe derive (plus precise)
class Child2: public Parent {};  // Classe derive (plus precise)

/* Les exemples ici font reference a des classes allant du plus general au plus precis.
	Nous allons voir comment le reintepretation des addresses se fait avec des classe
	plutot qu'avec des types de variables (int *, void*, int const *) comme dans les exemples precedents.
*/

int main(void)
{
	Child1		a;
	
	Parent *b = &a;					// Implicit reinterpretation cast
	Parent *c = (Parent *) &a;      // Explicit reinterpretation cast
	
	Parent *d = &a;					// Implicit upcast -> Ok
	Child1 *e = d;					// Implicit downcast -> Hell, no!
	Child2 *f = (Child2 *) d;		// Explicit downcast -> Ok, might compile,but will probably cause problem at runtime

	return (0);
}