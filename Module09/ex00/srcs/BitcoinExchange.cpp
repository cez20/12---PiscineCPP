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

            if(inputDate == "" || exchangeRate == "") {
                std::cout << "ERROR! Either inputDate or exchangeRate is missing!" << std::endl;
                exit(1); //TODO: Remove this exit which is not good practice 
            }

            if(!isDateFormatValid(inputDate) || !isDateOnlyDigits(inputDate) || !isMonthDayValid(inputDate)){
                std::cerr << "ERROR! Reference database has error" << std::endl;
                exit(1); // TODO:: Est-ce que je peux faire ca
            }

            if (!isRateValidFloat(exchangeRate) || !isFloatPositive(exchangeRate)){
                std::cerr << "ERROR! Exchange Rate has an error!" << std::endl;
                exit(1); // TODO:: Est-ce que je peux faire ca
            }

			_exchangeRates.insert(std::make_pair(inputDate,std::stod(exchangeRate))); //TODO: validate std::stod can be used
        } else {
            std::cerr << "Delimiter(comma) not found in the line: " << line << std::endl;
            exit(1);
        }
    }
}

void            BitcoinExchange::parseBitcoinValue(std::ifstream & bitcoinValueHistory) {
    std::string line;
    
    std::getline(bitcoinValueHistory, line); // Skip first line 
    while(std::getline(bitcoinValueHistory, line)) {
        std::stringstream ss(line);
        std::string targetDate, bitcoinValue;

        if (std::getline(ss, targetDate, '|')) {
            std::getline(ss, bitcoinValue);

            removeAllWhitespace(targetDate);
            removeAllWhitespace(bitcoinValue);

            // Error validation Validate
            if (targetDate == "" || bitcoinValue == "")
                std::cerr << "ERROR! Target date or bitcoin value is missing" << std::endl;
            else if (!isDateFormatValid(targetDate))
                std::cerr << "ERROR! Date format does not respect YYYY-MM-DD!" << std::endl;
            else {
                std::map<std::string, double>::iterator it = _exchangeRates.find(targetDate);
                if(it != _exchangeRates.end()) {
                    std::cout << it->first << " => " << bitcoinValue << " = "
                    << (std::stod(bitcoinValue) * it->second) << std::endl;
                } else {
                    std::cout << "Cannot find date! Must find closest date!" << std::endl;
                }
            } 
        } else {
            std::cerr << "ERROR! Delimiter | is missing or improperly formatted line" << std::endl;
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

bool isRateValidFloat(std::string& s) {
    bool decimalPointSeen = false;
    bool negativeSignSeen = false;

    // if (!std::isdigit(s[0]) || s[0] != '-')
    //     return false;

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (std::isdigit(c)) {
            continue;
        }

        if (c == '.') {
            if (decimalPointSeen)
                return false; 
            decimalPointSeen = true;
        } else if(c == '-'){
            if(negativeSignSeen)
                return false;
            negativeSignSeen = true;
        } else {
            return false;
        }
    }
    return true;
}

bool isFloatPositive(std::string& s){

    float rate = stringToFloat(s);

    if (rate < 0)
        return false;
    return true;
}

float stringToFloat(const std::string& s) {
    std::stringstream ss(s);
    float result;

    ss >> result;

    return result;
} 