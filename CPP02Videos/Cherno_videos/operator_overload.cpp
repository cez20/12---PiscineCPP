/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_overload.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:26:20 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/04/04 20:28:01 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

struct Vector2{

	float x, y;

	Vector2(float x, float y)
		: x(x), y(y) {}
	// Takes a reference to a Vector and it is const because it does not modify the class, simply return new vector	
	Vector2 Add(const Vector2 & other) const{
		
		std::cout << "The value of other.x : " << other.x << std::endl;
		std::cout << "The value of this.x is: " << this->x << std::endl;
		std::cout << "The value of other.y : " << other.y << std::endl;
		std::cout << "The value of this.y is: " << this->y << std::endl;
		return Vector2(x + other.x, y + other.y);
	}

	// This function takes only 1 arugments, but there are 2 in facts
	// 1st argument is the Vector 2 itself which correspondond to the operand on left side (position)
	// 2nd arguemnt is the Vector 2 correspond to the rhs operator  = speed 
	Vector2 operator+(const Vector2 &other) const
	{
		return Add(other);
	}

// Another way with a different syntax, 
	// Vector2 Add(const Vector2 & other) const{
		
	// 	return operator+(other);  //Retourne le resultat de la fonction operator+ avec arugment other_

	// Vector2 operator+(const Vector2 &other) const
	// {
	// 	return Vector2(x + other.x, y+ other.y)
	// }

	Vector2 Multiply(const Vector2 other) const
	{
		return Vector2(x * other.x, y + other.y);
	}

	Vector2 operator*(const Vector2 other) const
	{
		return Multiply(other);
	}
};


// Creating my own std::ostream to be able to display content of specific vector
std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << " , " << other.y;
	return (stream);
}




int main()
{
	Vector2 position (4.0f, 4.0f);
	Vector2 speed (0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	//Vector2 result1 = position.Add(speed.Multiply(powerup)); // kind of Java or other oriented object structure

	//C++ will allow to avoid with operator overloading a code that is more readable
	// As we know, Vector2 instance takes 2 arguments to be creates.
	// In this class, the operator+ has been modified to sum 2 already existing Vector
	// Therefore, result 2 will take in parameter the value x (sum of x.position and x.speed)
	// and sum of y.position + y.speed) 
	Vector2 result2 = position + speed * powerup;
	

	//std::cout allows me to printout content of variable already defined in its class:
	//int, float, double, string, etc.
	// However, it doesn't not know, how to print a Class that I created, because all class are diffenrently built
	//std::cout << result2.x << std::endl;
	//std::cout << result2.y << std::endl;
	
	std::cout << result2 << std::endl;
	std::cin.get();
}


// Other nice examples: Analyze these examples more throughluy. 

// bool	operator==(const Vector2& other) const
// {
// 	return (x == other.x && y == other.y);
// }

// bool operator!=(const Vector2& other) const
// {
// 	return !(operator==(other))
// }