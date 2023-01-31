/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample_Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:32:57 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/01/26 10:07:39 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample{

public:

	int	publicFoo;
	
	Sample(void);
	~Sample(void);

	void	publicBar(void) const;

private:

	int		_privateFoo;
	
	void	_privateBar(void) const;
	
};


#endif