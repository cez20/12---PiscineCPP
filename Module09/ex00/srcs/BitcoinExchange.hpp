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
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange &		operator=( BitcoinExchange const & rhs );

		void			parseBitcoinDatabase(std::ifstream & btc_database);
		void			findBitcoinData(std::ifstream & second_database);
		void			printMap();

	private:
		std::map<std::string, double> 		_bitcoin_map;
		// std::string 						_date_to_find;
		// double							_nbr_of_bitcoins;
		
};

std::string::iterator	findFirstLetter(std::string & s);
std::string::iterator	findFirstSpace(std::string & s);
std::string				trimLeftSpaces(std::string & s);
std::string				trimRightSpaces(std::string & s);
std::string				removeAllSpaces(std::string & s);

#endif /* ************************************************* BITCOINEXCHANGE_H */

