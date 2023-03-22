/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_and_delete.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:06:16 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/21 22:17:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_and_delete.hpp"

Student::Student(std::string login): _login(login) {
	
	std::cout << "Student " << this->_login << " is born" << std::endl;
}

Student::~Student() {
	std::cout << "Student " << this->_login << " died" << std::endl;
}