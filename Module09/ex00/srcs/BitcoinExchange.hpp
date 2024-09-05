#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream> 
# include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		// BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange &		operator=( BitcoinExchange const & rhs );

		void			mapBitcoinDatabase(std::ifstream & btc_database);
		void			findBitcoinData(std::ifstream & second_database);
		// void			printExchange();

		void			printMap();

	private:
		std::map<std::string, double> 		bitcoin_map;
		std::string 						date_to_find;
		double								nbr_of_bitcoins;
		
};

std::string::iterator	find_first_letter(std::string & s);
std::string::iterator	find_first_space(std::string & s);
std::string				trim_left_spaces(std::string & s);
std::string				trim_right_spaces(std::string & s);

#endif /* ************************************************* BITCOINEXCHANGE_H */

