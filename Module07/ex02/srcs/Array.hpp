#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template < typename T >
class Array
{

	public:

		Array(): array(NULL), arraySize(0){
			std::cout << "[DEFAULT CONSTRUCTOR] has been called" << std::endl;
		}
		Array(unsigned int n): arraySize(n){
			std::cout << "[CONSTRUCTOR WITH ARG] has been called" << std::endl;
			array = new T[n];
		}
		Array( Array const & src ){
			std::cout << "[COPY CONSTRUCTOR WITH ARG] has been called" << std::endl;
			*this = src;
		}
		~Array(){
			std::cout << "[DESTRUCTOR] has been called" << std::endl;
			delete[] array;
		}

		Array &		operator=( Array const & rhs ){
			std::cout << "[ASSIGNMENT OPERATOR] has been called" << std::endl;
			if ( this != &rhs ){
				arraySize = rhs.arraySize;
				array = new T[rhs.arraySize];
			}
			return *this;
		}

		void	print_array()
		{
			std::cout << "The address of array is: " << array << std::endl;
			for (unsigned int i = 0; i < arraySize; i++)
				std::cout << array[i] << std::endl;
		}

		unsigned int size(void){
			return arraySize;
		}

	private:

		T*				array;
		unsigned int	arraySize;

};

#endif /* *********************************************************** ARRAY_H */