#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if ( this != &rhs ) // TODO: Once class is finished added element inside condition. 
	{
		this->_exchangeRates = rhs._exchangeRates;
        //this->_exchangeRates = rhs.getBitcoinMap(); //Maybe this is it
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void			BitcoinExchange::parseBitcoinExchangeRate(std::ifstream & bitcoinRatesHistory) {
	std::string line;

	std::getline(bitcoinRatesHistory, line);
	while (std::getline(bitcoinRatesHistory, line)) { 
        std::stringstream ss(line);
        std::string inputDate, exchangeRate;

        if (std::getline(ss, inputDate, ',')) {
            std::getline(ss, exchangeRate);

            removeAllWhitespace(inputDate);
            removeAllWhitespace(exchangeRate);

            if(!isDateFormatValid(inputDate) || !isDateOnlyDigits(inputDate) || !isMonthDayValid(inputDate)){
                std::cerr << "ERROR! Reference database has error" << std::endl;
                exit(1); // TODO:: Est-ce que je peux faire ca
            }

			_exchangeRates.insert(std::make_pair(inputDate,std::stod(exchangeRate))); //TODO: validate std::stod can be used
        } else {
            std::cerr << "Delimiter(comma) not found in the line: " << line << std::endl;
        }
    }
}

void            BitcoinExchange::parseBitcoinValue(std::ifstream & bitcoinValueHistory) {
    std::string line;
    
    while(std::getline(bitcoinValueHistory, line)) {
        size_t delimiter_pos = line.find('|');

        if (delimiter_pos != std::string::npos){
            std::string target_date = line.substr(0, delimiter_pos);
            std::string nbr_of_bitcoins = line.substr(delimiter_pos + 1);

            trimTrailingWhitespace(target_date);
            trimLeadingWhitespace(nbr_of_bitcoins);

            // Check if the date exists in the map
            std::map<std::string, double>::iterator it = _exchangeRates.find(target_date);
            if (it != _exchangeRates.end()) {
                std::cout << it->first << " => " << nbr_of_bitcoins << " = "
                        << (std::stod(nbr_of_bitcoins) * it->second) << std::endl;
            } else {
                std::cerr << "ERROR! Cannot find the date in file or ERROR" << std::endl;
            }
        } else {
            std::cerr << "ERROR! Delimiter missing or improperly formatted line" << std::endl;
        }
    }
}


void	BitcoinExchange::printBitcoinRates(){
	std::map<std::string, double>::iterator it;

	for(it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it){
		std::cout << std::fixed << std::setprecision(2) << it->first << " | " << it->second << std::endl;
	}
}

/*
** --------------------------------- OTHER ---------------------------------
*/

std::string::iterator findFirstNonWhitespace(std::string & s){
    std::string::iterator it;

    for(it = s.begin(); it != s.end(); ++it){
        if (!std::isspace(static_cast<unsigned char>(*it)))
            return(it);
    }
    return s.end();
}

std::string::iterator findFirstTrailingWhitespace(std::string & s){
    std::string::iterator it;

    for(it = s.begin(); it != s.end(); ++it){
        if (std::isspace(static_cast<unsigned char>(*it)))
            return(it);
    }
    return s.end();
}

std::string     trimLeadingWhitespace(std::string & s){
    s.erase(s.begin(), findFirstNonWhitespace(s));
    return (s);
}

std::string     trimTrailingWhitespace(std::string & s){
    s.erase(findFirstTrailingWhitespace(s), s.end());
    return(s);
}

std::string     removeAllWhitespace(std::string & s){
    trimLeadingWhitespace(s);
    trimTrailingWhitespace(s);

    return (s);
}

bool            isDateFormatValid(std::string & s){
    if (s[4] != '-' || s[7] != '-')
        return false;
    return true;
}


bool            isDateOnlyDigits(std::string s){
    std::string str1 = s;

    str1.erase(4, 1);
    str1.erase(6, 1);
    
    for(std::size_t i = 0; i < str1.size(); ++i){
        if(!isdigit(static_cast<unsigned char>(str1[i]))){
            return false;
        }    
    }
    return true;
}

bool            isMonthDayValid(std::string s){

    std::string     year, month, day;
    unsigned int    new_year, new_month, new_day;

    year = s.substr(0, 4);
    month = s.substr(5, 2);
    day = s.substr(8, 2);

    new_year = atoi(year.c_str()); //TODO: Validate if atoi is the best function. Maybe std::stoi 
    new_month = atoi(month.c_str());
    new_day = atoi(day.c_str());

    if (new_month < 1 || new_month > 12)
        return false;
    if (new_day < 1 || new_day > 31)
        return false;
    if ((new_month == 4 || new_month == 6 || new_month == 9 || new_month == 11) && new_day > 30)
        return false;
    if (new_month == 2){
        if ((new_year % 4 == 0 && new_year % 100 != 0) || (new_year % 400 == 0)){
            if (new_day > 29)
                return false;
        } else {
            if (new_day > 28)
                return false;
        }
    }

    return true;
}
