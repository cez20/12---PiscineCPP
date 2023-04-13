/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:28:58 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/22 12:48:49 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

//Concept de retour par reference 
// Qu'est-ce que le const fait speficifiquement
// Reference complete les pointeurs, il ne remplace pas les pointeurs.
// une reference ne peut pas pointeur sur qqchose de null.
// Si j'utilise une variable et que celle-ci ne changent jamais = reference
// Si j'utilise une variable et que celle-ci est amene a change (null a valeur, a autre valuer = poitneur
class Student {

private:
	std::string _login;

public:
	Student(std::string const & login): _login (login)
	{
	}
	std::string& getLoginRef()
	{
		return this->_login;
	}
	std::string const & getLoginRefConst() const{
		return this->_login;
	}
	std::string*	getLoginPtr()
	{
		return &(this->_login);
	}
	std::string const * getLoginPtrConst() const{
		return &(this->_login);
	}
};


int main()
{
	Student bob = Student("bfubar");  
	Student const jim = Student("jfubar");

	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl; 

	bob.getLoginRef() = "bobfubar"; // Modifie le login par Reference 
	std::cout << bob.getLoginRefConst() << std::endl;

	*(bob.getLoginPtr()) = "bobbyfubar"; // Modifie le login par pointeur
	std::cout << bob.getLoginRefConst() << std::endl;

	return (0);
}	