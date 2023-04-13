/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:00:31 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/28 17:04:40 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Instead of passing a pointer, you can a pass a reference as a parameter
//If you wish to do so, you have to make sure that the variables
// will always exist and will never change , use a reference. Else, use a pointer.

#include <iostream>

void myFunction(int& myVariable) {
  // This line modifies the original variable
  myVariable = 10;
}

int main() {
  int x = 5;
  myFunction(x);
  // x is now equal to 10
  std::cout << x << std::endl;
}