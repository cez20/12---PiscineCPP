/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:40:44 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/25 15:44:32 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Scope global 

int	gl_var = 1; // Declaration d'une variable globale = gl_var
int	f(void) {return 2; }   // Creation d'une fonction f  qui renvoie un int et qui ne prend aucun parametre et qui retourne la constante 2 


//Les namespaces definissent un nouveau scope (un sous-scope) et tout ce qu'on met a l'interieur de ce namespace, appartiendra a ce namespace.
// Les namespaces n'entreront pas en conflit avec les declarations de variable se trouvant dans le scope global ci-haut 


//  Sous-scope #1 appele foo
namespace Foo {
	int	gl_var = 3; 
	int	f(void) {return 4; }  	
} 

// Sous-scope #2 appele Bar 
namespace Bar {
	int	gl_var = 5;
	int Cesar = 1099;
	int	f(void) {return 6; }
} 

// Aliasing de namespace sert a donner un nom different a un namespace. 
//Souvent utilise pour donner une nom plus court a un long namespace.
// Dans le cas ici-bas, l'utilisation du namespace Muf sert a referer au namespace Bar.  
namespace Muf = Bar;


int main(void)
{
	printf("gl_var:             [%d]\n", gl_var);
	printf("f():                [%d]\n\n", f());

	printf("Foo::gl_var:        [%d]\n", Foo::gl_var);
	printf("Foo::f():           [%d]\n\n", Foo::f());

	printf("Bar::gl_var:        [%d]\n", Bar::gl_var);
	printf("Bar::f():           [%d]\n\n", Bar::f());

	printf("Muf::gl_var:        [%d]\n", Muf::gl_var);
	printf("Muf::f():           [%d]\n\n", Muf::f());

	printf("gl_var:             [%d]\n", ::gl_var);
	printf("f():                [%d]\n", ::f());

	return (0);

}