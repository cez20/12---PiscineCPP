/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/09/11 14:20:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2){
      RPN mathExpression = RPN(argv[1]);
      
      try{
        mathExpression.parse();
      } catch (std::exception & e){
        std::cout << e.what() << std::endl;
      }
    } else {
        std::cout << "ERROR! Program needs RPN mathematical expression as an argument!" << std::endl;
        return 1;
    }
    return 0;
}