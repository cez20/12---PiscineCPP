#ifndef FORMSLIST_HPP
# define FORMSLIST_HPP

# include <iostream>
# include <string>

class FormsList
{

	public:

		FormsList();
		FormsList( FormsList const & src );
		~FormsList();

		FormsList &		operator=( FormsList const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, FormsList const & i );

#endif /* ******************************************************* FORMSLIST_H */