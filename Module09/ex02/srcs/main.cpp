/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:41:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2024/09/11 17:04:24 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 2) {
        (void)argv;
    } else {
        std::cout << "ERROR! Program should take a string of unsigned integers as argument!" << std::endl;
        return 1;
    }
    return 0;
}