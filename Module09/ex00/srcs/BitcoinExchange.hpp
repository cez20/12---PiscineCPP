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
		void			findMatchingDate(std::string s, std::string value);
		void			printBitcoinRates();

	private:
		std::map<std::string, double> 		_exchangeRates;
};

std::string::iterator	findFirstNonWhitespace(std::string & s);
std::string::iterator	findFirstTrailingWhitespace(std::string & s);
std::string				trimLeadingWhitespace(std::string & s);
std::string				trimTrailingWhitespace(std::string & s);
std::string				removeAllWhitespace(std::string & s);
bool					isDateFormatValid(std::string & s);
bool					isDateOnlyDigits(std::string s);
bool					isMonthDayValid(std::string s);
bool					isValidFloatFormat(std::string& s);
bool					isFloatPositive(std::string& s);
bool					isFloatWithinRange(std::string& s, int min, int max);
float 					stringToFloat(const std::string& s);

#endif /* ************************************************* BITCOINEXCHANGE_H */

