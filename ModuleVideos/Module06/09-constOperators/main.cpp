/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:41:26 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/05/25 16:50:27 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Typecast operators:
Possiblite de faire des operateurs speciaux dans votre classe pour  faire des conversion implicites
de votre classe vers un type qui vous interesse 
 */

#include <iostream>

class Foo {

	public:

		Foo (float  const v): _v(v){}

		float getV(void) const 			{return this->_v;}

		operator float() const 			{return this->_v;}		
		operator int() const 			{return static_cast<int>(this->_v);}		

	private:
		float  _v;
};


int main(void)
{
	Foo  a(420.024f);
	float b = a;
	int   c = a;

	std::cout << a.getV() << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	return (0);
}
