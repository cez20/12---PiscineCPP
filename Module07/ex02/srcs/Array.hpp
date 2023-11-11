#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template < typename T >
class Array
{

	public:

		Array<T>(): array(NULL), arraySize(0){
			std::cout << "[DEFAULT CONSTRUCTOR] has been called" << std::endl;
		}
		Array<T>(unsigned int n): arraySize(n){
			std::cout << "[CONSTRUCTOR WITH ARG] has been called" << std::endl;
			array = new T[n];
		}
		Array<T>( Array <T> const & src ){
			*this = src;
		}
		~Array<T>(){
			std::cout << "[DESTRUCTOR] has been called" << std::endl;
			delete[] array;
		}

		Array<T> &		operator=( Array<T> const & rhs ){
			if ( this != &rhs ){
				arraySize = rhs.arraySize;
				array = new T[rhs.arraySize];
			}
			return *this;
		}

		void	modify_array_value(unsigned int index, T value)
		{
			if (index < arraySize)
				array[index] = value;
			else
				std::cout << "Invalid index" << std::endl;
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