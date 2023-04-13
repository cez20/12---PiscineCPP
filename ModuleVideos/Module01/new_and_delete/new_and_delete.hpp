/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_and_delete.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:54:00 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/21 22:08:26 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_AND_DELETE_HPP
#define NEW_AND_DELETE_HPP

#include <iostream>
#include <string>

class Student {

private:  // Est-ce que les variables private doivent toujours venir avant les publiques 
	std::string _login;

public:
	Student(std::string login);
	~Student();
};

#endif /* NEW_AND_DELETE_HPP */
