/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:22:37 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/25 14:29:23 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Parent{};  // Classe de base (general)
class Child1: public Parent{};  // Classe derive (plus precise)
class Child2: public Parent {};  // Classe derive (plus precise)

class Unrelated             {};

/* Les exemples ici font reference a des classes allant du plus general au plus precis.
	Nous allons voir comment le reintepretation des addresses se fait avec des classe
	plutot qu'avec des types de variables (int *, void*, int const *) comme dans les exemples precedents.
*/

/* 
The concept of upcast, is when you cast in order to go from a precise to a more general type
The concept of downcast, is when you cast in order to go from a general to a more precise type
Therefore, alwasy look at the info next to equal (ex: Parent *b = &a ). We look at info, on the right.
&a is a child1, so if I want it to become the Parent * , I need to go UP, in the hierary tree.
 */


int main(void)
{
	Child1		a;
	
	Parent *b = &a;							// Implicit upcast 
	Child1 *c = b;                 			// Implicit downcast -> Hell no!
	Child2 *d = static_cast<Child2 *>(b);	// Explicit downcast -> Ok, I obey.

	Unrelated *e = static_cast<Unrelated *>(&a);	// Explicit conversion -> No


	return (0);
}