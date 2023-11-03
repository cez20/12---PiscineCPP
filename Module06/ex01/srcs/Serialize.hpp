#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>
# include <string>

typedef struct {
	char letter;
	int number;
	std::string name;
	bool isData;
} Data;

class Serialize
{
	public:

		Serialize();
		Serialize( Serialize const & src );
		~Serialize();

		Serialize &		operator=( Serialize const & rhs );

		uintptr_t	serialize(Data *ptr);
		Data		*deserialize(uintptr_t raw);

	private:

};

// std::ostream &			operator<<( std::ostream & o, Serialize const & i );

#endif /* ******************************************************* SERIALIZE_H */