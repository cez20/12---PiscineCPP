/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:07:52 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/03 13:16:54 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

//Essentially, ad-hoc polymorphism simply says that it is possible to have
// multiple function (either member of not member) with the same name as long as 
// they take different parameters. In order to call the right functions, we simply
// need to put the right arugment in the functino and the right function will call itself. 


int main(){

	Sample sample;
	
	sample.bar('Z');
	sample.bar(42);
	sample.bar("Cesar Menjivar");

	return (0);
}