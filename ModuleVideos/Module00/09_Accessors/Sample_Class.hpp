/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:51:16 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 11:10:09 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{
	
public:


	Sample(void);
	~Sample(void);

	int	getFoo(void)	const;  // Allow to get the value of private attribute _foo 
	void setFoo(int v); // Allows to set the value of private attribute _foo;


private:

	int	_foo;
};


#endif