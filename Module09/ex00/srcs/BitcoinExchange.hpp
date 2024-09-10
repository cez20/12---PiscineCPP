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

		void			parseBitcoinExchangeRate(std::ifstream & btc_database);
		void			parseBitcoinValue(std::ifstream & bitcoinValueHistory);
		void			printBitcoinRates();

	private:
		std::map<std::string, double> 		_exchangeRates;
		// std::string 						_date_to_find;
		// double							_nbr_of_bitcoins;
		
};

std::string::iterator	findFirstNonWhitespace(std::string & s);
std::string::iterator	findFirstTrailingWhitespace(std::string & s);
std::string				trimLeadingWhitespace(std::string & s);
std::string				trimTrailingWhitespace(std::string & s);
std::string				removeAllWhitespace(std::string & s);
bool					isDateFormatValid(std::string & s);
bool					isDateOnlyDigits(std::string s);
bool					isMonthDayValid(std::string s);
bool					isRateValidFloat(std::string& s);
bool					isFloatPositive(std::string& s);
float 					stringToFloat(const std::string& s);

#endif /* ************************************************* BITCOINEXCHANGE_H */

