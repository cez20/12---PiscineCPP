/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:09:01 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/29 11:38:01 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	L'utilisation des mots cles "Dynamic_cast" "reinterpret_cast", etc agissent quelquepeu comme une fonction
	ou chacun des termes ci-haut agisse comme une fonction
		Dynamic_cast = nom de la fonction
		<int> = serait l'equivalent d'un parametre qui est la cible, ou le type de donnes vers lequel on veut changer
	
	By default, C++ language always authorize a implicit cast. 
	
 */

#include <iostream>

class A {};
class B {};

class C {

	public:
					C (A const & _) { return; }
		explicit	C( B const & _)	{ return; }
};



void	f(C const & _) {

	return ;
}

int main(void)
{
	f ( A() );  // Implicit conversion Ok . Essentially, Fonction "f" takes a reference to C, but this expression to C will be implicity cast to reference to class A
	f ( B() );  // Explicit conversion NOT OK, constructor is explicit. If we comment it, the program will compile. 

	return 0;
}


// Puisque que la fonction f prend une instance de C et que dans C, on voit que nous avons besoin d'une classe A pour
// construire une instance de C, cela va bien fonctionner, car il va y avoir une conversion implicite de A vers C
// avant l'appel de la fonction f 

// A l'oppose, nous ne pouvons execute l'exemple avec B, parce que le mot cle "explicit" est precise avant.
// Cela veut dire que le compilateur interdit la conversion implicite de B vers C. Il aurait donc fallu creer
// une instance de C avec le constructeur qui prend un B en parametre et envoyer cette instance de C a la fonction f
