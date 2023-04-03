#ifndef SAMPLE_HPP
# define SAMPLE_HPP

#include <string>

class Sample{

	private:


	public:
		Sample();
		~Sample();
		void	bar(char c);
		void	bar(int c);
		void	bar(std::string c);
};

#endif