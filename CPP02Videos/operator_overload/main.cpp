/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:19:32 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/03 15:39:46 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "integerClass.hpp"

// Prefix notation (+ 1 1)
// An expression in which the operator is before operand
// notation prefix est aussi appele notation fonctionnelle, car lorsqu'on transform l'expression
// + (1,1) ca ressemble beaucoup a une fonction OU
// Aussis a une instance de classe avec un appel a une fonction memebre   1.+ (1)
// Ex: l'instance 1, appelle la fonction '+' qui prend en parametres le chiffre 1. 


// infix notation or infix expression (ex: 1 + 1)
// An expression in which the operator is in the middle of operands (ex: le '+'   dans l'expression "1 + 1")


// Postfix notation (ex: 1 1 +)
// An expression in which the operator is after operand
// Ressemble beaucoup a ce qu'on appelle des calculs sur pile (ex: Je pousse un 1 sur la pile, suivi d'un autre 1)
// et j'effectue l'addition.  

// Il existe aussi le mot cle "operator" et different type d'operator
// Soit l'operateur : unaire, binaire, ternaire

// L'operateur d'assignation ('=') est binaire  pcq il a un operand a gauche et un autre a droit (ex: a = b)
// Il en est de meme pour les operatoeur +, - , *, /


// OPERATOR OVERLOAD : Regles a respecter
// La surchage d'un operateur soit naturelle
// La surchage d'operateur ait un rapport avec la semantique naturelle de cet operateur
// Ne pas faire de surcharge d'operateur : car  lorsqu'on pense que c'est une bonne idee, ce n'en ait pas une
// Le cas ou c'est utilise sont rares. 


int main(){

	Integer		x( 30);
	Integer		y(10);
	Integer		z(0);

	std::cout << "Value of x : " << x << std::endl; // Permet d'afficher le contenu de la variable x juste en appelant le nom de l'instance
	std::cout << "Value of y : " << y << std::endl;
	y = Integer(12); // Creation d'une nouvelle instance Integer avec la valeur 12. Il s'agit de la 4eme instance cree
	// Appel a l'operateur d'assignation "=" ici. 
	// l'instance Integer(12) n'etant plus utile.. elle est detruite. 
	std::cout << "Value of y : " << y << std::endl;

	std::cout << "Value of z : " << z << std::endl;
	z = x + y;  // L'operateur '=' cree une nouvelle instance (5eme instance) qui est detruite par la suite. 
	std::cout << "Value of z : " << z << std::endl;

	return (0); 
	
}