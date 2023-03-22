/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:09:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/21 23:04:18 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_and_delete.hpp"


int main()
{
	Student bob = Student("bfubar");  // objet bob cree sur la stack 
	Student* jim = new Student("jbufar"); // objet jim cree sur la heap en assignant de la memoire avec new 

	delete jim;  // Delete est l'equivalent de free(); 

	return (0); // Destructor is called 
}


//Dans le cas ici-bas, nous ne pouvons pas cree un objet bob de type Student, car en effectuant cette tache, il appelle
//le constructor qui lui exige un string. On doit donc rappeler le constructeur
// int main()
// {
// 	Student bob; 


// 	return (0); // Destructor is called 
// }